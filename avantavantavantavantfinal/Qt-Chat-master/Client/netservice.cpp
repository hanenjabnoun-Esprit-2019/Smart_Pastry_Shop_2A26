#include "netservice.h"

NetService::NetService(QObject *parent)
    : QObject(parent),
    menu(new AuthMenu()),
    chat(new chatwidget()),
    socket(new QTcpSocket(this)),
    ctimer(new QTimer(this))
{
    menu->show();
    chat->setVisible(true);

    connectSocketSignals();

    connect(menu, SIGNAL(signIn(QString, QString)),
            this, SLOT(onSignIn(QString, QString)));

//    connect(ctimer, SIGNAL(timeout()),
//            this, SLOT(onConnectionTimeOut()));

    connect(chat, SIGNAL(messageSent(Message&)),
            this, SLOT(onMessageSent(Message&)));
}

NetService::~NetService()
{
    delete menu;
    delete chat;
}



void
NetService::connectSocketSignals()
{
    connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}



void
NetService::onSignIn(const QString &username, const QString &password)
{
    identifier.setUsername("sana");
    identifier.setPassword("sana");

    // Connect to server and write auth data on success
    // see onSocketConnected() slot
    socket->connectToHost(QHostAddress::LocalHost, 8001);

    // Create 10 seconds timer for waiting server response
    ctimer->start(10000);
}



void
NetService::onSocketConnected()
{
    ctimer->stop();
    identifier.setType(DataType::AuthRequest);
    write(socket, identifier);
}



void
NetService::onSocketDisconnected()
{
    socket->abort();
}



void
NetService::onConnectionTimeOut()
{
    socket->abort();
    menu->setStatus("Connection timeout.");
}



void
NetService::readAuthAnswer(QDataStream &readStream)
{
    AuthAnswer ans;
    readStream >> ans;

    if (!ans.isSigned())
    {
        menu->setStatus("Authentication error.");
        socket->abort();
        return;
    }

    menu->close();
    chat->show();
}



void
NetService::readUserList(QDataStream &readStream)
{
    UserList lst;
    readStream >> lst;
    chat->addParticipants(lst);
}



void
NetService::readNewConnection(QDataStream &readStream)
{
    UserData user;
    readStream >> user;
    chat->addParticipant(user);
}



void
NetService::readDisconnection(QDataStream &readStream)
{
    UserData user;
    readStream >> user;
    chat->removeParticipant(user.getUsername());
}



void
NetService::readMessage(QDataStream &readStream)
{
    Message msg;
    readStream >> msg;
    chat->addMessage(msg);
}



void
NetService::write(QTcpSocket *socket, const BaseData &data)
{
    QByteArray datagram;
    QDataStream writeStream(&datagram, QIODevice::WriteOnly);
    writeStream << qint16(0) << (qint8)data.type();
    writeStream << data;
    writeStream.device()->seek(0);
    writeStream << qint16(datagram.size() - sizeof(qint16)); // writing data size
    socket->write(datagram);
    socket->waitForBytesWritten();
}



void
NetService::onSocketReadyRead()
{
    auto socket = static_cast<QTcpSocket *>(sender());
    QDataStream readStream(socket);
    qint16 sizeRead;
    qint8 type;

    readStream >> sizeRead;
    if (socket->bytesAvailable() < sizeRead) return;
    readStream >> type;

    if (type == DataType::AuthResponse)
        readAuthAnswer(readStream);
    if (type == DataType::UserListResponse)
        readUserList(readStream);
    if (type == DataType::NewConnection)
        readNewConnection(readStream);
    if (type == DataType::Disconnection)
        readDisconnection(readStream);
    if (type == DataType::Msg)
        readMessage(readStream);
}



void
NetService::onMessageSent(Message &msg)
{
    msg.setSender(identifier.getUsername());
    write(socket, msg);
}

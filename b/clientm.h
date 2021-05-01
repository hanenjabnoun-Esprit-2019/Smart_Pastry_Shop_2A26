#ifndef CLIENTM_H
#define CLIENTM_H

#include <QObject>
#include <QWidget>
#include <QTcpSocket>
class QHostAddress;
class QJsonDocument;
class Clientm : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Clientm)
public:
    explicit Clientm(QObject *parent = nullptr);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void login(const QString &userName);
    void sendMessage(const QString &text);
    void disconnectFromHost();
private slots:
    void onReadyRead();
signals:
    void connected();
    void loggedIn();
    void loginError(const QString &reason);
    void disconnected();
    void messageReceived(const QString &sender, const QString &text);
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username);
    void userLeft(const QString &username);
private:
    QTcpSocket *m_clientSocket;
    bool m_loggedIn;
    void jsonReceived(const QJsonObject &doc);
};

#endif // CLIENTM_H

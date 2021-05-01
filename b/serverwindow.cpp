#include "serverwindow.h"
#include "ui_serverwindow.h"
#include "server.h"
#include <QMessageBox>
#include <QDialog>
#include<QTimer>
#include "chatwindow.h"
#include<QPainter>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>
#include<QSqlTableModel>
#include <QChartView>


ServerWindow::ServerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ServerWindow)
    , m_chatServer(new Server(this))
{
    ui->setupUi(this);
    connect(ui->startStopButton, &QPushButton::clicked, this, &ServerWindow::toggleStartServer);
    connect(m_chatServer, &Server::logMessage, this, &ServerWindow::logMessage);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::toggleStartServer()
{
    if (m_chatServer->isListening()) {
        m_chatServer->stopServer();
        ui->startStopButton->setText(tr("Start Server"));
        logMessage(QStringLiteral("Server Stopped"));
    } else {
        if (!m_chatServer->listen(QHostAddress::Any, 1967)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to start the server"));
            return;
        }
        logMessage(QStringLiteral("Server Started"));
        ui->startStopButton->setText(tr("Stop Server"));
    }
}

void ServerWindow::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + '\n');
}


void ServerWindow::on_pushButton_clicked()
{
    ChatWindow f;
    f.exec();
}

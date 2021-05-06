#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QAbstractSocket>
class Clientm;
class QStandardItemModel;
namespace Ui { class ChatWindow; }
class ChatWindow : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(ChatWindow)
public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
private:
    Ui::ChatWindow *ui;
    Clientm *m_chatClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;
private slots:
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString &userName);
    void loggedIn();
    void loginFailed(const QString &reason);
    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void userJoined(const QString &username);
    void userLeft(const QString &username);
    void error(QAbstractSocket::SocketError socketError);
    void on_connectButton_clicked();
};

#endif // CHATWINDOW_H
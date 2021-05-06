#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QDialog>
#include <QFileDialog>
#include <QImage>

#include "../Data/userlist.h"
#include "../Data/userdata.h"
#include "../Data/message.h"
#include "styledialog.h"

namespace Ui {
class chatwidget;
}

class chatwidget : public QDialog
{
    Q_OBJECT

public:
    explicit chatwidget(QWidget *parent = 0);
    ~chatwidget();

public:

    void addParticipant(const UserData &username);
    void removeParticipant(const QString &username);
    void addParticipants(const UserList &lst);
    void addMessage(const Message &msg);


private slots:

    void on_SendButton_clicked();
    void on_loadImageButton_clicked();

    void onStyleChanged(QFont &font, QColor &color);

signals:

    void messageSent(Message &msg);

private:
    Ui::chatwidget *ui;
    UserData style;
    QPixmap bufferedImage;
    StyleDialog dlg;
};

#endif // CHATWIDGET_H


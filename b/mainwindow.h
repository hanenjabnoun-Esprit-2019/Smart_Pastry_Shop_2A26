#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include<QTimer>
#include "employer.h"
#include "popup.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void myfunction1();

   /* void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void myfunction() ;*/
    void on_mdp_oublie_clicked();
    void on_valider_mdp_clicked();
    void on_mail_clicked();
    void on_retour_clicked();

    QString get_code();
    void set_code(QString);

    QString generer_code();
    void mailSent(QString );

    void on_pushButton_facebook_clicked();
    void on_pushButton_twitter_clicked();
private:
    Ui::MainWindow *ui;

    QMediaPlayer * music = new QMediaPlayer();
    QTimer * timer ;
    Employer E;
    QString code;
    QByteArray image;
    QString fileNameImage ;

    QString text;
    popup *popUp;

};
#endif // MAINWINDOW_H

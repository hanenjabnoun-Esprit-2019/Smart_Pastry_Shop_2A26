#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QtDebug>
#include<QMessageBox>
#include <QtMessageHandler>
#include "SmtpMime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->tab_commande->setModel(c.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bp_ajout_clicked()
{
        int    id=ui->lineEdit_id->text().toInt();
        QString prix=ui->lineEdit_pr->text();
        QString fourn=ui->lineEdit_fourn->text();
        QString  client=ui->lineEdit_cl->text();

    Commande C(id,prix,fourn,client);
    bool test=c.ajouter();
    QMessageBox msgBox;

    if (test)
        msgBox.setText("ajout avec succes");
                else
        msgBox.setText("echec de l'ajout");

       msgBox.exec();


}

void MainWindow::on_pushButton_clicked()
{
    int    id=ui->lineEdit_id->text().toInt();
    QString prix=ui->lineEdit_pr->text();
    QString fourn=ui->lineEdit_fourn->text();
    QString  client=ui->lineEdit_cl->text();

Commande C(id,prix,fourn,client);
bool test=c.ajouter();
QMessageBox msgBox;

if (test)
    msgBox.setText("ajout avec succes");
            else
    msgBox.setText("echec de l'ajout");

   msgBox.exec();


}

void MainWindow::on_supprimer_clicked()
{


    Commande c1; c1.setid(ui->lineEdit_s->text().toInt());
    bool test=c1.supprimer(c1.getid());
QMessageBox msgBox;

if (test)
    msgBox.setText("suppression avec succes");
            else
    msgBox.setText("echec de la suppression");

   msgBox.exec();

}

void MainWindow::on_sendBtn_clicked()
{
    // This is a first demo application of the SmtpClient for Qt project

        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("houssemjrad94@gmail.com");
        smtp.setPassword("03101919");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("houssemjrad94@gmail.com", " 2A26 PASTRYSHOP"));
        message.addRecipient(new EmailAddress("houssem.jrad@esprit.tn", "cher clients"));
        message.setSubject("SmtpClient for Qt - Demo");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText("Hi,\nThis is a simple email message.\n");

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();


}

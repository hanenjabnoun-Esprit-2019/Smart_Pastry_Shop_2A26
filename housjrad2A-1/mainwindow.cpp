#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hcommande.h"
#include "notifications.h"
#include "commandev.h"
#include <QPixmap>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintEngine>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrinterInfo>
#include <QtPrintSupport/QPrintPreviewWidget>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPageSetupDialog>
#include "smtp.h"
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView_3->setModel(ss.afficherv());

    QPixmap pix("C:/Users/User/Desktop/images/pat.jpg");
    QPixmap dix("C:/Users/User/Desktop/images/welcom.png");

 ui->label_1->setPixmap(pix);
 ui->label_2->setPixmap(pix);
 ui->label_6->setPixmap(pix);
 ui->label_8->setPixmap(dix);
 ui->label_9->setPixmap(pix);
 ui->label_29->setPixmap(pix);
 ui->label_30->setPixmap(pix);
 ui->label_31->setPixmap(pix);




 connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
 connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));

 connect(ui->sendBtn_3, SIGNAL(clicked()),this, SLOT(sendMail()));
 connect(ui->exitBtn_3, SIGNAL(clicked()),this, SLOT(close()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterc_clicked()
{

//recuperation d information

int id=ui->lineEdit_i->text().toInt();
QString quantite=ui->lineEdit_q->text();
QString fournisseur=ui->lineEdit_f->text();
QString client=ui->lineEdit_c->text();

//instancier les info

hcommande c(id,quantite,fournisseur,client);

bool test=c.ajouter(); ;  //recuperation de la retour de query.exe
if (test) //si test true
{
    Notifications N;
 N.notifications_ajoutercommande();
 // ui->tableView->setModel(Etmp.afficher());

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué click cancel to exit."),QMessageBox::Cancel);

 }
else
    QMessageBox::critical(nullptr,QObject::tr("error"),QObject::tr("non ajouté click cancel to exit "),QMessageBox::Cancel);

}




void MainWindow::on_Supp_clicked()
{

    hcommande c1; c1.setId(ui->lineEdit_s->text().toInt());
    bool test=c1.supprimer(c1.getId());
QMessageBox msgBox;

if (test)
   { Notifications N;
    N.notifications_supprimercommande();
    ui->tableView->setModel(Etmp.afficher());

    msgBox.setText("suppression avec succes");
        }    else
    msgBox.setText("echec de la suppression");

   msgBox.exec();

}

void MainWindow::on_trier_clicked()
{
    ui->tableView->setModel(Etmp.trier());

}

void MainWindow::on_search_clicked()
{

int id=ui->lineEdit_r->text().toInt();
ui->tableView_2->setModel(Etmp.chercher(id));


}

void MainWindow::on_update_clicked()
{
    //recuperation d information

    int id=ui->lineEdit_r->text().toInt();
    QString quantite=ui->lineEdit_u2->text();
    QString fournisseur=ui->lineEdit_u3->text();
    QString client=ui->lineEdit_u4->text();

    //instancier les info

    hcommande c(id,quantite,fournisseur,client);

    bool test=c.modifier(); ;  //recuperation de la retour de query.exe
    if (test) //si test true
    {
       // ui->tableView->setModel(Etmp.afficher());
        Notifications N;
     N.notifications_modifiercommande();

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué click cancel to exit."),QMessageBox::Cancel);

     }
    else
        QMessageBox::critical(nullptr,QObject::tr("error"),QObject::tr("non ajouté click cancel to exit "),QMessageBox::Cancel);

}

void MainWindow::on_export_2_clicked()
{
    QPdfWriter pdf("C:/Users/User/Desktop/exportqt/Pdfachat.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(2300,1200,"Liste Des commande d achat");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/User/Desktop/exportqt/Pdfachat.pdf"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"ID");
        painter.drawText(1300,3300,"quantite");
        painter.drawText(3300,3300,"fournisseur");
        painter.drawText(5300,3300,"client");


        QSqlQuery query;
        query.prepare("select * from comande");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(3300,i,query.value(2).toString());
            painter.drawText(5300,i,query.value(3).toString());
            painter.drawText(7000,i,query.value(4).toString());
            painter.drawText(8000,i,query.value(4).toString());
            i = i +500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/User/Desktop/exportqt/Pdfachat.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}



void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->paswd_2->text(), ui->server_2->text(), ui->port_2->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}



void MainWindow::on_ajouterc_2_clicked()
{
    //recuperation d information

    int id=ui->lineEdit->text().toInt();
    QString produit=ui->lineEdit_2->text();
    QString datep=ui->dateEdit->text();
    QString prix=ui->lineEdit_4->text();
    QString quantite=ui->lineEdit_5->text();

    //instancier les info

    commandev c(id,produit,datep,prix,quantite);

    bool test=c.ajouterv(); ;  //recuperation de la retour de query.exe
    if (test) //si test true
    {
        Notifications N;
     N.notifications_ajoutercommande();
     // ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué click cancel to exit."),QMessageBox::Cancel);

     }
    else
        QMessageBox::critical(nullptr,QObject::tr("error"),QObject::tr("non ajouté click cancel to exit "),QMessageBox::Cancel);

}

void MainWindow::on_Supp_2_clicked()
{
    commandev c1; c1.setId(ui->lineEdit_s_2->text().toInt());
    bool test=c1.supprimerv(c1.getId());
QMessageBox msgBox;

if (test)
   { Notifications N;
    N.notifications_supprimercommande();
    ui->tableView->setModel(ss.afficherv());

    msgBox.setText("suppression avec succes");
        }    else
    msgBox.setText("echec de la suppression");

   msgBox.exec();

}

void MainWindow::on_trier_2_clicked()
{
     ui->tableView_3->setModel(ss.trierv());
}



void MainWindow::on_pushButton_clicked()
{
    ui->tableView_3->setModel(ss.refreshv());

}


void MainWindow::on_search_2_clicked()
{
    int id=ui->lineEdit_r_2->text().toInt();
    ui->tableView_4->setModel(ss.chercherv(id));
}

void MainWindow::on_update_2_clicked()
{
    //recuperation d information

    int id=ui->lineEdit_u1_2->text().toInt();
    QString produit=ui->lineEdit_u1_3->text();
    QString datep=ui->dateEdit_2->text();
    QString prix=ui->lineEdit_u1_5->text();
    QString quantite=ui->lineEdit_u1_6->text();

    //instancier les info

    commandev c(id,produit,datep,prix,quantite);

    bool test=c.modifierv(); ;  //recuperation de la retour de query.exe
    if (test) //si test true
    {
       // ui->tableView->setModel(Etmp.afficher());
        Notifications N;
     N.notifications_modifiercommande();

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué click cancel to exit."),QMessageBox::Cancel);

     }
    else
        QMessageBox::critical(nullptr,QObject::tr("error"),QObject::tr("non ajouté click cancel to exit "),QMessageBox::Cancel);
}

void MainWindow::on_export_3_clicked()
{
    QPdfWriter pdf("C:/Users/User/Desktop/exportqt/Pdfvente.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(2300,1200,"Liste Des commande de vente");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/User/Desktop/exportqt/Pdfvente.pdf"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"ID");
        painter.drawText(1300,3300,"produit");
        painter.drawText(3300,3300,"date de commande");
        painter.drawText(5300,3300,"prix en dinars");
        painter.drawText(6300,3300,"quantite en kg");



        QSqlQuery query;
        query.prepare("select * from commandev");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(3300,i,query.value(2).toString());
            painter.drawText(5300,i,query.value(3).toString());
            painter.drawText(7000,i,query.value(4).toString());
            i = i +500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/User/Desktop/exportqt/Pdfvente.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}

void MainWindow::on_trier_3_clicked()
{
    ui->tableView_3->setModel(ss.triervp());

}


void MainWindow::on_trier_4_clicked()
{
    ui->tableView_3->setModel(ss.triervd());

}

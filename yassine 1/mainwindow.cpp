#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
#include "client.h"
#include <QString>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>

#include <QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <QChart>

#include <QStatusBar>
#include "hcommande.h"
#include "commandev.h"
#include "carte_fid.h"
#include "employer.h"
#include "deppartement.h"
#include "smtp.h"
#include<cstdlib>

#include <QPdfWriter>
#include <QPainter>

//#include <QtNetwork/QAbstractSocket>
//#include <QtNetwork/QSslSocket>

#include <QString>

#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QSqlTableModel>

//------------------

#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QTextEdit>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QPainter>
#include <QDesktopServices>
#include <QPdfWriter>
#include <QMessageBox>
#include <QUrl>
#include <QFileDialog>
#include <QPixmap>
#include <QTabWidget>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QApplication>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include <QSharedPointer>
#include <QPaintEvent>
#include <QPixmap>

#include <QProgressBar>
#include <QStatusBar>
 #include <QtNetwork>


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    //     Positions initiale des boutons


    ui->client->setGeometry(60,190,131,71);
    ui->commande->setGeometry(60,250,131,71);
    ui->employe->setGeometry(60,310,131,71);
    ui->fournisseur->setGeometry(60,370,131,71);
    ui->maintenance->setGeometry(60,430,131,71);


    ui->le_id->setValidator(new QIntValidator(0, 9999, this));
    ui->le_numero->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_id_dep->setValidator(new QIntValidator(0, 9999, this));
    ui->tab_employer->setModel(E.afficher());
    ui->tab_depp->setModel(D.afficher());

    //................ houssem ......................
    ui->tableView_5->setModel(Etmp.afficher());
    ui->tableView_7->setModel(ss.afficherv());

    QPixmap pix("C:/Users/User/Desktop/images/pat.jpg");
    QPixmap dix("C:/Users/User/Desktop/images/welcom.png");

 //ui->label_1->setPixmap(pix);
 ui->label_2->setPixmap(pix);
 ui->label_6->setPixmap(pix);
 ui->label_8->setPixmap(dix);
 ui->label_9->setPixmap(pix);
 ui->label_29->setPixmap(pix);
 ui->label_30->setPixmap(pix);
 ui->label_31->setPixmap(pix);




 connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMail()));
 connect(ui->exitBtn_2, SIGNAL(clicked()),this, SLOT(close()));

 connect(ui->sendBtn_4, SIGNAL(clicked()),this, SLOT(sendMail()));
 connect(ui->exitBtn_4, SIGNAL(clicked()),this, SLOT(close()));
//........................

    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/1.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }

    //************************************************** Yassine
    ui->comboBox_4->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_3->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_mail->setModel(tmpabonnee.afficher_mail());
    ui->comboBox_mail->setModel(tmpabonnee.afficher_mail());

    ui->comboBox_7->setModel(tmpabonnement.afficher());

    ui->tababonne->setModel(tmpabonnee.afficher());
    ui->tababonnement->setModel(tmpabonnement.afficher());

    ui->comboBox_ida->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_8->setModel(tmpabonnement.afficher());

    ui->comboBox_ida_2->setModel(tmpabonnee.afficher_combobox());



    //********************************************************

    PixTrueIcon=QPixmap(":/images/True_icon.png");
    PixFalseIcon=QPixmap(":/images/False_icon.png");


}

MainWindow::~MainWindow()
{
    delete ui;
}


//******************************* client *****************



void MainWindow::on_pb_ajouter_abonne_clicked()
{

    bool test;
    int cin= ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString mail= ui->lineEdit_mail->text();
    long tel= ui->lineEdit_tel->text().toLong();

    if(nom==""|| prenom==""|| cin==0||cin>99999999||nom.length()>10||tel==0||tel>99999999||tel<10000000)
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/3.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
        test=false;
    }else
    {
        CLIENT a(cin,nom,prenom,mail,tel);
        N.notification_ajoutAbonne();
        test=a.ajouter();}
    if(test)
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        refresh();
        QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnee"),
                                 QObject::tr("abonnee ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnee"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_radioButton_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    ui->tababonne->setModel( tmpabonnee.afficher_tri_cin());
}

void MainWindow::on_pb_supprimer_abonne_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    int res=ui->comboBox_3->currentText().toInt();

    QString str = " Vous voulez vraiment supprimer \n l'abonne :";
    int ret = QMessageBox::question(this, tr("Abonne"),str,QMessageBox::Ok|QMessageBox::Cancel);

    switch (ret) {
    case QMessageBox::Ok:
        if (tmpabonnee.supprimer(res)){
            N.notification_supprimerAbonne();
            refresh();
        }else
        {
            QMessageBox::critical(0, qApp->tr("Suppression"),
                                  qApp->tr("Abonne non trouvé "), QMessageBox::Cancel);
        }
        break;
    case QMessageBox::Cancel:

        break;
    default:
        // should never be reached
        break;
    }

}

void MainWindow::on_pb_modifier_abonne_clicked()
{

    int cin= ui->comboBox_4->currentText().toInt();
    QString nom=ui->lineEdit_modifier_nom->text();
    QString prenom=ui->lineEdit_modifier_prenom->text();
    QString mail= ui->lineEdit_modifier_mail->text();
    long tel= ui->lineEdit_modifier_tel->text().toLong();

    if(nom==""|| prenom==""|| cin==0||cin>99999999||nom.length()>10||tel==0||tel>99999999||tel<10000000)
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/3.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

    }else
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        bool test=tmpabonnee.modifier(cin,nom,prenom,mail,tel);
        N.notification_modifierAbonne();
        if (test)
        {   refresh();
            QMessageBox::information(nullptr, QObject::tr("Modifier un abonne"),
                                     QObject::tr("abonne modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un abonne"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}








void MainWindow::on_comboBox_4_activated()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    int cin= ui->comboBox_4->currentText().toInt();
    QString res = QString:: number(cin);

    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE CIN=:cin");
    query.bindValue(":cin", res);

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_modifier_nom->setText(query.value(1).toString());
            ui->lineEdit_modifier_prenom->setText(query.value(2).toString());
            ui->lineEdit_modifier_mail->setText(query.value(3).toString());
            ui->lineEdit_modifier_tel->setText(query.value(4).toString());

        }
    }

}





void MainWindow::on_pdf_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    QPdfWriter pdf("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/PdfClients.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Clients");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"CIN");
    painter.drawText(1800,3300,"NOM");
    painter.drawText(3800,3300,"PRENOM");
    painter.drawText(5800,3300,"EMAIL");
    painter.drawText(8000,3300,"TELEPHONE");

    QSqlQuery query;
    query.prepare("select * from CLIENT");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        painter.drawText(8000,i,query.value(4).toString());
        i = i +500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/PdfClients.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void MainWindow::on_rechercher_abonne_textChanged()
{

    if(ui->rechercher_abonne->text()!="")
    {
        QString b=ui->combo_rech_abonne->currentText();
        QString a=ui->rechercher_abonne->text();
        ui->tababonne->setModel(tmpabonnee.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
    }
    else
        ui->tababonne->setModel(tmpabonnee.afficher());
}





void MainWindow::on_radioButton_5_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    ui->tababonne->setModel( tmpabonnee.afficher_trinom());
}

void MainWindow::on_radioButton_7_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    ui->tababonne->setModel( tmpabonnee.afficher_triprenom());
}


void MainWindow::on_refresh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    refresh();
}

void MainWindow::refresh(){

    ui->comboBox_4->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_3->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_mail->setModel(tmpabonnee.afficher_mail());
    ui->comboBox_mail->setModel(tmpabonnee.afficher_mail());

    ui->comboBox_7->setModel(tmpabonnement.afficher());
    ui->tababonne->setModel(tmpabonnee.afficher());
    ui->tababonnement->setModel(tmpabonnement.afficher());
    ui->comboBox_ida->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_8->setModel(tmpabonnement.afficher());

    ui->comboBox_ida_2->setModel(tmpabonnee.afficher_combobox());
}




//********************************************************




//*************************** carte fidelite *****************


void MainWindow::on_pb_ajouter_abonnement_clicked()
{

    bool test;
    int id= ui->lineEdit_id_abonnement->text().toInt();
    QString type=ui ->lineEdit_type_abonnement->text();
    int pt=ui->lineEdit_pt->text().toInt();
    int id_client=ui->comboBox_ida->currentText().toInt();

    if(ui->lineEdit_id_abonnement->text().isEmpty()||ui ->lineEdit_type_abonnement->text().isEmpty())
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/3.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
        test=false;
    }else
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        carte_fid ab (id,type,pt,id_client);
        test=ab.ajouter();}
    if(test)
    {
        N.notification_ajoutAbonnement();
        refresh();
        QMessageBox::information(nullptr, QObject::tr("Ajouter un carte fidelite"),
                                 QObject::tr("carte fidelite ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un carte fidelite"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_radioButton_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    ui->tababonnement->setModel( tmpabonnement.afficher_tri_id_carte());
}

void MainWindow::on_pb_supprimer_abonnement_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    int res=ui->comboBox_8->currentText().toInt();

    QString str = " Vous voulez vraiment supprimer \n l' carte fidelite :";
    int ret = QMessageBox::question(this, tr("carte fidelite"),str,QMessageBox::Ok|QMessageBox::Cancel);

    switch (ret) {
    case QMessageBox::Ok:
        if (tmpabonnement.supprimer(res)){
            N.notification_supprimerAbonnement();
            refresh();

        }else
        {
            QMessageBox::critical(0, qApp->tr("Suppression"),
                                  qApp->tr("carte fidelite non trouvé "), QMessageBox::Cancel);
        }
        break;
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }
}

void MainWindow::on_pb_modifier_abonnement_clicked()
{

    int id= ui->comboBox_7->currentText().toInt();
    QString type= ui->lineEdit_typemodif->text();
    int pt= ui->lineEdit_pt_2->text().toInt();
    int id_client= ui->comboBox_ida_2->currentText().toInt();


    carte_fid ab(id,type,pt,id_client);

    bool test=ab.modifier();
    if (test)
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        refresh();
        N.notification_modifierAbonnement();
        QMessageBox::information(nullptr, QObject::tr("Modifier un carte fidelite"),
                                 QObject::tr("carte fidelite modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMediaPlayer * bulletsound = new QMediaPlayer();
               bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/3.mp3"));
              if (bulletsound->state() == QMediaPlayer::PlayingState){
                   bulletsound->setPosition(0);
               }
               else if (bulletsound->state() == QMediaPlayer::StoppedState){
                   bulletsound->play();
               }
        QMessageBox::critical(nullptr, QObject::tr("Modifier un carte fidelite"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




void MainWindow::on_comboBox_7_activated()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    int id= ui->comboBox_7->currentText().toInt();
    QString res = QString:: number(id);

    QSqlQuery query;
    query.prepare("SELECT * FROM carte_fid WHERE id=:id");
    query.bindValue(":id", res);
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_typemodif->setText(query.value(1).toString());
            ui->lineEdit_pt_2->setText(query.value(2).toString());

        }
    }
}



/*void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        N.mail_Abonnement();
}

void MainWindow::on_pb_ajouter_7_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    Smtp* smtp = new Smtp("atou26.ag@gmail.com","ibrahguota26","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("atou26.ag@gmail.com",ui->comboBox_mail->currentText(),ui->subject->text(),ui->msg->toPlainText());
}

bool MainWindow::testmail(QString mail){
    int test=0;
    for(int i = 0; i < mail.size(); i++) {
if(mail[i]=="@")
    test++;
    }
    for(int i = 0; i < mail.size(); i++) {
if((test==1)&&(mail[i]=="."))
        return true;
    }
return false;}
*/


void MainWindow::on_radioButton_6_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    ui->tababonne->setModel( tmpabonnement.afficher_tri_pt());
}

void MainWindow::on_radioButton_4_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    ui->tababonnement->setModel( tmpabonnement.afficher_fidele());
}

void MainWindow::on_rechercher_abonnement_textChanged()
{
    if(ui->rechercher_abonnement->text()!="")
    {        QString b=ui->combo_rech_abonne_2->currentText();
        QString a=ui->rechercher_abonnement->text();
        ui->tababonnement->setModel(tmpabonnement.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
    }else
        ui->tababonnement->setModel(tmpabonnement.afficher());
}

void MainWindow::on_refresh_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    refresh();
}

void MainWindow::on_pdf_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }
    QPdfWriter pdf("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/PdfCarteFidelite.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Cartes Fidelite");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID CARTE");
    painter.drawText(2800,3300,"TYPE CARTE");
    painter.drawText(5300,3300,"POINTS FIDELITE");
    painter.drawText(7800,3300,"ID CLIENT");


    QSqlQuery query;
    query.prepare("select * from carte_fid");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2800,i,query.value(1).toString());
        painter.drawText(5300,i,query.value(2).toString());
        painter.drawText(7800,i,query.value(3).toString());

        i = i +500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/PdfCarteFidelite.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}


//********************************************************




//********************** seif **********************************

void MainWindow::on_pb_ajouter_clicked()
{
    QMessageBox msgBox;

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    float salaire=ui->le_salaire->text().toFloat();
    int numero=ui->le_numero->text().toInt();
    int id_depp=ui->le_id_depp->text().toInt();
    Employer E(id,nom,prenom,salaire,numero,id_depp);
    bool test=E.ajouter();

    if(test)
    {   msgBox.setText("ajout avec succes.");
        ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec d'ajout");
                msgBox.exec();
}


void MainWindow::on_pb_supp_clicked()
{
    Employer E1;
    E1.setid(ui->le_id_supp->text().toInt());
    int id=ui->le_id_supp->text().toInt();
    bool test=E1.supprimer(E1.getid());

    QMessageBox msgBox;
    if(test)
    {   msgBox.setText("Suppression avec succes.");
         ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec de suppression");
                msgBox.exec();
}

void MainWindow::on_pb_update_clicked()
{
    Employer E1;
    E1.setid(ui->le_id->text().toInt());

    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    float salaire=ui->le_salaire_2->text().toInt();
    int numero=ui->le_numero_2->text().toInt();
    int id_depp=ui->le_id_depp_2->text().toInt();
    Employer  E(id,nom,prenom,salaire,numero,id_depp);
    bool test=E.modifier(id);

    QMessageBox msgBox;
    if(test)
    {   msgBox.setText("mise à jour avec succes.");
         ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec de mise à jour");
                msgBox.exec();
}


void MainWindow::on_pb_ajouter_depp_clicked()
{
    QMessageBox msgBox;

    int id_dep=ui->le_id_dep->text().toInt();
    QString specialite=ui->le_spec->text();
    QString gerant=ui->le_gerant->text();
    QString localisation=ui->le_local->text();
    Deppartement D(id_dep,specialite,gerant,localisation);
    bool test=D.ajouter();

    if(test)
    {   msgBox.setText("ajout avec succes.");
        ui->tab_depp->setModel(D.afficher());
    }

    else
                msgBox.setText("Echec d'ajout");
                msgBox.exec();
}

void MainWindow::on_pb_supp_depp_clicked()
{
    Deppartement D1;
    D1.setid(ui->le_id_dep_supp->text().toInt());
    int id_dep=ui->le_id_dep_supp->text().toInt();
    bool test=D1.supprimer(D1.getid());

    QMessageBox msgBox;
    if(test)
    {   msgBox.setText("Suppression avec succes.");
        ui->tab_depp->setModel(D.afficher());}

    else
                msgBox.setText("Echec de suppression");
                msgBox.exec();
}


void MainWindow::on_pb_chercher_clicked()
{
    ui->tab_employer->setModel(E.afficher());
    int id= ui->le_id_chercher->text().toInt();
    ui->tab_employer->setModel(E.recherche(id));
}

void MainWindow::on_update_depp_clicked()
{
    Deppartement D1;
    D1.setid(ui->le_id_dep->text().toInt());

        int id_dep=ui->le_id_dep_2->text().toInt();
        QString specialite=ui->le_spec_2->text();
        QString gerant=ui->le_gerant_2->text();
        QString localisation=ui->le_local_2->text();

        Deppartement D(id_dep,specialite,gerant,localisation);
    bool test=D.modifier(id_dep);

    QMessageBox msgBox;
    if(test)
    {   msgBox.setText("mise à jour avec succes.");
         ui->tab_depp->setModel(D.afficher());}

    else
                msgBox.setText("Echec de mise à jour");
                msgBox.exec();
}

void MainWindow::on_pb_chercher_depp_clicked()
{
    ui->tab_depp->setModel(D.afficher());
    int id= ui->le_id_chercher_depp->text().toInt();
    ui->tab_depp->setModel(D.recherche(id));
}

void MainWindow::on_trier_clicked()
{
     Employer E;
     E.trier();
     ui->tab_employer->setModel(E.trier());
     /*QMediaPlayer * bulletsound = new QMediaPlayer();
            bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
           if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
            }
            else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
            }*/


}


void MainWindow::on_reset_employer_clicked()
{
    ui->tab_employer->setModel(E.afficher());
}

void MainWindow::on_reset_depp_clicked()
{
    ui->tab_depp->setModel(D.afficher());
}


void MainWindow::on_pdf_3_clicked()
{
    QPdfWriter pdf("C:/Users/payou/Documents/employe_depp_pastryShop/PdfEmployer.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Employer");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/payou/Documents/employe_depp_pastryShop/PdfEmployer.pdf"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID");
    painter.drawText(1300,3300,"NOM");
    painter.drawText(3300,3300,"PRENOM");
    painter.drawText(5300,3300,"SALAIRE");
    painter.drawText(7000,3300,"TELEPHONE");
    painter.drawText(8000,3300,"ID DEP");

    QSqlQuery query;
    query.prepare("select * from employer");
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
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/payou/Documents/employe_depp_pastryShop/PdfEmployer.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}


//********************************************************



//********************** houssem **********************************

void MainWindow::on_ajouterc_3_clicked()
{

//recuperation d information

int id=ui->lineEdit_i_2->text().toInt();
QString quantite=ui->lineEdit_q_2->text();
QString fournisseur=ui->lineEdit_f_2->text();
QString client=ui->lineEdit_c_2->text();

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




void MainWindow::on_Supp_3_clicked()
{

    hcommande c1; c1.setId(ui->lineEdit_s_3->text().toInt());
    bool test=c1.supprimer(c1.getId());
QMessageBox msgBox;

if (test)
   { Notifications N;
    N.notifications_supprimercommande();
    ui->tableView_5->setModel(Etmp.afficher());

    msgBox.setText("suppression avec succes");
        }    else
    msgBox.setText("echec de la suppression");

   msgBox.exec();

}

void MainWindow::on_trier_6_clicked()
{
    ui->tableView_5->setModel(Etmp.trier());

}

void MainWindow::on_search_3_clicked()
{

int id=ui->lineEdit_r_3->text().toInt();
ui->tableView_6->setModel(Etmp.chercher(id));


}

void MainWindow::on_update_3_clicked()
{
    //recuperation d information

    int id=ui->lineEdit_u1_4->text().toInt();
    QString quantite=ui->lineEdit_u2_2->text();
    QString fournisseur=ui->lineEdit_u3_2->text();
    QString client=ui->lineEdit_u4_2->text();

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

void MainWindow::on_export_4_clicked()
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
    Smtp* smtp = new Smtp(ui->uname_3->text(), ui->paswd_3->text(), ui->server_3->text(), ui->port_3->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname_3->text(), ui->rcpt_3->text() , ui->subject_3->text(),ui->msg_3->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}



void MainWindow::on_ajouterc_4_clicked()
{
    //recuperation d information

    int id=ui->lineEdit_3->text().toInt();
    QString produit=ui->lineEdit_6->text();
    QString datep=ui->dateEdit_3->text();
    QString prix=ui->lineEdit_7->text();
    QString quantite=ui->lineEdit_8->text();

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

void MainWindow::on_Supp_4_clicked()
{
    commandev c1; c1.setId(ui->lineEdit_s_4->text().toInt());
    bool test=c1.supprimerv(c1.getId());
QMessageBox msgBox;

if (test)
   { Notifications N;
    N.notifications_supprimercommande();
    ui->tableView_7->setModel(ss.afficherv());

    msgBox.setText("suppression avec succes");
        }    else
    msgBox.setText("echec de la suppression");

   msgBox.exec();

}

void MainWindow::on_trier_7_clicked()
{
     ui->tableView_7->setModel(ss.trierv());
}



void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_7->setModel(ss.refreshv());

}


void MainWindow::on_search_4_clicked()
{
    int id=ui->lineEdit_r_4->text().toInt();
    ui->tableView_8->setModel(ss.chercherv(id));
}

void MainWindow::on_update_4_clicked()
{
    //recuperation d information

    int id=ui->lineEdit_u1_7->text().toInt();
    QString produit=ui->lineEdit_u1_8->text();
    QString datep=ui->dateEdit_4->text();
    QString prix=ui->lineEdit_u1_9->text();
    QString quantite=ui->lineEdit_u1_10->text();

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

void MainWindow::on_export_5_clicked()
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

void MainWindow::on_trier_8_clicked()
{
    ui->tableView_7->setModel(ss.triervp());

}


void MainWindow::on_trier_9_clicked()
{
    ui->tableView_7->setModel(ss.triervd());

}

//********************************************************

#include "admin.h"
#include "ui_mainwindow.h"

#include "QPrintDialog"
#include "client.h"
#include <QString>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include "maintenance.h"
#include "equipement.h"
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
#include "fournisseur.h"
#include "c_achat.h"
#include <QPdfWriter>
#include <QPainter>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>

#include <QString>


#include <QSsl>
#include <QSslCertificate>
#include <QSslCertificateExtension>
#include <QSslCipher>
#include <QSslConfiguration>
#include <QSslDiffieHellmanParameters>
#include <QSslEllipticCurve>
#include <QSslError>
#include <QSslKey>
#include <QSslPreSharedKeyAuthenticator>
#include <QSslSocket>


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





admin::admin(QWidget *parent)
   : QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);




    //     Positions initiale des boutons


    ui->client->setGeometry(60,190,131,71);
    ui->commande->setGeometry(60,250,131,71);
    ui->employe->setGeometry(60,310,131,71);
    ui->fournisseur->setGeometry(60,370,131,71);
    ui->maintenance->setGeometry(60,430,131,71);



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

 //............. moussa ...........

 ui->tableView_3_mou->setModel(mtemp.afficher()); //affichage table fournisseur
 ui->tableView_4_mou->setModel(etemp.afficher()); //affichage table devis


 ui->tableView_3_mou->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableView_3_mou->setSelectionMode(QAbstractItemView::SingleSelection);


 ui->tableView_4_mou->setSelectionBehavior(QAbstractItemView::SelectRows);
 ui->tableView_4_mou->setSelectionMode(QAbstractItemView::SingleSelection);

 //........................

 music->setMedia(QUrl("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/1.mp3"));


 timer=new QTimer(this) ;
 connect(timer , SIGNAL(timeout()),this,SLOT(myfunction())) ;
 timer->start(1000) ;
 qDebug()<<music->errorString();

  music->play() ;

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

    //************************* khalil *******************************

    ui->tableView_3_kh->setModel(ftemp.afficher()); //affichage table fournisseur
    ui->tableView_4_kh->setModel(ctemp.afficher()); //affichage table devis


    ui->tableView_3_kh->setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tableView_3_kh->setSelectionMode(QAbstractItemView::SingleSelection);


    ui->tableView_4_kh->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_4_kh->setSelectionMode(QAbstractItemView::SingleSelection);

    //********************************************************

    PixTrueIcon=QPixmap(":/images/True_icon.png");
    PixFalseIcon=QPixmap(":/images/False_icon.png");


}

admin::~admin()
{
    delete ui;
}

void admin::on_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void admin::on_commande_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void admin::on_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void admin::on_fournisseur_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
}

void admin::on_maintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
}




//******************************* client *****************



void admin::on_pb_ajouter_abonne_clicked()
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

void admin::on_radioButton_clicked()
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

void admin::on_pb_supprimer_abonne_clicked()
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

void admin::on_pb_modifier_abonne_clicked()
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








void admin::on_comboBox_4_activated()
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





void admin::on_pdf_clicked()
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

void admin::on_rechercher_abonne_textChanged()
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





void admin::on_radioButton_5_clicked()
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

void admin::on_radioButton_7_clicked()
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


void admin::on_refresh_clicked()
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

void admin::refresh(){

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


void admin::on_pb_ajouter_abonnement_clicked()
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

void admin::on_radioButton_3_clicked()
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

void admin::on_pb_supprimer_abonnement_clicked()
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

void admin::on_pb_modifier_abonnement_clicked()
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




void admin::on_comboBox_7_activated()
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



void admin::mailSent(QString status)
{
    if(status == "Message sent")
        N.mail_Abonnement();
}

void admin::on_pb_ajouter_7_clicked()
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

bool admin::testmail(QString mail){
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



void admin::on_radioButton_6_clicked()
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

void admin::on_radioButton_4_clicked()
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

void admin::on_rechercher_abonnement_textChanged()
{
    if(ui->rechercher_abonnement->text()!="")
    {        QString b=ui->combo_rech_abonne_2->currentText();
        QString a=ui->rechercher_abonnement->text();
        ui->tababonnement->setModel(tmpabonnement.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
    }else
        ui->tababonnement->setModel(tmpabonnement.afficher());
}

void admin::on_refresh_2_clicked()
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

void admin::on_pdf_2_clicked()
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

void admin::on_pb_ajouter_clicked()
{
    QMessageBox msgBox;

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    float salaire=ui->le_salaire->text().toFloat();
    int numero=ui->le_numero->text().toInt();
    int id_depp=ui->le_id_depp->text().toInt();
    QString service=ui->serviceemploye->currentText();
    QString mdp=ui->motdepasse->text();
    QString e_mail=ui->email->text();


    Employer E(id,nom,prenom,salaire,numero,id_depp,service,mdp,e_mail);
    bool test=E.ajouter();

    if(test)
    {   msgBox.setText("ajout avec succes.");
        ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec d'ajout");
                msgBox.exec();
}


void admin::on_pb_supp_clicked()
{





                int res=ui->le_id_supp->text().toInt();

                QString str = " Vous voulez vraiment supprimer \n l'employe :";
                int ret = QMessageBox::question(this, tr("Employe"),str,QMessageBox::Ok|QMessageBox::Cancel);

                switch (ret) {
                case QMessageBox::Ok:
                    if (E.supprimer(res)){

                    }else
                    {
                        QMessageBox::critical(0, qApp->tr("Suppression"),
                                              qApp->tr("Employe non trouvé "), QMessageBox::Cancel);
                    }
                    break;
                case QMessageBox::Cancel:

                    break;
                default:
                    // should never be reached
                    break;
                }
}

void admin::on_pb_update_clicked()
{


    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    float salaire=ui->le_salaire_2->text().toInt();
    long numero=ui->le_numero_2->text().toLong();
    int id_depp=ui->le_id_depp_2->text().toInt();
    QString service=ui->serviceemploye_2->currentText();
    QString mdp=ui->motdepasse_2->text();
    QString e_mail=ui->email_3->text();


    Employer  E(id,nom,prenom,salaire,numero,id_depp,service,mdp,e_mail);
    bool test=E.modifier(id);

    QMessageBox msgBox;
    if(test)
    {   msgBox.setText("mise à jour avec succes.");
         ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec de mise à jour");
                msgBox.exec();
}


void admin::on_pb_ajouter_depp_clicked()
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

void admin::on_pb_supp_depp_clicked()
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


void admin::on_pb_chercher_clicked()
{
    ui->tab_employer->setModel(E.afficher());
    int id= ui->le_id_chercher->text().toInt();
    ui->tab_employer->setModel(E.recherche(id));
}

void admin::on_update_depp_clicked()
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

void admin::on_pb_chercher_depp_clicked()
{
    ui->tab_depp->setModel(D.afficher());
    int id= ui->le_id_chercher_depp->text().toInt();
    ui->tab_depp->setModel(D.recherche(id));
}

void admin::on_trier_clicked()
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


void admin::on_reset_employer_clicked()
{
    ui->tab_employer->setModel(E.afficher());
}

void admin::on_reset_depp_clicked()
{
    ui->tab_depp->setModel(D.afficher());
}


void admin::on_pdf_3_clicked()
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

void admin::on_ajouterc_3_clicked()
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




void admin::on_Supp_3_clicked()
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

void admin::on_trier_6_clicked()
{
    ui->tableView_5->setModel(Etmp.trier());

}

void admin::on_search_3_clicked()
{

int id=ui->lineEdit_r_3->text().toInt();
ui->tableView_6->setModel(Etmp.chercher(id));


}

void admin::on_update_3_clicked()
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

void admin::on_export_4_clicked()
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



void admin::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_3->text(), ui->paswd_3->text(), ui->server_3->text(), ui->port_3->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname_3->text(), ui->rcpt_3->text() , ui->subject_3->text(),ui->msg_3->toPlainText());
}

/*void admin::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
*/


void admin::on_ajouterc_4_clicked()
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

void admin::on_Supp_4_clicked()
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

void admin::on_trier_7_clicked()
{
     ui->tableView_7->setModel(ss.trierv());
}



void admin::on_pushButton_2_clicked()
{
    ui->tableView_7->setModel(ss.refreshv());

}


void admin::on_search_4_clicked()
{
    int id=ui->lineEdit_r_4->text().toInt();
    ui->tableView_8->setModel(ss.chercherv(id));
}

void admin::on_update_4_clicked()
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

void admin::on_export_5_clicked()
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

void admin::on_trier_8_clicked()
{
    ui->tableView_7->setModel(ss.triervp());

}


void admin::on_trier_9_clicked()
{
    ui->tableView_7->setModel(ss.triervd());

}

//********************************************************


//************************* moussa *******************************

void admin::on_pushButton_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/crud.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    int ID=ui->lineEdit_mou->text().toInt();
    QString NOM=ui->lineEdit_5_mou->text();
    QString ETAT = ui->lineEdit_4_mou->text();

    equipement e(ID,NOM,ETAT);


    bool test=e.ajouter();
       qDebug() << "test :" << test;
    if (test)
    {
        ui->tableView_4_mou->setModel(etemp.afficher());
        QMessageBox::information(nullptr,QObject::tr("")
                                 ,QObject::tr("Ajout effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);

    }
else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                                 ,QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

}


void admin::on_pushButton_5_mou_clicked()
{
    int ID= ui->lineEdit_14_mou->text().toInt();
        QString DATE_M=ui->lineEdit_15_mou->text();
        int PRIX=ui->lineEdit_16_mou->text().toInt();
        int ID_EQP= ui->lineEdit_17_mou->text().toInt();
        int ID_EMPLOYE= ui->lineEdit_18_mou->text().toInt();

        if(ID==0)
        {
            QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

        }else
        {
            bool test=mtemp.modifier(ID,DATE_M,PRIX,ID_EQP,ID_EMPLOYE);

            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier maintenance"),
                                         QObject::tr("MAIntenence modifié.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }else
                QMessageBox::critical(nullptr, QObject::tr("Modifier un maintenance"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void admin::on_pushButton_4_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/crud.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QItemSelectionModel *select = ui->tableView_3_mou->selectionModel();

            int id =select->selectedRows(0).value(0).data().toInt();

           if(mtemp.supprimer(id))
            {
                ui->tableView_3_mou->setModel(mtemp.afficher());

             }
}

void admin::on_pushButton_6_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->tableView_3_mou->setModel(mtemp.afficher(  ));
   int ID= ui->lineEdit_10_mou->text().toInt();
   ui->tableView_3_mou->setModel(mtemp.recherche(ID));

}


void admin::on_pushButton_2_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/crud.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    int ID=ui->lineEdit_2_mou->text().toInt();
    QString DATE_M=ui->lineEdit_6_mou->text();
    int PRIX=ui->lineEdit_8_mou->text().toInt();
   int ID_EQP=ui->lineEdit_9_mou->text().toInt();
   int ID_EMPLOYE=ui->lineEdit_7_mou->text().toInt();

    maintenance m(ID,DATE_M,PRIX,ID_EQP,ID_EMPLOYE);



    bool test=m.ajouter();
       qDebug() << "test :" << test;
    if (test)
    {
        ui->tableView_3_mou->setModel(mtemp.afficher());
        QMessageBox::information(nullptr,QObject::tr("")
                                 ,QObject::tr("Ajout effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }
else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                                 ,QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void admin::on_pushButton_13_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->tableView_4_mou->setModel(etemp.afficher(  ));
   int ID= ui->lineEdit_12_mou->text().toInt();
   ui->tableView_4_mou->setModel(mtemp.recherche(ID));
}

void admin::on_pushButton_9_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/crud.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QItemSelectionModel *select = ui->tableView_4_mou->selectionModel();

            int ID =select->selectedRows(0).value(0).data().toInt();

           if(etemp.supprimer(ID))
            {
                ui->tableView_4_mou->setModel(etemp.afficher());

             }
}

/*void admin::on_pushButton_8_clicked()
{
    QString val=ui->tableView_4_mou->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from  EQUIPEMENT where NOM Like '%"+val+"%' or prenom Like'%"+val+"%' or date_naissance Like '%"+val+"%'  ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->ID->setText(qry.value(0).toString());
            ui->NOM->setText(qry.value(1).toString());
            ui->prenom_m->setText(qry.value(2).toString());
            ui->date_m->setDate(qry.value(3).toDate());
            ui->email_m->setText(qry.value(4).toString());
            ui->tel_m->setText(qry.value(5).toString());
            ui->comboBox_2->setEditText(qry.value(6).toString());
        }
    }
      ui->stackedWidget->setCurrentIndex(4);
     ui->tabWidget_3->setCurrentIndex(0);
    ui->modifier->show();
    }*/

void admin::on_pushButton_14_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    {
        ui->tableView_4_mou->setModel(etemp.afficher(  ));
       int ID= ui->lineEdit_13_mou->text().toInt();
       ui->tableView_4_mou->setModel(etemp.recherche(ID));

    }
}

/*void admin::on_pushButton_10_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()==QDialog::Rejected)

            return;
}*/


void admin::on_pushButton_15_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->tableView_3_mou->setModel(etemp.afficher(  ));
   int ID= ui->lineEdit_11_mou->text().toInt();
   ui->tableView_3_mou->setModel(mtemp.recherche(ID));
}





void admin::on_tableView_3_mou_clicked(const QModelIndex &index)
{
        ui->lineEdit_14_mou->setText( ui->tableView_3_mou->model()->data(ui->tableView_3_mou->model()->index(ui->tableView_3_mou->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_15_mou->setText( ui->tableView_3_mou->model()->data(ui->tableView_3_mou->model()->index(ui->tableView_3_mou->selectionModel()->currentIndex().row(),1)).toString() );
        ui->lineEdit_16_mou->setText( ui->tableView_3_mou->model()->data(ui->tableView_3_mou->model()->index(ui->tableView_3_mou->selectionModel()->currentIndex().row(),2)).toString() );
        ui->lineEdit_17_mou->setText( ui->tableView_3_mou->model()->data(ui->tableView_3_mou->model()->index(ui->tableView_3_mou->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_18_mou->setText( ui->tableView_3_mou->model()->data(ui->tableView_3_mou->model()->index(ui->tableView_3_mou->selectionModel()->currentIndex().row(),1)).toString() );
}

void admin::on_tableView_4_mou_clicked(const QModelIndex &index)
{
    ui->lineEdit_19_mou->setText( ui->tableView_4_mou->model()->data(ui->tableView_4_mou->model()->index(ui->tableView_4_mou->selectionModel()->currentIndex().row(),0)).toString() );
    ui->lineEdit_20_mou->setText( ui->tableView_4_mou->model()->data(ui->tableView_4_mou->model()->index(ui->tableView_4_mou->selectionModel()->currentIndex().row(),1)).toString() );
    ui->lineEdit_21_mou->setText( ui->tableView_4_mou->model()->data(ui->tableView_4_mou->model()->index(ui->tableView_4_mou->selectionModel()->currentIndex().row(),2)).toString() );

}

void admin::on_pushButton_7_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
 equipement e;
 e.trier_id();
}
void admin::on_pushButton_3_mou_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/ahmed/Documents/son projet/metier.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
maintenance m;
m.trier_id();
}
void admin::on_pushButton_10_mou_clicked()
{
    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tableView_4_mou->model()->rowCount();
                 const int columnCount = ui->tableView_4_mou->model()->columnCount();

                 out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des equipement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView_4_mou->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView_4_mou->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView_4_mou->isColumnHidden(column)) {
                             QString data = ui->tableView_4_mou->model()->data(ui->tableView_4_mou->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);


    }
void admin::on_pushButton_11_mou_clicked()
{
    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tableView_3_mou->model()->rowCount();
                 const int columnCount = ui->tableView_3_mou->model()->columnCount();

                 out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste de Maintenance </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView_3_mou->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView_3_mou->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView_3_mou->isColumnHidden(column)) {
                             QString data = ui->tableView_3_mou->model()->data(ui->tableView_3_mou->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);


    }
void admin::on_pushButton_16_mou_clicked()
{
    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tableView_4_mou->model()->rowCount();
                 const int columnCount = ui->tableView_4_mou->model()->columnCount();

                 out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des equipement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView_3_mou->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView_4_mou->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView_4_mou->isColumnHidden(column)) {
                             QString data = ui->tableView_4_mou->model()->data(ui->tableView_4_mou->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en TXT", QString(), "*.txt");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);


    }


void admin::on_pushButton_8_mou_clicked()
{
    int ID= ui->lineEdit_19_mou->text().toInt();
        QString NOM=ui->lineEdit_20_mou->text();
        QString ETAT=ui->lineEdit_21_mou->text();

        if(ID==0)
        {
            QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

        }else
        {
            bool test=etemp.modifier(ID,NOM,ETAT);

            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                                         QObject::tr("equipement modifié.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }else
                QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
        }
}



/*void admin::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT where ETAT=='1' ");
    float salaire=model->rowCount();
    model->setQuery("select * from EQUIPEMENT where ETAT=='0' ");
    float salairee=model->rowCount();
    float total=salaire+salairee;
    QString a=QString(" EQUIPEMENT=1 "+QString::number((salaire*100)/total,'f',2)+"%" );
    QString b=QString(" EQUIPEMENT=0  "+QString::number((salairee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,salaire);
    series->append(b,salairee);
    if (salaire!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( salairee!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(salaireee!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Statistiques: Nombre Des abonnements  "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}*/

/*void admin::on_refresh_clicked()
{
    refresh();
}

void admin::refresh(){
    ui->tableView_4_mou->setModel(etemp.afficher());
    ui->tableView_3_mou->setModel(mtemp.afficher());
    }


*/

//********************************************************


//*************************** khalil *****************************

void admin::on_pushButton_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    int ID=ui->lineEdit_kh->text().toInt();
    QString DATE_C=ui->lineEdit_5_kh->text();
     int PRIX=ui->lineEdit_4_kh->text().toInt();
      int ID_FOURNISSEUR=ui->lineEdit_22_kh->text().toInt();
       int ID_EMPLOYE=ui->lineEdit_23_kh->text().toInt();

    c_achat c(ID,DATE_C,PRIX,ID_FOURNISSEUR,ID_EMPLOYE);


    bool test=c.ajouter();
       qDebug() << "test :" << test;
    if (test)
    {
        ui->tableView_4_kh->setModel(ctemp.afficher());
        QMessageBox::information(nullptr,QObject::tr("")
                                 ,QObject::tr("Ajout effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }
else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                                 ,QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

}


void admin::on_pushButton_5_kh_clicked()
{
    int ID= ui->lineEdit_14_kh->text().toInt();
            QString NOM=ui->lineEdit_15_kh->text();
             QString PRENOM= ui->lineEdit_16_kh->text();
            int NUMERO= ui->lineEdit_17_kh->text().toInt();
            QString EMAIL= ui->lineEdit_18_kh->text();


            if(ID==0)
            {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                      QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

            }else
            {
                bool test=ftemp.modifier(ID,PRENOM,NOM,NUMERO,EMAIL);

                if (test)
                {
                    QMessageBox::information(nullptr, QObject::tr("Modifier une commande"),
                                             QObject::tr("commande modifié.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);

                }else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une commande"),
                                          QObject::tr("Erreur !.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
            }

}

void admin::on_pushButton_4_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QItemSelectionModel *select = ui->tableView_3_kh->selectionModel();

            int id =select->selectedRows(0).value(0).data().toInt();

           if(ftemp.supprimer(id))
            {
                ui->tableView_3_kh->setModel(ftemp.afficher());

             }
}

void admin::on_pushButton_6_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->tableView_3_kh->setModel(ftemp.afficher(  ));
   int ID= ui->lineEdit_10_kh->text().toInt();
   ui->tableView_3_kh->setModel(ftemp.recherche(ID));

}


void admin::on_pushButton_2_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    int ID=ui->lineEdit_2_kh->text().toInt();
    QString PRENOM=ui->lineEdit_6_kh->text();
    QString NOM=ui->lineEdit_8_kh->text();
   int NUMERO=ui->lineEdit_9_kh->text().toInt();
   QString EMAIL=ui->lineEdit_7_kh->text();

    fournisseur f(ID,PRENOM,NOM,NUMERO,EMAIL);



    bool test=f.ajouter();
       qDebug() << "test :" << test;
    if (test)
    {
        ui->tableView_3_kh->setModel(ftemp.afficher());
        QMessageBox::information(nullptr,QObject::tr("")
                                 ,QObject::tr("Ajout effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }
else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                                 ,QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void admin::on_pushButton_13_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->tableView_4_kh->setModel(ctemp.afficher(  ));
   int ID= ui->lineEdit_12_kh->text().toInt();
   ui->tableView_4_kh->setModel(ftemp.recherche(ID));
}

void admin::on_pushButton_9_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QItemSelectionModel *select = ui->tableView_4_kh->selectionModel();

            int ID =select->selectedRows(0).value(0).data().toInt();

           if(ctemp.supprimer(ID))
            {
                ui->tableView_4_kh->setModel(ctemp.afficher());

             }
}

void admin::on_pushButton_8_kh_clicked()
{
    int ID= ui->lineEdit_19_kh->text().toInt();
            QString DATE_C=ui->lineEdit_20_kh->text();
            int PRIX= ui->lineEdit_21_kh->text().toInt();
            int ID_FOURNISSEUR= ui->lineEdit_24_kh->text().toInt();
            int ID_EMPLOYE= ui->lineEdit_25_kh->text().toInt();


            if(ID==0)
            {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                      QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

            }else
            {
                bool test=ctemp.modifier(ID,DATE_C,PRIX,ID_FOURNISSEUR,ID_EMPLOYE);

                if (test)
                {
                    QMessageBox::information(nullptr, QObject::tr("Modifier une commande"),
                                             QObject::tr("commande modifié.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);

                }else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une commande"),
                                          QObject::tr("Erreur !.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
            }


}

void admin::on_pushButton_14_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    {
        ui->tableView_4_kh->setModel(ctemp.afficher(  ));
       int ID= ui->lineEdit_13_kh->text().toInt();
       ui->tableView_4_kh->setModel(ctemp.recherche(ID));

    }
}

void admin::on_pushButton_10_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()==QDialog::Rejected)

            return;
}


void admin::on_pushButton_15_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->tableView_3_kh->setModel(ctemp.afficher(  ));
   int ID= ui->lineEdit_11_kh->text().toInt();
   ui->tableView_3_kh->setModel(ftemp.recherche(ID));
}





void admin::on_tableView_3_kh_clicked(const QModelIndex &index)
{
        ui->lineEdit_14_kh->setText( ui->tableView_3_kh->model()->data(ui->tableView_3_kh->model()->index(ui->tableView_3_kh->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_15_kh->setText( ui->tableView_3_kh->model()->data(ui->tableView_3_kh->model()->index(ui->tableView_3_kh->selectionModel()->currentIndex().row(),1)).toString() );
        ui->lineEdit_16_kh->setText( ui->tableView_3_kh->model()->data(ui->tableView_3_kh->model()->index(ui->tableView_3_kh->selectionModel()->currentIndex().row(),2)).toString() );
        ui->lineEdit_17_kh->setText( ui->tableView_3_kh->model()->data(ui->tableView_3_kh->model()->index(ui->tableView_3_kh->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_18_kh->setText( ui->tableView_3_kh->model()->data(ui->tableView_3_kh->model()->index(ui->tableView_3_kh->selectionModel()->currentIndex().row(),1)).toString() );
}

void admin::on_tableView_4_kh_clicked(const QModelIndex &index)
{
    ui->lineEdit_19_kh->setText( ui->tableView_4_kh->model()->data(ui->tableView_4_kh->model()->index(ui->tableView_4_kh->selectionModel()->currentIndex().row(),0)).toString() );
    ui->lineEdit_20_kh->setText( ui->tableView_4_kh->model()->data(ui->tableView_4_kh->model()->index(ui->tableView_4_kh->selectionModel()->currentIndex().row(),1)).toString() );
    ui->lineEdit_21_kh->setText( ui->tableView_4_kh->model()->data(ui->tableView_4_kh->model()->index(ui->tableView_4_kh->selectionModel()->currentIndex().row(),2)).toString() );
     ui->lineEdit_24_kh->setText( ui->tableView_4_kh->model()->data(ui->tableView_4_kh->model()->index(ui->tableView_4_kh->selectionModel()->currentIndex().row(),3)).toString() );
      ui->lineEdit_25_kh->setText( ui->tableView_4_kh->model()->data(ui->tableView_4_kh->model()->index(ui->tableView_4_kh->selectionModel()->currentIndex().row(),4)).toString() );

}



/*
void admin::on_pushButton_11_clicked()
{

}

void admin::on_pushButton_12_clicked()
{

}

void admin::on_pushButton_16_clicked()
{

}*/

void admin::on_pushButton_3_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
      fournisseur f;
      f.trier();
}
void admin::on_pushButton_7_kh_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/rii/ze.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    c_achat c;
    c.trier();

}

void admin::on_pdf_kh_clicked()
{
    QPdfWriter pdf("C:/Users/Khalil/Desktop/projet_1/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Fournisseurs");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID");
    painter.drawText(2300,3300,"PRENOM");
    painter.drawText(4300,3300,"NOM");
    painter.drawText(6300,3300,"NUMERO");
    painter.drawText(8000,3300,"MAIL");
    QSqlQuery query;
    query.prepare("select * from fournisseur");
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
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Khalil/Desktop/projet_1/Pdf.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}


//********************************************************

void admin::on_deconnexion_clicked()
{
    hide();
    MainWindow w;
    w.show();
    music->stop() ;
}


/*void admin::on_chatButton_clicked()
{
    chatwidget chat;
    chat.exec();
}*/

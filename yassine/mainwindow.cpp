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

#include "carte_fid.h"

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


    ui->billetterie->setGeometry(60,190,131,71);
    ui->stock->setGeometry(60,250,131,71);
    ui->abonnement->setGeometry(60,310,131,71);
    ui->materiel->setGeometry(60,370,131,71);
    ui->salaries->setGeometry(60,430,131,71);
    ui->cinehome->setGeometry(60,490,131,71);


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
        refresh();
        QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnee"),
                                 QObject::tr("abonnee ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnee"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_radioButton_clicked()
{
    ui->tababonne->setModel( tmpabonnee.afficher_tri_cin());
}

void MainWindow::on_pb_supprimer_abonne_clicked()
{
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
        QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

    }else
    {
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
    ui->tababonne->setModel( tmpabonnee.afficher_trinom());
}

void MainWindow::on_radioButton_7_clicked()
{
    ui->tababonne->setModel( tmpabonnee.afficher_triprenom());
}


void MainWindow::on_refresh_clicked()
{
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
        QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
        test=false;
    }else
    {
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
    ui->tababonnement->setModel( tmpabonnement.afficher_tri_id_carte());
}

void MainWindow::on_pb_supprimer_abonnement_clicked()
{
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
    {   refresh();
        N.notification_modifierAbonnement();
        QMessageBox::information(nullptr, QObject::tr("Modifier un carte fidelite"),
                                 QObject::tr("carte fidelite modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un carte fidelite"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_comboBox_7_activated()
{
    int id= ui->comboBox_7->currentText().toInt();
    QString res = QString:: number(id);

    QSqlQuery query;
    query.prepare("SELECT * FROM carte_fid WHERE ID=:id");
    query.bindValue(":id", res);
    if(query.exec())
    {
        while(query.next())
        {

            ui->lineEdit_pt_2->setText(query.value(4).toString());
            ui->comboBox_7->setModel(tmpabonnement.afficher());
        }
    }
}





void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        N.mail_Abonnement();
}

void MainWindow::on_pb_ajouter_7_clicked()
{
    Smtp* smtp = new Smtp("atou26.ag@gmail.com","OTOM","smtp.gmail.com",465);
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



void MainWindow::on_radioButton_6_clicked()
{
    ui->tababonne->setModel( tmpabonnement.afficher_tri_pt());
}

void MainWindow::on_radioButton_4_clicked()
{
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
    refresh();
}

void MainWindow::on_pdf_2_clicked()
{
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

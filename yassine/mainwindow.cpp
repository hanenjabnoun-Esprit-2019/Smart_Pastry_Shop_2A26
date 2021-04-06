#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QString>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>

#include "carte_fid.h"



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
//---------
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QTextEdit>
#include <QMessageBox>
#include<QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QPainter>
#include<QDesktopServices>
#include<QPdfWriter>
#include <QMessageBox>
#include<QUrl>
#include<QFileDialog>
#include <QPixmap>
#include <QTabWidget>
#include <QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QSharedPointer>
#include <QPaintEvent>



MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //     Positions initiale des boutons
    ui->billetterie->setGeometry(60,160,131,71);
    ui->stock->setGeometry(60,220,131,71);
    ui->abonnement->setGeometry(60,280,131,71);
    ui->materiel->setGeometry(60,340,131,71);
    ui->salaries->setGeometry(60,400,131,71);
    ui->cinehome->setGeometry(60,460,131,71);



    //************************************************** Yassine
    ui->comboBox_4->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_3->setModel(tmpabonnee.afficher_combobox());



    ui->tababonne->setModel(tmpabonnee.afficher());
    ui->comboBox_ida->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_ida_2->setModel(tmpabonnee.afficher_combobox());

    //********************************************************




}

MainWindow::~MainWindow()
{
    delete ui;
}


//******************************* ABONNEMENT ***************** Yassine



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
    painter.drawText(2300,3300,"NOM");
    painter.drawText(4300,3300,"PRENOM");
    painter.drawText(6300,3300,"EMAIL");
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


void MainWindow::on_refresh_clicked()
{
    refresh();
}

void MainWindow::refresh(){

    ui->comboBox_4->setModel(tmpabonnee.afficher_combobox());
    ui->comboBox_3->setModel(tmpabonnee.afficher_combobox());


    ui->tababonne->setModel(tmpabonnee.afficher());

    ui->comboBox_ida->setModel(tmpabonnee.afficher_combobox());

    ui->comboBox_ida_2->setModel(tmpabonnee.afficher_combobox());
}

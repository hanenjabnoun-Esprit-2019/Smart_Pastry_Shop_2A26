#include "seif.h"
#include "ui_seif.h"
#include "employer.h"
#include "deppartement.h"
#include "mainwindow.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QTabWidget>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

#include <QStatusBar>


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
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999, this));
    ui->le_numero->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_id_dep->setValidator(new QIntValidator(0, 9999, this));
    ui->tab_employer->setModel(E.afficher());
    ui->tab_depp->setModel(D.afficher());

   /* ui->employer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->employer->setSelectionMode(QAbstractItemView::SingleSelection);*/


        /*ui->depp_>setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->depp->setSelectionMode(QAbstractItemView::SingleSelection);*/
}

MainWindow::~MainWindow()
{
    delete ui;

}


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


void MainWindow::on_pdf_clicked()
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

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
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));

        ui->tab_client->setModel(C.afficher());
        ui->tab_client->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tab_client->setSelectionMode(QAbstractItemView::SingleSelection);

        ui->tab_carte->setModel(F.afficher_carte());
        ui->tab_carte->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tab_carte->setSelectionMode(QAbstractItemView::SingleSelection);

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
QString email=ui->le_email->text();
long numero=ui->le_numero->text().toLong();
    CLIENT C(id,nom,prenom,email,numero);
    bool test=C.ajouter();

    if(test)
    {   msgBox.setText("Ajout avec succes.");
        ui->tab_client->setModel(C.afficher());}
    else
                msgBox.setText("Echec d'ajout");
                msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    CLIENT C1;
       C1.setid(ui->le_id_supp->text().toInt());
       int id=ui->le_id_supp->text().toInt();
       QMessageBox msgBox;
       bool test=C1.supprimer(id);
       if(test)
       {   msgBox.setText("Suppression avec succes.");
        ui->tab_client->setModel(C.afficher());}

       else
                   msgBox.setText("Echec de supression");
                   msgBox.exec();
}




void MainWindow::on_pb_ajouter_carte_clicked()
{
    QMessageBox msgBox;

int id=ui->le_id_carte->text().toInt();
QString type=ui->le_type->text();
int pt=ui->le_pt->text().toInt();
int id_client=ui->le_id_client->text().toInt();
    carte_fid F(id,type,pt,id_client);
    bool test=F.ajouter_carte();

    if(test)
    {   msgBox.setText("Ajout avec succes.");
        ui->tab_carte->setModel(F.afficher_carte());}
    else
                msgBox.setText("Echec d'ajout");
                msgBox.exec();
}

void MainWindow::on_pb_supprimer_carte_clicked()
{
    carte_fid F1;
       F1.setid(ui->le_id_supp_carte->text().toInt());
       int id=ui->le_id_supp_carte->text().toInt();
       QMessageBox msgBox;
       bool test=F1.supprimer_carte(id);
       if(test)
       {   msgBox.setText("Suppression avec succes.");
        ui->tab_carte->setModel(F.afficher_carte());}

       else
                   msgBox.setText("Echec de supression");
                   msgBox.exec();
}

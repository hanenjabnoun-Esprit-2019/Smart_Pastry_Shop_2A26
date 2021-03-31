#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QString>
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_client->setModel(C.afficher());
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
int numero=ui->le_numero->text().toInt();
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

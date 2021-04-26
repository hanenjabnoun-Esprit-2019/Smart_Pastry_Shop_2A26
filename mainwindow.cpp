#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include <QString>
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_employer->setModel(E.afficher());
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
    {   msgBox.setText("Suppression avec succes.");
        ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec de s");
                msgBox.exec();
}


void MainWindow::on_pb_supp_clicked()
{
    Employer E1;
    E1.setid(ui->le_id_supp->text().toInt());
    int id=ui->le_id_supp->text().toInt();
    QMessageBox msgBox;
    bool test=E1.supprimer(id);
    if(test)
    {   msgBox.setText("Suppression avec succes.");
        ui->tab_employer->setModel(E.afficher());}

    else
                msgBox.setText("Echec de s");
                msgBox.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    commande c;
c.setidcommande(ui->lineEdit_idc->text());
c.setquantite(ui->lineEdit_qte->text());
c.setidclient(ui->lineEdit_idcl->text());
c.setdate(ui->lineEdit_datecm->text());
c.setdatel(ui->lineEdit_datecmf->text());


}

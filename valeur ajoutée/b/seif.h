#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employer.h"
#include "deppartement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_update_clicked();

    void on_pb_ajouter_depp_clicked();

    void on_pb_supp_depp_clicked();

    void on_pdf_clicked();


    void on_pb_chercher_clicked();

    void on_update_depp_clicked();

    void on_pb_chercher_depp_clicked();

    void on_trier_clicked();

    void on_reset_employer_clicked();

    void on_reset_depp_clicked();

private:
    Ui::MainWindow *ui;
    Employer E;
    Deppartement D;
};
#endif // MAINWINDOW_H

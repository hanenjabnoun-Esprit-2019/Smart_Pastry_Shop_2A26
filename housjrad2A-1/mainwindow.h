#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hcommande.h"
#include "commandev.h"
#include <QObject>
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
    void on_ajouterc_clicked();




    void on_Supp_clicked();

    void on_trier_clicked();

    void on_search_clicked();

    void on_update_clicked();

    void on_export_2_clicked();


    void sendMail();
    void mailSent(QString);

    void on_ajouterc_2_clicked();

    void on_Supp_2_clicked();

    void on_trier_2_clicked();

    void on_pushButton_clicked();

    void on_search_2_clicked();

    void on_update_2_clicked();

    void on_export_3_clicked();

    void on_trier_3_clicked();

    void on_trier_4_clicked();

private:
    Ui::MainWindow *ui;
    hcommande Etmp;
    commandev ss;
};
#endif // MAINWINDOW_H

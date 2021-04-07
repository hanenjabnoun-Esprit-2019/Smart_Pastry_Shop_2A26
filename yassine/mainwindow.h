#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "client.h"
#include "carte_fid.h"
#include "notification.h"
#include <QMediaPlayer>

#include <QDialog>

#include<QTimer>

#include<QPainter>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>
#include<QSqlTableModel>








QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    //************************* client
    void refresh();

    void on_pb_ajouter_abonne_clicked();

    void on_pb_supprimer_abonne_clicked();

    void on_pb_modifier_abonne_clicked();

    void on_comboBox_4_activated();

    void on_pdf_clicked();

    void on_refresh_clicked();

    void on_rechercher_abonne_textChanged();

    void on_radioButton_clicked();

    void on_radioButton_5_clicked();

    //*********************************



    //************************* carte fidelite

    void on_pb_ajouter_abonnement_clicked();

    void on_pb_supprimer_abonnement_clicked();

    void on_pb_modifier_abonnement_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_comboBox_7_activated();

    void on_rechercher_abonnement_textChanged();

    void on_pb_ajouter_7_clicked();

    void mailSent(QString );

    void on_radioButton_6_clicked();

    void on_refresh_2_clicked();

    void on_pdf_2_clicked();


    //*********************************




private:
    Ui::MainWindow *ui;
    CLIENT tmpabonnee;
    carte_fid tmpabonnement;
    Notification N;
};

#endif // MAINWINDOW_H

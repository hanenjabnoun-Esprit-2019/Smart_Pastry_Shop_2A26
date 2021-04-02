#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "client.h"
#include "carte_fid.h"

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
    void on_pb_ajouter_clicked();
    void on_pb_ajouter_carte_clicked();
    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();
    void on_pb_supprimer_carte_clicked();

private:
    Ui::MainWindow *ui;
    CLIENT C;
    carte_fid F;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"commande.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bp_ajout_clicked();

    void on_pushButton_clicked();

    void on_supprimer_clicked();

    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
    Commande c;

};

#endif // MAINWINDOW_H

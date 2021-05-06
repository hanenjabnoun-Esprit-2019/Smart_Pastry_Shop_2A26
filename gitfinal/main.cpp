#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include <QSqlDatabase>



#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
    QStringList languages;
    languages <<"frensh"<<"english";
     QString lang=QInputDialog::getItem(NULL,"select language","language",languages);
     if (lang=="english")
     {
            t.load(":/english.qm");
     }
     if (lang!="frensh")
     {
       a.installTranslator(&t);
     }

    Connection c;
    MainWindow w;



    bool test=c.createConnection();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();





}

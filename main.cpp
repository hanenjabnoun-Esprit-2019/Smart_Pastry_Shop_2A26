#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createConnection();
    MainWindow w;



    if (test)
    {
        w.show();
        qDebug() <<"connection reussite !!";
    }
        else
        qDebug() <<"erreur de connection";

    //w.show();
    return a.exec();
}



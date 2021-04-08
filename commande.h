#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class Commande
{
public:
    Commande();
    Commande(int,QString,QString,QString);
    int getid();
    QString getprix();
    QString getfourn();
    QString getclient();
    void setid (int);
    void setprix (QString);
    void setfourn (QString);
    void setclient (QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);





private:
int id ;
QString prix,fourn,client;

};

#endif // COMMANDE_H


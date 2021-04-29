#ifndef COMMANDEV_H
#define COMMANDEV_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class commandev
{ int id;
    QString quantite,prix,produit,datep;

public:
    //constructeur
    commandev(){};
    commandev(int,QString,QString,QString,QString);
    //getters

    int getId(){return id;}
    QString getPrix(){return prix;}
    QString getProduit(){return produit;}
    QString getDatep(){return datep;}
    QString getQuantite(){return quantite;}

    //Setters
    void setId(int id){this->id=id;}
    void setPrix(QString p){prix=p;}
    void setProduit(QString pr){produit=pr;}
    void setDatep (QString d){datep=d;}
    void setQuantite(QString q){quantite=q;}

    //fonctionalité de base lié a commande vente


    bool ajouterv();
    bool modifierv();
    QSqlQueryModel*afficherv();
    QSqlQueryModel*trierv();
    QSqlQueryModel*triervp();
    QSqlQueryModel*triervd();

    QSqlQueryModel*refreshv();

    QSqlQueryModel*chercherv(int);


    bool supprimerv(int);
};

#endif // COMMANDEV_H

#ifndef HCOMMANDE_H
#define HCOMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class hcommande
{
    int id ;
    QString quantite,fournisseur,client;

public:

    //constructeur
    hcommande(){}
    hcommande(int,QString,QString,QString);

    //getters

    int getId(){return id ;}
    QString getQuantite(){return quantite;}
    QString getFournisseur(){return fournisseur;}
    QString getClient(){return client;}
    //setters

    void setId(int id){this->id=id;}
    void setQuantite(QString q){quantite=q;}
    void setFournisseur(QString f){fournisseur=f;}
    void setClient (QString c){client=c;}
//fonctionalité de base relative a hcommande

bool ajouter();
bool modifier();
QSqlQueryModel*afficher();
QSqlQueryModel*trier();
QSqlQueryModel*chercher(int);


bool supprimer(int);
bool excel ();





};

#endif // HCOMMANDE_H

#include "commande.h"
#include <QString>
#include<QSqlQuery>
#include<QDebug>
#include<QtDebug>
#include <QObject>


Commande::Commande()
{
id=0;prix="";fourn="";client="";
}

Commande::Commande(int id ,QString prix,QString fourn,QString client)
{this->id=id;this->prix=prix;this->fourn=fourn;this->client=client;}
int Commande::getid(){return id;}
QString Commande::getprix(){return prix;}
QString Commande::getfourn(){return fourn;}
QString Commande::getclient(){return client;}
void Commande::setid (int id){this->id=id;}
void Commande::setprix (QString prix){this->prix=prix;}
void Commande::setfourn (QString fourn){this->fourn=fourn;}
void Commande::setclient (QString client){this->client=client;}
bool Commande::ajouter()
{bool test=false;

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO commande (id, prix, fournisseur,client) "
                  "VALUES (:id, :prix, :four,:cle)");
    query.bindValue(0, id);
    query.bindValue(1, prix);
    query.bindValue(2, fourn);
    query.bindValue(3, client);
    return query.exec();



}
bool Commande::supprimer(int id )
{

QSqlQuery query;
    query.prepare("DELETE FROM commande WHERE id=:id ");
    query.bindValue(0, id);

    return query.exec();



}

QSqlQueryModel* Commande::afficher()


{


QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT * FROM commande");
   model->setHeaderData(0, Qt::Horizontal,QObject::tr("identifiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("fournisseur"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("client"));




return model;

}


#include "hcommande.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>
hcommande::hcommande(int id,QString quantite,QString fournisseur,QString client)
{
this->id=id;
this->quantite=quantite;
this->fournisseur=fournisseur;
this->client=client;
}

bool hcommande::ajouter()

{
QSqlQuery query;
QString res=QString::number(id);
//preparation de la requette

query.prepare("insert into comande (id,quantite,fournisseur,client)""values(:id,:quantite,:fournisseur,:client)");
//creation des variables liée

query.bindValue(":id",res);
query.bindValue(":quantite",quantite);
query.bindValue(":fournisseur",fournisseur);
query.bindValue(":client",client);

return query.exec();//retourner la resultat d execution

}

QSqlQueryModel *hcommande::afficher()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from comande");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("fournisseur"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("client"));
 return model;



}

bool hcommande::supprimer(int id)

{

   /* QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("select from comande where ID=:id");
    query.bindValue(":id",res);
    query.exec();*/
    QSqlQuery query;
        query.prepare("DELETE FROM comande WHERE id=:id ");
        query.bindValue(0, id);

        return query.exec();





}

QSqlQueryModel *hcommande::trier()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from comande ORDER BY ID");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("fournisseur"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("client"));
 return model;



}

QSqlQueryModel *hcommande::chercher(int id)

{
//CRUD chercher

    QString rec=QString::number(id);

    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from comande WHERE ID='"+rec+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("fournisseur"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("client"));
 return model;



}
bool hcommande::modifier()

{
QSqlQuery query;
QString up=QString::number(id);
//preparation de la requette

query.prepare("update  comande set quantite=:quantite,fournisseur=:fournisseur,client=:client where ID=:id");
//creation des variables liée

query.bindValue(":id",up);
query.bindValue(":quantite",quantite);
query.bindValue(":fournisseur",fournisseur);
query.bindValue(":client",client);

return query.exec();//retourner la resultat d execution

}
bool hcommande::excel()

{

   /* QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("select from comande where ID=:id");
    query.bindValue(":id",res);
    query.exec();*/
    QSqlQuery query;
        query.prepare("SELECT * INTO OUTFILE 'c:/stats.csv'FROM comande");

        return query.exec();





}



#include "commandev.h"

commandev::commandev(int id ,QString produit,QString datep,QString prix,QString quantite)

{
this->id=id;
this->produit=produit;
this->datep=datep;
this->prix=prix;
this->quantite=quantite;


}
bool commandev::ajouterv()

{
QSqlQuery query;
QString res=QString::number(id);
//preparation de la requette

query.prepare("insert into commandev (id,produit,datep,prix,quantite)""values(:id,:produit,:datep,:prix,:quantite)");
//creation des variables liée

query.bindValue(":id",res);
query.bindValue(":produit",produit);
query.bindValue(":datep",datep);
query.bindValue(":prix",prix);
query.bindValue(":quantite",quantite);

return query.exec();//retourner la resultat d execution

}

QSqlQueryModel *commandev::afficherv()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from commandev");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom produit"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("date commande"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix en dt"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite en kg"));

 return model;



}

bool commandev::supprimerv(int id)

{

   /* QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("select from comande where ID=:id");
    query.bindValue(":id",res);
    query.exec();*/
    QSqlQuery query;
        query.prepare("DELETE FROM commandev WHERE id=:id ");
        query.bindValue(0, id);

        return query.exec();


}


QSqlQueryModel *commandev::trierv()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from commandev ORDER BY ID");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("date commande"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));

 return model;



}
QSqlQueryModel *commandev::refreshv()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from commandev ");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("date commande"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));

 return model;

}
QSqlQueryModel *commandev::chercherv(int id)

{
//CRUD chercher

    QString rec=QString::number(id);

    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from commandev WHERE ID='"+rec+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("datep"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));

 return model;



}
bool commandev::modifierv()

{
QSqlQuery query;
QString up=QString::number(id);
//preparation de la requette

query.prepare("update  commandev set produit=:produit,datep=:datep,prix=:prix,quantite=:quantite where ID=:id");
//creation des variables liée

query.bindValue(":id",up);
query.bindValue(":produit",produit);
query.bindValue(":datep",datep);
query.bindValue(":prix",prix);
query.bindValue(":quantite",quantite);

return query.exec();//retourner la resultat d execution

}

QSqlQueryModel *commandev::triervp()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from commandev ORDER BY produit");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("date commande"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));

 return model;



}
QSqlQueryModel *commandev::triervd()

{
//CRUD Affichage
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from commandev ORDER BY datep");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("date commande"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));

 return model;



}





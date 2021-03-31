#include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>

CLIENT::CLIENT()
{
id=0; nom=""; prenom=""; email=""; numero=0;
}

CLIENT::CLIENT(int id,QString nom,QString prenom,QString email,int numero)
{
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->email=email;
this->numero=numero;
}

int CLIENT::getid(){return id;}
QString CLIENT::getnom(){return nom;}
QString CLIENT::getprenom(){return prenom;}
QString CLIENT::getemail(){return email;}
int CLIENT::getnumero(){return numero;}
void CLIENT::setid(int id){this->id=id;}
void CLIENT::setnom(QString nom){this->nom=nom;}
void CLIENT::setprenom(QString prenom){this->prenom=prenom;}
void CLIENT::setemail(QString email){this->email=email;}
void CLIENT::setnumero(int numero){this->numero=numero;}


bool CLIENT::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString numero_string=QString::number(numero);


        query.prepare("INSERT INTO employer (id, nom, prenom,email,numero) "
                  "VALUES (:id, :nom, :prenom, :email, :numero)");
        query.bindValue(":id", id_string);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":email", email);
        query.bindValue(":numero", numero_string);

        return query.exec();
}


bool CLIENT::supprimer(int id)
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
QSqlQuery query;
query.prepare("Delete from CLIENT where id = :id ");
query.bindValue(":id", id);
return    query.exec();

}


QSqlQueryModel* CLIENT::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM employer");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero telephone"));

        return model;
}

bool CLIENT::modifier(int id,QString nom,QString prenom,QString email,int numero){
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString numero_string=QString::number(numero);

    query.prepare("update CLIENT set nom=:nom ,prenom=:prenom,email=:email,numero=:numero  where id = :id");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":numero", numero_string);

    return query.exec();
}



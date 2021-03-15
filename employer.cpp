#include "employer.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Employer::Employer()
{
id=0; nom=""; prenom=""; id_depp=0; numero=0; salaire=0;
}
Employer::Employer(int id,QString nom,QString prenom,float salaire,int numero,int id_depp)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->salaire=salaire;
    this->numero=numero;
    this->id_depp=id_depp;
}
int Employer::getid(){return id;}
QString Employer::getnom(){return nom;}
QString Employer::getprenom(){return prenom;}
float Employer::getsalaire(){return salaire;}
int Employer::getnumero(){return numero;};
int Employer::getid_depp(){return id_depp;}

void Employer::setid(int id){this->id=id;}
void Employer::setnom(QString nom){this->nom=nom;}
void Employer::setprenom(QString prenom){this->prenom=prenom;}
void Employer::setsalaire(float salaire){this->salaire=salaire;}
void Employer::setnumero(int numero){this->numero=numero;}
void Employer::setid_depp(int id_depp){this->id_depp=id_depp;}
bool Employer::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString salaire_string=QString::number(salaire);
    QString num_string=QString::number(numero);
    QString id_depp_string=QString::number(id_depp);

        query.prepare("INSERT INTO employer (id, nom, prenom,salaire,numero,id_depp) "
                  "VALUES (:id, :nom, :prenom, :salaire, :num, :id_depp)");
        query.bindValue(0, id_string);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, salaire_string);
        query.bindValue(4, num_string);
        query.bindValue(5, id_depp_string);
        return query.exec();
}
bool Employer::supprimer(int)
{
    QSqlQuery query;
    query.prepare("DELETE * from employer WHERE id=:id ");
    query.bindValue(0, id);
    return query.exec();
}
QSqlQueryModel* Employer::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM employer");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr(" identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("numéro"));
        model->setHeaderData(5, Qt::Horizontal,  QObject::tr("id département"));
        return model;
}

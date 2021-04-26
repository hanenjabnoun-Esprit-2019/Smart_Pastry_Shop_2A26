#include "deppartement.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Deppartement::Deppartement()
{
    id_dep=0; specialite=""; gerant=""; localisation="";
}

Deppartement::Deppartement(int id_dep,QString specialite,QString gerant,QString localisation)
{
    this->id_dep=id_dep;
    this->specialite=specialite;
    this->gerant=gerant;
    this->localisation=localisation;
}

int Deppartement::getid(){return id_dep;}
QString Deppartement::getspecialite(){return specialite;}
QString Deppartement::getgerant(){return gerant;}
QString Deppartement::getlocal(){return localisation;}

void Deppartement::setid(int id_dep){this->id_dep=id_dep;}
void Deppartement::setspecialite(QString specialite){this->specialite=specialite;}
void Deppartement::setgerant(QString gerant){this->gerant=gerant;}
void Deppartement::setlocal(QString localisation){this->localisation=localisation;}

bool Deppartement::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id_dep);

        query.prepare("INSERT INTO departement (id_depp,specialite,gerant,localisation) "
                  "VALUES (:id, :specialite, :gerant, :localisation)");
        query.bindValue(0, id_string);
        query.bindValue(1, specialite);
        query.bindValue(2, gerant);
        query.bindValue(3, localisation);
        return query.exec();
}

bool Deppartement::supprimer(int id_dep)
{
    QSqlQuery query;
    query.prepare("DELETE from departement WHERE id_depp=:id ");
    query.bindValue(0, id_dep);
    return query.exec();
}

QSqlQueryModel* Deppartement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM departement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr(" identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("spécialité"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom gérant"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("localitaion"));
        return model;
}



bool Deppartement::modifier(int id_dep)
{

    QSqlQuery query;
    QString id_string=QString::number(id_dep);

    query.prepare("update departement set specialite=:specialite, gerant=:gerant, localisation=:localisation where id_depp=:id");

    query.bindValue(":id", id_string);
    query.bindValue("specialite", specialite);
    query.bindValue(":gerant", gerant);
    query.bindValue(":localisation", localisation);
            return query.exec();

}

QSqlQueryModel *Deppartement::recherche(int id_dep)
{
    QString id_string=QString::number(id_dep);
    QString query=("SELECT * FROM departement WHERE ID_depp='"+id_string+"'");
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("spécialité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom gérant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("localitaion"));
      return model;
}



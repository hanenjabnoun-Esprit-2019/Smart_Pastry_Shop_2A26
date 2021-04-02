#include "carte_fid.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>

#include "client.h"

carte_fid::carte_fid()
{
id=0; type=""; pt=0; id_client=0;
}

carte_fid::carte_fid(int id, QString type, int pt, int id_client)
{
this->id=id;
this->type=type;
this->pt=pt;
this->id_client=id_client;

}

int carte_fid::getid(){return id;}
QString carte_fid::gettype(){return type;}
int carte_fid::getpt(){return pt;}
int carte_fid::getid_client(){return id_client;}

void carte_fid::setid(int id){this->id=id;}
void carte_fid::settype(QString type){this->type=type;}
void carte_fid::setpt(int pt){this->pt=pt;}
void carte_fid::setid_client(int id_client){this->id_client=id_client;}



bool carte_fid::ajouter_carte()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString pt_string=QString::number(pt);
    QString id_client_string=QString::number(id_client);


        query.prepare("INSERT INTO carte_fid (id, type, pt, id_client) "
                  "VALUES (:id, :type, :pt, :id_client)");
        query.bindValue(":id", id_string);
        query.bindValue(":type", type);
        query.bindValue(":pt", pt_string);
        query.bindValue(":id_client", id_client_string);

        return query.exec();
}


bool carte_fid::supprimer_carte(int id)
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from carte_fid");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
QSqlQuery query;
query.prepare("Delete from carte_fid where id = :id ");
query.bindValue(":id", id);
return    query.exec();

}


QSqlQueryModel* carte_fid::afficher_carte()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM carte_fid");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de carte"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points fidelites"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Identifiant du client"));


        return model;
}

bool carte_fid::modifier_carte(int, QString, int, int) {
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString pt_string=QString::number(pt);
    QString id_client_string=QString::number(id_client);

    query.prepare("update carte_fid set id=:id ,type=:type,pt=:pt,id_client=:id_client  where id = :id");
    query.bindValue(":id", id_string);
    query.bindValue(":type", type);
    query.bindValue(":pt", pt_string);
    query.bindValue(":id_client", id_client_string);


    return query.exec();
}

bool carte_fid::rech_carte(int id){
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString pt_string=QString::number(pt);
    QString id_client_string=QString::number(id_client);

    query.prepare("select * from carte_fid where id = :id");
    query.bindValue(":id", id_string);
    query.bindValue(":type", type);
    query.bindValue(":pt", pt_string);
    query.bindValue(":id_client", id_client_string);


    return query.exec();
}

QSqlQueryModel * carte_fid::affichercartechercher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from carte_fid where id= :id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de carte"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points fidelites"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Identifiant du client"));


    return model;
}

QSqlQueryModel * carte_fid::trier_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de carte"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points fidelites"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Identifiant du client"));


        return model;
}



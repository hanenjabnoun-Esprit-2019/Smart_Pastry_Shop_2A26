#include "carte_fid.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>


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





bool carte_fid:: ajouter()
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


    return    query.exec();
    }


QSqlQueryModel *carte_fid::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte_fid  ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de carte"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points fidelites"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Identifiant du client"));

    return model;
}


bool carte_fid::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString:: number(id);
    query.prepare("Delete from carte_fid where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}
bool carte_fid:: modifier()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString pt_string=QString::number(pt);


    query.prepare("update carte_fid set id=:id ,type=:type,pt=:pt,id_client=:id_client  where id = :id");
    query.bindValue(":id", id_string);
    query.bindValue(":type", type);
    query.bindValue(":pt", pt_string);


        return    query.exec();

}


QSqlQueryModel * carte_fid::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from carte_fid where ID =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
   }


QSqlQueryModel * carte_fid::afficher_tri_id_carte()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte_fid order by ID asc ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de carte"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points fidelites"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Identifiant du client"));


    return model;
}



QSqlQueryModel *carte_fid::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM carte_fid " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type de carte"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points fidelites"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Identifiant du client"));
    return model;
}

QSqlQueryModel * carte_fid::afficher_fidele()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT id_client,COUNT(id_client) FROM carte_fid GROUP BY  id_client ORDER BY COUNT(id_client) DESC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de carte fidelite"));
return model;
}



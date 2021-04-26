#include "c_achat.h"
#include <QDate>
#include <QString>
#include <QDebug>
c_achat::c_achat()
{
    this->ID=0;
    this->DATE_C="";
    this->PRIX=0;
     this->ID_FOURNISSEUR=0;
     this->ID_EMPLOYE=0;
}
c_achat::c_achat(int ID,QString DATE_C,int PRIX,int ID_FOURNISSEUR,int ID_EMPLOYE)
{
    this->ID=ID;
    this->DATE_C=DATE_C;
    this->PRIX=PRIX;
    this->ID_FOURNISSEUR=ID_FOURNISSEUR;
    this->ID_EMPLOYE=ID_EMPLOYE;

}
bool c_achat::ajouter() //works
{
QSqlQuery query;
query.prepare("INSERT INTO COMMANDE_ACHAT(ID,DATE_C,PRIX,ID_FOURNISSEUR,ID_EMPLOYE)"
              " VALUES(:ID,:DATE_C,:PRIX,:ID_FOURNISSEUR,:ID_EMPLOYE)");

query.bindValue(":ID",getID());
query.bindValue(":DATE_C",getDATE_C());
query.bindValue(":PRIX",getPRIX());
query.bindValue(":ID_FOURNISSEUR",getID_FOURNISSEUR());
query.bindValue(":ID_EMPLOYE",getID_EMPLOYE());
return query.exec();
}
QSqlQueryModel * c_achat::afficher() //Works
    {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from COMMANDE_ACHAT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_C")); //horizontal
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX")); //horizontal
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FOURNISSEUR")); //horizontal
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_EMPLOYE")); //horizontal
    return model;
    }

bool c_achat::supprimer(int ID) //works
{
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("DELETE FROM COMMANDE_ACHAT WHERE ID = :ID");
    query.bindValue(":ID",res);
    return query.exec();
    }

QSqlQueryModel *c_achat::recherche(int ID) //Works
{
    QString query1="SELECT * FROM COMMANDE_ACHAT WHERE ID=";
    QString idtxt= QString::number(ID);
    QString queryfull=query1 + idtxt;
  // qDebug() << "query  :" << queryfull;

    QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery(queryfull);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_C")); //horizontal
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX")); //horizontal
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FOURNISSEUR")); //horizontal
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_EMPLOYE")); //horizontal
    return model;
}

bool c_achat:: modifier(int ID,QString DATE_C,int PRIX, int ID_FOURNISSEUR, int ID_EMPLOYE)
{
    QSqlQuery query;

        QString ID_string=QString::number(ID);
        QString PRIX_string=QString::number(PRIX);
        QString ID_FOURNIISSEUR_string=QString::number(ID_FOURNISSEUR);
        QString ID_EMPLOYE_string=QString::number(ID_EMPLOYE);



        query.prepare("UPDATE COMMANDE_ACHAT set ID=:ID,DATE_C=:DATE_C,PRIX=:PRIX ,ID_FOURNISSEUR=:ID_FOURNISSEUR,ID_EMPLOYE=:ID_EMPLOYE  where ID= :ID ");
        query.bindValue(":ID", ID_string);
        query.bindValue(":DATE_C",DATE_C );
        query.bindValue(":PRIX", PRIX_string);
        query.bindValue(":ID_FOURNISSEUR", ID_FOURNIISSEUR_string);
        query.bindValue(":ID_EMPLOYE", ID_EMPLOYE_string);


        return    query.exec();
}

void c_achat::trier(Ui::MainWindow *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from COMMANDE_ACHAT order by ID");
       q.exec();
       model->setQuery(q);
       ui->tableView_4_kh->setModel(model);
}

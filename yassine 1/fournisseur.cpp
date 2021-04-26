#include "fournisseur.h"
#include <QDate>
#include <QString>
#include <QDebug>

fournisseur::fournisseur()
{
    this->ID=0;
    this->PRENOM="";
    this->NOM="";
     this->NUMERO=0;
     this->EMAIL="";
}
fournisseur::fournisseur(int ID,QString PRENOM,QString NOM,int NUMERO,QString EMAIL)
{
    this->ID=ID;
    this->PRENOM=PRENOM;
    this->NOM=NOM;
    this->NUMERO=NUMERO;
    this->EMAIL=EMAIL;

}
bool fournisseur::ajouter() //works
{
QSqlQuery query;
query.prepare("INSERT INTO FOURNISSEUR(ID,PRENOM,NOM,NUMERO,EMAIL)"
              " VALUES(:ID,:PRENOM,:NOM,:NUMERO,:EMAIL)");

query.bindValue(":ID",getID());
query.bindValue(":PRENOM",getPRENOM());
query.bindValue(":NOM",getNOM());
query.bindValue(":NUMERO",getNUMERO());
query.bindValue(":EMAIL",getEMAIL());
return query.exec();
}
QSqlQueryModel * fournisseur::afficher() //Works
    {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM")); //horizontal
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM")); //horizontal
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUMERO")); //horizontal
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL")); //horizontal
    return model;
    }

bool fournisseur::supprimer(int ID) //works
{
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("DELETE FROM FOURNISSEUR WHERE ID = :ID");
    query.bindValue(":ID",res);
    return query.exec();
    }

QSqlQueryModel *fournisseur::recherche(int ID) //Works
{
    QString query1="SELECT * FROM FOURNISSEUR WHERE ID=";
    QString idtxt= QString::number(ID);
    QString queryfull=query1 + idtxt;
  // qDebug() << "query  :" << queryfull;

    QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery(queryfull);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM")); //horizontal
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM")); //horizontal
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUMERO")); //horizontal
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL")); //horizontal
    return model;
}

bool fournisseur::testmail(QString EMAIL){
    int test=0;
    for(int i = 0; i < EMAIL.size(); i++) {
        if(EMAIL[i]=="@")
        {test++;

        }}
    for(int i = 0; i < EMAIL.size(); i++) {
        if((test==1)&&(EMAIL[i]=="."))
        {if(EMAIL.size()>i+1)
                return true;
        }}
    return false;}

bool fournisseur:: modifier(int ID,QString PRENOM,QString NOM, int NUMERO, QString EMAIL)
{
    QSqlQuery query;

        QString ID_string=QString::number(ID);
        QString NUMERO_string=QString::number(NUMERO);



        query.prepare("UPDATE FOURNISSEUR set ID=:ID,PRENOM=:PRENOM,NOM=:NOM ,NUMERO=:NUMERO,EMAIL=:EMAIL  where ID= :ID ");
        query.bindValue(":ID", ID_string);
        query.bindValue(":PRENOM",PRENOM );
        query.bindValue(":NOM",NOM);
        query.bindValue(":NUMERO", NUMERO_string);
        query.bindValue(":EMAIL",EMAIL);


        return    query.exec();
}

void fournisseur::trier(Ui::MainWindow *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from FOURNISSEUR order by ID");
       q.exec();
       model->setQuery(q);
       ui->tableView_3_kh->setModel(model);
}

#include "client.h"


#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QDate>
#include <QString>
#include <QDebug>
#include<QPrinter>
#include<QFileDialog>
#include<QTextDocument>



CLIENT::CLIENT()
{
cin=0; nom=""; prenom=""; mail=""; tel=0;
}

CLIENT::CLIENT(int cin, QString nom, QString prenom, QString mail, long tel)
{
this->cin=cin;
this->nom=nom;
this->prenom=prenom;
this->mail=mail;
this->tel=tel;
}

int CLIENT:: get_cin(){return cin; }

bool CLIENT:: ajouter()
{
    QSqlQuery query;

    QString cin_string=QString::number(cin);
    QString tel_string=QString::number(tel);


        query.prepare("INSERT INTO CLIENT (cin, nom, prenom,mail,tel) "
                  "VALUES (:cin, :nom, :prenom, :mail, :tel)");
        query.bindValue(":cin", cin_string);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":mail", mail);
        query.bindValue(":tel", tel_string);

    return    query.exec();
}

QSqlQueryModel *CLIENT::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT   ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero telephone"));



    return model;
}


QSqlQueryModel *CLIENT::afficher_combobox()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select CIN from CLIENT   ");
    return model;
}

QSqlQueryModel *CLIENT::afficher_mail()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select MAIL from CLIENT   ");
    return model;
}
bool CLIENT::supprimer(int cin)
{
    QSqlQuery query;
    QString res = QString:: number(cin);
    query.prepare("Delete from CLIENT where CIN = :cin ");
    query.bindValue(":cin", res);
    return    query.exec();
}

bool CLIENT:: modifier(int cin ,QString nom, QString prenom ,QString mail,long tel )
{QSqlQuery query;

    QString cin_string=QString::number(cin);
    QString tel_string=QString::number(tel);

    query.prepare("UPDATE CLIENT set CIN=:cin,NOM=:nom ,PRENOM=:prenom ,MAIL=:mail, TEL=:tel where CIN= :cin ");
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":tel", tel_string);

    return    query.exec();

}


QSqlQueryModel * CLIENT::rechercher(int cin)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from CLIENT where CIN =:cin");
    query.bindValue(":cin",cin);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}


QSqlQueryModel * CLIENT::afficher_tri_cin()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT order by CIN desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero telephone"));
    return model;
}
QSqlQueryModel * CLIENT::afficher_trinom()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT order by NOM desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero telephone"));

    return model;
}
QSqlQueryModel * CLIENT::afficher_triprenom()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT order by PRENOM desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero telephone"));
    return model;
}

bool CLIENT::testmail(QString mail){
    int test=0;
    for(int i = 0; i < mail.size(); i++) {
        if(mail[i]=="@")
        {test++;

        }}
    for(int i = 0; i < mail.size(); i++) {
        if((test==1)&&(mail[i]=="."))
        {if(mail.size()>i+1)
                return true;
        }}
    return false;}


QSqlQueryModel *CLIENT::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero telephone"));


    return model;
}


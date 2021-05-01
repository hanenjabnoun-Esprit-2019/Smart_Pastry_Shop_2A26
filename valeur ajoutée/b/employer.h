#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QString>
#include <QSqlQueryModel>


class Employer
{
public:
    Employer();
    Employer(int,QString,QString,float,long,int,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    float getsalaire();
    long getnumero();
    int getid_depp();
    QString get_service() ;
    QString get_mdp() ;
    QString get_e_mail() ;



    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* recherche(int);
    QSqlQueryModel* trier();
private:
    int id,id_depp;
    long numero;
    float salaire;
    QString nom,prenom,service,mdp,e_mail;




};

#endif // EMPLOYER_H

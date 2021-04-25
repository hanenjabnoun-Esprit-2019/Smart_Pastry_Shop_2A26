#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QString>
#include <QSqlQueryModel>


class Employer
{
public:
    Employer();
    Employer(int,QString,QString,float,long,int);
    int getid();
    QString getnom();
    QString getprenom();
    float getsalaire();
    long getnumero();
    int getid_depp();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setsalaire(float);
    void setnumero(long);
    void setid_depp(int);
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
    QString nom,prenom;




};

#endif // EMPLOYER_H

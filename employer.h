#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QString>
#include <QSqlQueryModel>

class Employer
{
public:
    Employer();
    Employer(int,QString,QString,float,int,int);
    int getid();
    QString getnom();
    QString getprenom();
    float getsalaire();
    int getnumero();
    int getid_depp();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setsalaire(float);
    void setnumero(int);
    void setid_depp(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
    int id,numero,id_depp;
    float salaire;
    QString nom,prenom;




};

#endif // EMPLOYER_H

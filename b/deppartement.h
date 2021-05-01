#ifndef DEPPARTEMENT_H
#define DEPPARTEMENT_H
#include<QString>
#include <QSqlQueryModel>

class Deppartement
{
public:
    Deppartement();
    Deppartement(int,QString,QString,QString);
    int getid();
    QString getspecialite();
    QString getgerant();
    QString getlocal();

    void setid(int);
    void setspecialite(QString);
    void setgerant(QString);
    void setlocal(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* recherche(int);

private:
    int id_dep;
    QString specialite,gerant,localisation;
};

#endif // DEPPARTEMENT_H

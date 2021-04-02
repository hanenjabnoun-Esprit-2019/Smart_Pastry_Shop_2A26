#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>

class CLIENT
{
public:
    CLIENT();
    CLIENT(int,QString,QString,QString,long);

    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    long getnumero();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setnumero(long);

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * afficherC();

    bool supprimer(int);

    bool modifier(int,QString,QString,QString,long);
     bool rech(int);
     QSqlQueryModel * afficherclientchercher();
     QSqlQueryModel * trier_id();

private:
    int id;
    QString nom , prenom , email;
    long numero;
};

#endif // CLIENT_H

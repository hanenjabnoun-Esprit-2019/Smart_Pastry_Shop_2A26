#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>

class CLIENT
{
public:
    CLIENT();
    CLIENT(int,QString,QString,QString,int);

    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    int getnumero();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setnumero(int);

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int,QString,QString,QString,int);

private:
    int id;
    QString nom , prenom , email;
    int numero;
};

#endif // CLIENT_H

#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>


class CLIENT
{
public:
    CLIENT();
    CLIENT(int,QString,QString,QString,long);

    int get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_mail();
    long get_tel();

    bool ajouter();
    QSqlQueryModel * afficher();

    QSqlQueryModel * afficher_combobox();
    QSqlQueryModel * afficher_mail();

    bool testmail(QString);


    bool supprimer(int);

    bool modifier(int,QString,QString,QString,long);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri_cin();
    QSqlQueryModel * afficher_trinom();
    QSqlQueryModel * afficher_triprenom();


    QSqlQueryModel *displayClause(QString cls);


private:
    int cin;
    QString nom , prenom , mail;
    long tel;
};

#endif // CLIENT_H

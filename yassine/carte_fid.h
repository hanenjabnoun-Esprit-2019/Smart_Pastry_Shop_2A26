#ifndef CARTE_FID_H
#define CARTE_FID_H
#include <QString>
#include <QSqlQueryModel>

class carte_fid
{
public:
    carte_fid();
    carte_fid(int, QString , int, int);

    int getid();
    QString gettype();
    int getpt();
    int getid_client();

    void setid(int);
    void settype(QString);
    void setpt(int);
    void setid_client(int);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(int );


    QSqlQueryModel * afficher_tri_id_carte();

    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel * afficher_fidele();

private:
    int id;
    QString type;
    int pt,id_client;
};

#endif // CARTE_FID_H

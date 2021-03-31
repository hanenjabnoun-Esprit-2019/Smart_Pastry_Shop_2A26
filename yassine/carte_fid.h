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

    bool ajouter_carte();
    QSqlQueryModel* afficher_carte();


    bool supprimer_carte(int);

    bool modifier_carte(int,QString,int,int);
     bool rech_carte(int);
     QSqlQueryModel * affichercartechercher();
     QSqlQueryModel * trier_type();

private:
    int id;
    QString type;
    int pt,id_client;
};

#endif // CARTE_FID_H

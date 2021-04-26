#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>

class commande
{
public:
    void setcommande(commande c);

    void setid(QString n);
    void setquantite(QString n);
    void setfournisseur(QString n);
    void setclient (QString n);
   QString get_id();
   QString get_quantite();
   QString get_fournisseir();
   QString get_client();
    commande();

    bool ajouter();

private:
    QString id,quantite,fournisseur,client;
};

#endif // COMMANDE_H

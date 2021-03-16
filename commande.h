#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>

class commande
{
public:


    void setidcommande(Qstring n);
    void setquantite (Qstring n);
    void setidclient (Qstring n);
    void setdate (Qstring n);
    void setdatel (Qstring n);

    QString get_idcommande ();
    QString get_quantite ();
    QString get_idclient ();
    QString get_date ();
    QString get_datel ();
    commande();


    private:
    QString idcommande,quantite,date,idclient,datel;
};

#endif // COMMANDE_H

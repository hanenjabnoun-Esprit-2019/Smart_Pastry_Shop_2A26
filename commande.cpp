#include "commande.h"
#include<QString>

commande::commande()
{
idcommande "";
quantite "";
idclient "";
date "";
datel "";

void commande::setidcommande(Qstring n){idcommande=n;}
void commande::setquantite(Qstring n){quantite=n;}
void commande::setidclient(Qstring n)Qstring n){idclient=n;}
void commande::setdate(Qstring n){date=n;}
void commande::datel(Qstring n){datel=n;}
Qstring commande::get_idcommande(){return idcommande;}
Qstring commande::get_idclient(){return idclient;}
Qstring commande::get_quantite(){return quantite;}
Qstring commande::get_date(){return date;}
Qstring commande::get_datel(){return datel;}











}

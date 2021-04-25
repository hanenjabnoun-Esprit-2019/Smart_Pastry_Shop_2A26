#include "commande.h"
#include <QSqlQuery>

commande::commande()
{
 id="";quantite="";fournisseur="";client="";

}

void commande::setid(QString n){id=n;}
void commande::setquantite(QString n){quantite=n;}
void commande::setfournisseur(QString n){fournisseur=n;}
void commande::setclient(QString n){client=n;}

QString commande::get_id(){return id;}
QString commande::get_quantite(){return quantite;}
QString commande::get_fournisseir(){return fournisseur;}
QString commande::get_client(){return client;}

bool commande::ajouter()
{

}


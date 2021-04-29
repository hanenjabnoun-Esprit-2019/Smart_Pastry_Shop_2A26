#ifndef C_ACHAT_H
#define C_ACHAT_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>



class c_achat
{
    int ID;
    QString DATE_C;
    int PRIX;
    int ID_FOURNISSEUR;
    int ID_EMPLOYE;


public:
    c_achat();
    c_achat(int ID ,QString DATE_C,int PRIX,int ID_FOURNISSEUR,int ID_EMPLOYE);

    //getters
    int getID(){return ID;}
    QString getDATE_C(){return DATE_C;}
    int getPRIX(){return PRIX;}
    int getID_FOURNISSEUR(){return ID_FOURNISSEUR;}
    int getID_EMPLOYE(){return ID_EMPLOYE;}

    //Setters
      void setID(int x){ID = x ;}
      void setDATE_C(QString x){DATE_C = x ;}
      void setPRIX(int x){PRIX = x ;}
      void setID_FOURNISSEUR(int x){ID_FOURNISSEUR = x ;}
      void setID_EMPLOYE(int x){ID_EMPLOYE = x ;}


     bool ajouter();
    QSqlQueryModel * afficher();
     bool supprimer(int);
    QSqlQueryModel * recherche(int ID);

     bool modifier(int ID,QString DATE_C,int PRIX,int ID_FOURNISSEUR,int ID_EMPLOYE );
     bool imprimer(int ID);
     QSqlQueryModel * trier();

};

#endif // C_ACHAT_H

#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
#include "ui_mainwindow.h"

class fournisseur
{
    int ID;
    QString PRENOM ;
    QString NOM;
    int NUMERO;
    QString EMAIL;

public:
    fournisseur();
    fournisseur(int ID ,QString PRENOM, QString NOM,int NUMERO,QString EMAIL);

    //getters
    int getID(){return ID;}
    QString getPRENOM(){return PRENOM;}
    QString getNOM(){return NOM;}
    int getNUMERO(){return NUMERO;}
    QString getEMAIL(){return EMAIL;}
    //Setters
    void setID(int x){ID = x ;}
    void setPRENOM(QString x){PRENOM = x ;}
     void setNOM(QString x){NOM = x ;}
      void setNUMERO(int x){NUMERO = x ;}
    void setEMAIL(QString x){EMAIL = x ;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(int ID);

   bool imprimer(int ID);
   void trier(Ui::MainWindow *ui);
   bool testmail(QString);
   bool modifier(int ID,QString PRENOM,QString NOM, int NUMERO, QString EMAIL);
   bool stati (int ID,QString PRENOM,QString NOM, int NUMERO, QString EMAIL );

};


#endif // FOURNISSEUR_H

#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
#include "ui_mainwindow.h"

class maintenance
{
    int ID;
    QString DATE_M;
    int PRIX;
    int ID_EQP;
    int ID_EMPLOYE;
public:
    maintenance();
    maintenance(int ID,QString DATE_M,int PRIX,int ID_EQP,int ID_EMPLOYE);

    //getters
    int getID(){return ID;}
    QString getDATE_M(){return DATE_M;}
    int getPRIX(){return PRIX;}
    int getID_EQP(){return ID_EQP;}
    int getID_EMPLOYE(){return ID_EMPLOYE;}

    //Setters
    void setID(int x){ID = x ;}
    void setDATE_M(QString x){DATE_M = x ;}
    void setPRIX(int x){PRIX = x ;}
    void setID_EQP(int x){ID_EQP = x ;}
    void setID_EMPLOYE(int x) {ID_EMPLOYE= x;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *recherche(int ID);
  bool modifier(int ID,QString DATE_M,int PRIX,int ID_EQP,int ID_EMPLOYE);
   // QSqlQueryModel * trier_id();
    void trier_id(Ui::MainWindow *ui);
    void creationpdf();

};



#endif // MAINTENANCE_H

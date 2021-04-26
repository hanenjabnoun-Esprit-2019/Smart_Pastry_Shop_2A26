#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
#include "ui_mainwindow.h"

class equipement
{
    int ID;
    QString NOM;
    QString ETAT;

public:
    equipement();
    equipement(int ID ,QString NOM,QString ETAT);

    //getters
    int getID(){return ID;}
    QString getNOM(){return NOM;}
    QString getETAT(){return ETAT;}

    //Setters
    void setID(int x){ID = x ;}
    void setNOM(QString x){NOM = x ;}
    void setETAT(QString x){ETAT = x ;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(int ID);
 //   bool modifier(Ui::MainWindow *ui);
  //   bool modifiereqp ();
  //  QSqlQueryModel * trier_id();
   bool modifier(int ID);
    void trier_id(Ui::MainWindow *ui);
      void creationpdf();
      void imprimer();
     bool modifier(int ID,QString NOM,QString ETAT);
   //  QVector<double> Statistique();
     QSqlQueryModel *displayClause(QString cls);


};


#endif // EQUIPEMENT_H

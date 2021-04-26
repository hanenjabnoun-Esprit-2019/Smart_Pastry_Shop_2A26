#include "maintenance.h"
#include <QDate>
#include <QString>
#include <QDebug>
#include<QPrinter>
#include<QFileDialog>
#include<QTextDocument>
maintenance::maintenance()
{
    this->ID=0;
    this->DATE_M="";
    this->PRIX=0;
    this->ID_EQP=0;
    this->ID_EMPLOYE=0;
}
maintenance::maintenance(int ID,QString DATE_M,int PRIX,int ID_EQP,int ID_EMPLOYE)
{
    this->ID=ID;
    this->DATE_M=DATE_M;
    this->PRIX=PRIX;
    this->ID_EQP=ID_EQP;
    this->ID_EMPLOYE=ID_EMPLOYE;
}

bool maintenance::ajouter() //works
{
QSqlQuery query;
query.prepare("INSERT INTO MAINTENANCE(ID,DATE_M,PRIX,ID_EQP,ID_EMPLOYE)"
              " VALUES(:ID,:DATE_M,:PRIX,:ID_EQP,:ID_EMPLOYE)");

query.bindValue(":ID",getID());
query.bindValue(":DATE_M",getDATE_M());
query.bindValue(":PRIX",getPRIX());
query.bindValue(":ID_EQP",getID_EQP());
query.bindValue(":ID_EMPLOYE",getID_EMPLOYE());

return query.exec();
}
QSqlQueryModel * maintenance::afficher() //Works
    {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from maintenance");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_M")); //horizontal
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX")); //horizontal
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_EQP")); //horizontal
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_EMPLOYE")); //horizontal
    return model;
    }

bool maintenance::supprimer(int ID) //works
{
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("DELETE FROM MAINTENANCE WHERE ID = :ID");
    query.bindValue(":ID",res);
    return query.exec();
    }
QSqlQueryModel *maintenance::recherche(int ID) //Works
{
    QString query1="SELECT * FROM MAINTENANCE WHERE ID=";
    QString idtxt= QString::number(ID);
    QString queryfull=query1 + idtxt;
  // qDebug() << "query  :" << queryfull;

    QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery(queryfull);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_M")); //horizontal
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX")); //horizontal
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_EQP")); //horizontal
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_EMPLOYE")); //horizontal
    return model;
}
/*QSqlQueryModel * fournisseur::afficher_choix1(QString choix)//trier
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="")
    {
     model->setQuery("SELECT * FROM fournisseur  ORDER BY NOM;");
    }
    else if(choix=="Tel")
    {
        model->setQuery("SELECT * FROM fournisseur  ORDER BY tel  ASC ;");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE_FOUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL_FOUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL_FOUR"));

    return model;
}*/

bool maintenance:: modifier(int ID,QString DATE_M,int PRIX,int ID_EQP,int ID_EMPLOYE)
{
    QSqlQuery query;

        QString ID_string=QString::number(ID);
        QString PRIX_string=QString::number(PRIX);
        QString ID_EQP_string=QString::number(ID_EQP);
        QString ID_EMPLOYE_string=QString::number(ID_EMPLOYE);

        query.prepare("UPDATE MAINTENANCE set ID=:ID,DATE_M=:DATE_M ,PRIX=:PRIX ,ID_EQP=:ID_EQP, ID_EMPLOYE=:ID_EMPLOYE where ID= :ID ");
        query.bindValue(":ID", ID_string);
        query.bindValue(":DATE_M",DATE_M );
        query.bindValue(":PRIX", PRIX_string);
        query.bindValue(":ID_EQP", ID_EQP_string);
        query.bindValue(":ID_EMPLOYE", ID_EMPLOYE_string);

        return    query.exec();
}
/*QSqlQueryModel * maintenance::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from MAINTENANCE ORDER BY id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_M"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_EQP"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));

        return model;
}*/
void maintenance::trier_id(Ui::MainWindow *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from MAINTENANCE order by ID");
       q.exec();
       model->setQuery(q);
       ui->tableView_3_mou->setModel(model);
}
void maintenance::creationpdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM MAINTENANCE ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE DE Maintenance  <br></h1>\n <br> <table>  <tr>  <th> ID  </th> <th> Date de maintenance </th> <th> cout de maintenance </th><th> Identifient d'equipement </th><th> Identifient d'employe </th> </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" " "ans "  " " "</td>   <td>"+q.value(5).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

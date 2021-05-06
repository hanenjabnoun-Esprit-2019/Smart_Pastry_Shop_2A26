#include "equipement.h"
#include <QDate>
#include <QString>
#include <QDebug>
#include<QPrinter>
#include<QFileDialog>
#include<QTextDocument>
equipement::equipement()
{
    this->ID=0;
    this->NOM="";
    this->ETAT="";
}
equipement::equipement(int ID,QString NOM,QString ETAT)
{
    this->ID=ID;

    this->NOM=NOM;
    this->ETAT=ETAT;
}
bool equipement::ajouter() //works
{
QSqlQuery query;
query.prepare("INSERT INTO EQUIPEMENT(ID,NOM,ETAT)"
              " VALUES(:ID,:NOM,:ETAT)");

query.bindValue(":ID",getID());
query.bindValue(":NOM",getNOM());
query.bindValue(":ETAT",getETAT());

return query.exec();
}
QSqlQueryModel * equipement::afficher() //Works
    {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from equipement");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM")); //horizontal
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT")); //horizontal
    return model;
    }

bool equipement::supprimer(int ID) //works
{
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("DELETE FROM EQUIPEMENT WHERE ID = :ID");
    query.bindValue(":ID",res);
    return query.exec();
    }

QSqlQueryModel *equipement::recherche(int ID) //Works
{
    QString query1="SELECT * FROM EQUIPEMENT WHERE ID=";
    QString idtxt= QString::number(ID);
    QString queryfull=query1 + idtxt;
  // qDebug() << "query  :" << queryfull;

    QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery(queryfull);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM")); //horizontal
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT")); //horizontal
    return model;
}
bool equipement:: modifier(int ID,QString NOM,QString ETAT)
{
    QSqlQuery query;

        QString ID_string=QString::number(ID);


        query.prepare("UPDATE EQUIPEMENT set ID=:ID,NOM=:NOM ,ETAT=:ETAT  where ID= :ID ");
        query.bindValue(":ID", ID_string);
        query.bindValue(":NOM",NOM );
        query.bindValue(":ETAT", ETAT);


        return    query.exec();
}

/*bool equipement::modifier(Ui::MainWindow *ui)
{
    QSqlQuery query;
       int a = ui->lineEdit_19->text().toInt();
       QString b = ui->lineEdit_20->text();
       QString c = ui->lineEdit_21->text();
       QString teta= QString::number(a);

       query.prepare ("update EQUIPEMENT set ID ='"+teta+"', NOM='"+b+"', ETAT='"+c+"'' WHERE ID ='"+teta+"'");
      return query.exec();
}*/

/*QSqlQueryModel * equipement::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));

        return model;
}*/

/*QSqlQueryModel * equipement::afficher_choix1(QString choix)//trier
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="DATE_DEV")
    {
     model->setQuery("SELECT * FROM DEVIS  ORDER BY DATE_DEV;");
    }
    else if(choix=="MONTNET_DEV")
    {
        model->setQuery("SELECT * FROM DEVIS  ORDER BY MONTNET_DEV  ASC ;");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_DEV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTNET_DEV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESC_DEV"));

    return model;
}*/
/*QString queryStr("Select * from equipement order by ID desc");
QSqlQuery query = QSqlDatabase->exec(queryStr);

if(query.lastError().isValid())
{
   //print Erreur
}
else
{
   while(query.next())
   {
       //Traitement par ligne de résultat
       int ID = query.value(0).toInt();
   }
}*/
QSqlQueryModel *equipement::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from equipement order by id desc ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")); //horizontal
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM")); //horizontal
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT")); //horizontal
        return model;
}
void equipement::creationpdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM EQUIPEMENT ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE DES EQUIPEMENT  <br></h1>\n <br> <table>  <tr>  <th> ID  </th> <th> NOM DE Materiel </th> <th> Etat Presentiel </th> </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" " "ans "  " " "</td>   <td>"+q.value(5).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}
void equipement::imprimer()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export TXT", QString(), "*.txt");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM EQUIPEMENT ");
        q.exec();
        QString txt="<br> <h1  style='color:red'>LISTE DES EQUIPEMENT  <br></h1>\n <br> <table>  <tr>  <th> ID  </th> <th> NOM DE Materiel </th> <th> Etat Presentiel </th> </tr>" ;


        while ( q.next()) {

            txt= txt+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" " "ans "  " " "</td>   <td>"+q.value(5).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

        }
        doc.setHtml(txt);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}
/*QVector<double> equipement::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT * FROM EQUIPEMENT WHERE ETAT=='1'");
    q.exec();
    while (q.next())
    {
        stat[0]+=q.value(3).toInt();
    }
    q.prepare("SELECT * FROM EQUIPEMENT WHERE ETAT=='0'");
    q.exec();
    while (q.next())
    {
        stat[1]+=q.value(3).toInt();
    }

    return stat;
}
*/

QSqlQueryModel *equipement::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EQUIPEMENT " +cls);
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}


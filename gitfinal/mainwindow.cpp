#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admin.h"
#include"employer.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QBuffer>

#include "user.h"
#include<QDateTime>
#include<QTimer>

#include <QMovie>
#include <QThread>
#include "smtp.h"
#include <QUrl>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
timer= new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(myfunction1()));
timer->start(1000);




    ui->username->setPlaceholderText("Entrer votre Identifiant :") ;
    ui->password->setPlaceholderText("Entrer votre Mot de passe :") ;
    ui->stackedWidget->setCurrentIndex(0);






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::myfunction1()
{
QTime time=QTime::currentTime();
QString time_text=time.toString("hh : mm : ss");
if ((time.second()% 2)==0){
    time_text[3]=' ';
    time_text[8]=' ';


}
ui->label_datetime->setText(time_text);


}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();


    QSqlQuery qry;
    qry.prepare("Select * from employer where nom=:nom");
    qry.bindValue(":nom",username);
    qry.exec();
    while (qry.next())

    {
        if ( qry.value(1).toString()==username && qry.value(7).toString()==password &&qry.value(6).toString()=="Administrateur" )
        {
                              // hide();//La fenetre d'authentification se ferme automatiquement
            admin a;
            a.exec() ;
        }
       else
            if(qry.value(1).toString()==username && qry.value(7).toString()==password &&qry.value(6).toString()!="Administrateur")
            {
                             //  hide();
                User u;
                u.exec();

            }
            else
                QMessageBox::warning(this, "Connexion Impossible", "Identifiant ou mot de passe incorrect ! ") ;
    }
    ui->Status->hide();
}

/*
void MainWindow::on_pushButton_3_clicked()
{
    music->stop() ;
}

void MainWindow::on_pushButton_2_clicked()
{
    music->play() ;
}
*/
/*void MainWindow::myfunction()
{
    QTime time = QTime::currentTime() ;
    QString time_text=time.toString("hh : mm : ss")  ;

    ui->label_date_time->setText(time_text) ;
}
*/

void MainWindow::on_mdp_oublie_clicked()
{
    ui->code_recuperation_2->hide();
    ui->confirmation->hide();
    ui->nouveau_mdp->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->valider_mdp->hide();

    ui->email->show();
    ui->label_11->show();
    ui->mail->show();
    ui->email->setReadOnly(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_valider_mdp_clicked()
{
    QSqlQuery query;
    QByteArray array;

    QString mail = ui->email->text();

    int id,id_depp;
    long numero;
    float salaire;
    QString nom,prenom,service,mdp,e_mail;
    query.prepare("select * from employer where e_mail = '"+mail+"'");
    if (query.exec())
    {
        while(query.next())
        {
            id = query.value(0).toInt();
            nom = query.value(1).toString();
            prenom = query.value(2).toString();
            salaire = query.value(3).toFloat();
            numero = query.value(4).toLongLong();
            id_depp = query.value(5).toInt();
            service = query.value(6).toString();
            e_mail =  query.value(8).toString();



            array = query.value(17).toByteArray();
            QBuffer buffer(&array);
            image = (array);
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData(image);
        }
    }

    mdp = ui->nouveau_mdp->text();
    if ((ui->nouveau_mdp->text() == ui->confirmation->text()) && (ui->code_recuperation_2->text()==get_code()))
    {
        bool test=E.supprimer(id) ;
        Employer E(id,nom,prenom,salaire,numero,id_depp,service,mdp,e_mail) ;
        bool test1=E.ajouter() ;
        //        e.AjoutImage(fileNameImage);
        //        bool test = e.update();

        //        bool test = tmpemp.update();
        if (test && test1)
        {
            QMessageBox::information(nullptr, QObject::tr("Réinitialiser mdp"),
                                     QObject::tr("Mot De Passe modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->stackedWidget->setCurrentIndex(0);
            ui->code_recuperation_2->clear();
            ui->confirmation->clear();
            ui->nouveau_mdp->clear();
            ui->email->clear();
        }else

            QMessageBox::critical(nullptr, QObject::tr("Réinitialiser mdp"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::information(nullptr, QObject::tr("Réinitialiser mdp"),
                                 QObject::tr("Erreur ! Le code de récupération est incorrect \nou "
                                             "les mots de passe sont différents. \n"), QMessageBox::Cancel);
}



void MainWindow::on_mail_clicked()
{
    QString code = generer_code();
    QString text = "Bonjour Monsieur/Madame, \n\nVous avez demandé à changer le mot de passe de votre compte Smart Pastry Shop \n\n"
                   "Voici votre code récupération: " + code +" \n\n Si ce n'est pas vous, veuillez contacter votre responsable au plus vite.\n\n"
                                                             " Cordialement,\n L'Equipe OTOM";
    Smtp* smtp = new Smtp("houssemjrad94@gmail.com","03101919","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("houssemjrad94@gmail.com", ui->email->text(),"Reinitialisation mot de passe Smart Pastry Shop",text );
    set_code(code);

}

QString MainWindow::get_code(){return code;}
void MainWindow::set_code(QString code){this->code = code;};

void MainWindow::mailSent(QString status)
{
    if (status == "Message sent")
    {
        ui->code_recuperation_2->show();
        ui->confirmation->show();
        ui->nouveau_mdp->show();
        ui->label_12->show();
        ui->label_13->show();
        ui->label_14->show();
        ui->valider_mdp->show();

        ui->email->show();
        ui->label_11->show();
        ui->mail->hide();
        ui->email->setReadOnly(true);
    }
}
void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

QString MainWindow:: generer_code()
{
    int cpt = 0;
    QString chaine ="";
    srand(time(NULL));
    while (cpt != 4)
    {
        int lettre = (rand() % ('Z' - 'A'+ 1)) + 'A';
        chaine += lettre;
        int nbr = (rand() % 9) + 1;
        chaine += " "+QString::number(nbr);
        cpt++;
    }
    return chaine;
}

void MainWindow::on_pushButton_facebook_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.facebook.com", QUrl::TolerantMode));
}

void MainWindow::on_pushButton_twitter_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.twitter.com", QUrl::TolerantMode));
}


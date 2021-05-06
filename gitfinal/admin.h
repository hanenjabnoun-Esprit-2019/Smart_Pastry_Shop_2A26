#ifndef ADMIN_H
#define ADMIN_H
#include "mainwindow.h"
#include "ui_admin.h"

#include "client.h"
#include "carte_fid.h"
#include "notification.h"
#include "notifications.h"
#include "popup.h"
#include "hcommande.h"
#include "commandev.h"
#include "c_achat.h"
#include "employer.h"
#include "deppartement.h"
#include <QMediaPlayer>
#include "maintenance.h"
#include "equipement.h"
#include <QDialog>
#include "fournisseur.h"
#include "c_achat.h"

#include<QTimer>

#include<QPainter>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>
#include<QSqlTableModel>
#include <QChartView>
#include <QDialog>








namespace Ui { class admin; }



class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:

     void on_client_clicked();
      void on_commande_clicked();
       void on_fournisseur_clicked();
        void on_employe_clicked();
         void on_maintenance_clicked();

    //************************* client
    void refresh();

    void on_pb_ajouter_abonne_clicked();

    void on_pb_supprimer_abonne_clicked();

    void on_pb_modifier_abonne_clicked();

    void on_comboBox_4_activated();

    void on_pdf_clicked();

    void on_refresh_clicked();

    void on_rechercher_abonne_textChanged();

    void on_radioButton_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_7_clicked();



    //*********************************



    //************************* carte fidelite

    void on_pb_ajouter_abonnement_clicked();

    void on_pb_supprimer_abonnement_clicked();

    void on_pb_modifier_abonnement_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_comboBox_7_activated();

    void on_rechercher_abonnement_textChanged();

    void on_pb_ajouter_7_clicked();

   // void mailSent(QString );

    void on_radioButton_6_clicked();

    void on_refresh_2_clicked();

    void on_pdf_2_clicked();



    bool testmail(QString);


    //*********************************

    //**************** seif *****************


    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_update_clicked();

    void on_pb_ajouter_depp_clicked();

    void on_pb_supp_depp_clicked();


    void on_pdf_3_clicked();



    void on_pb_chercher_clicked();

    void on_update_depp_clicked();

    void on_pb_chercher_depp_clicked();

    void on_trier_clicked();

    void on_reset_employer_clicked();

    void on_reset_depp_clicked();


//*********************************

    //*************** houssem ******************


    void on_ajouterc_3_clicked();

    void on_Supp_3_clicked();

    void on_trier_6_clicked();

    void on_search_3_clicked();

    void on_update_3_clicked();

    void on_export_4_clicked();


    void sendMail();

    void mailSent(QString);

    void on_ajouterc_4_clicked();

    void on_Supp_4_clicked();

    void on_trier_7_clicked();

    void on_pushButton_2_clicked();

    void on_search_4_clicked();

    void on_update_4_clicked();

    void on_export_5_clicked();

    void on_trier_8_clicked();

    void on_trier_9_clicked();

 //*********************************

    //*************** moussa ******************

    void on_pushButton_10_mou_clicked();



        void on_pushButton_mou_clicked();

        void on_pushButton_5_mou_clicked();

        void on_pushButton_4_mou_clicked();

        void on_pushButton_6_mou_clicked();



        void on_pushButton_2_mou_clicked();

        void on_pushButton_13_mou_clicked();

        void on_pushButton_9_mou_clicked();

        void on_pushButton_8_mou_clicked();

        void on_pushButton_14_mou_clicked();

        void on_pushButton_15_mou_clicked();


        void on_pushButton_3_mou_clicked();



        void on_tableView_3_mou_clicked(const QModelIndex &index);

        void on_tableView_4_mou_clicked(const QModelIndex &index);




        void on_pushButton_7_mou_clicked();

        void on_pushButton_11_mou_clicked();



        void on_pushButton_16_mou_clicked();



       /* void on_stat_clicked();

        void on_refresh_clicked();*/

        //*********************************

        //*************** khalil ******************


        void on_pushButton_10_kh_clicked();



            void on_pushButton_kh_clicked();

            void on_pushButton_5_kh_clicked();

            void on_pushButton_4_kh_clicked();

            void on_pushButton_6_kh_clicked();



            void on_pushButton_2_kh_clicked();

            void on_pushButton_13_kh_clicked();

            void on_pushButton_9_kh_clicked();

            void on_pushButton_8_kh_clicked();

            void on_pushButton_14_kh_clicked();

            void on_pushButton_15_kh_clicked();


            void on_tableView_3_kh_clicked(const QModelIndex &index);

            void on_tableView_4_kh_clicked(const QModelIndex &index);



            void on_pushButton_3_kh_clicked();

            void on_pushButton_7_kh_clicked();



            void on_pdf_kh_clicked();

            //*********************************

            void on_deconnexion_clicked();

           /* void on_chatButton_clicked();*/

            void on_pushButton_clicked();

            void on_pushButton_3_clicked();

            void on_pushButton_4_clicked();

            void on_excel_2_clicked();

private:
    Ui::admin *ui;

    CLIENT tmpabonnee;
    carte_fid tmpabonnement;
    Notification N;
    popup *popUp;
    QPixmap PixTrueIcon;
    QPixmap PixFalseIcon;
    QPixmap photo ;
    QString fileNameImage ;
    QString fileNameImage2 ;
    QByteArray image;
    QTimer * timerr ;
     QString text;
     Employer E;
     Deppartement D;
     hcommande Etmp;
     commandev ss;
     equipement etemp;
         maintenance mtemp;
         fournisseur ftemp;
             c_achat ctemp;
             QMediaPlayer * music = new QMediaPlayer();
             QTimer * timer ;

             QString code;
};

#endif // ADMIN_H

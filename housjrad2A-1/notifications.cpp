#include "notifications.h"
#include <QSystemTrayIcon>
#include<QString>
Notifications::Notifications()
{

}

void Notifications::notifications_ajoutercommande()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","Nouvelle commande ajouté ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_ajoutercommandev()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

     notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des participation ","Nouvelle participation ajouté ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_supprimercommande(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","commande Supprimé",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_supprimercommandev(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","Une commande est supprimé",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_modifiercommande(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","Une commande est modifié",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_modifiercommandev(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des participations ","Une participation est modifié",QSystemTrayIcon::Information,15000);

}

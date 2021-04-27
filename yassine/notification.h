#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_ajoutAbonne();
    void notification_ajoutAbonnement();
    void notification_supprimerAbonne();
    void notification_supprimerAbonnement();
    void notification_modifierAbonne();
    void notification_modifierAbonnement();
    void mail_Abonnement();






};

#endif // NOTIFICATION_H

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H


#include <QSystemTrayIcon>
#include<QString>
class Notifications
{
public:
    Notifications();
    void notifications_ajoutercommande();
    void notifications_ajoutercommandev();
    void notifications_supprimercommande();
    void notifications_supprimercommandev();
    void notifications_modifiercommande();
    void notifications_modifiercommandev();

};

#endif // NOTIFICATIONS_H

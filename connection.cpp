#include <connection.h>

Connection::Connection()
{

}

bool Connection::createConnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A26");//inserer le nom de la source de données ODBC
db.setUserName("yassine");//inserer nom de l'utilisateur
db.setPassword("yassine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
void Connection::closeConnection (){db.close();}

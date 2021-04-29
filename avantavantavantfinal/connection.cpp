#include <connection.h>

Connection::Connection()
{

}

bool Connection::createConnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2A26");//inserer le nom de la source de données ODBC
db.setUserName("houssem");//inserer nom de l'utilisateur
db.setPassword("houssem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
void Connection::closeConnection (){db.close();}

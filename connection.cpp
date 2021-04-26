#include <connection.h>

Connection::Connection()
{

}

bool Connection::createConnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2a26");//inserer le nom de la source de données ODBC
db.setUserName("bd");//inserer nom de l'utilisateur
db.setPassword("123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
void Connection::closeConnection (){db.close();}

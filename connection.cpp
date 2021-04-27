#include<connection.h>

Connection::Connection(){};

bool Connection::createConnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Projet2A.");
    db.setUserName("bd");
    db.setPassword("123");

    if (db.open()) test=true;

    return test;
}

void Connection::closeConnection(){db.close();}

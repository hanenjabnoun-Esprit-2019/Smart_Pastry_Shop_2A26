#include<connection.h>

Connection::Connection(){};

bool Connection::createConnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("projet2");
    db.setUserName("houssem");
    db.setPassword("houssem");

    if (db.open()) test=true;

    return test;
}

void Connection::closeConnection(){db.close();}

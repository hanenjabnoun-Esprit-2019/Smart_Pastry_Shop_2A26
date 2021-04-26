#include<connection.h>

Connection::Connection(){};

bool Connection::createConnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("projet2a26");
    db.setUserName("bd");
    db.setPassword("123");

    if (db.open()) test=true;

    return test;
}

void Connection::closeConnection(){db.close();}

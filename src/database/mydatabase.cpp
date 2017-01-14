#include "mydatabase.h"
#include <QDebug>

MyDatabase::MyDatabase(QObject *parent) : QObject(parent)
{

}

MyDatabase::~MyDatabase()
{
    qDebug() << "database closed!";
    db.close();
}

bool MyDatabase::open()
{
    if(!QFileInfo::exists("lug.db"))
    {
        createDatabase("lug.db");
        return true;
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lug.db");
    db.setUserName("ilug");
    db.setPassword("ilug");

    if (!db.open()) {
        qDebug("database Not Exist!");
        if(this->createDatabase("lug.db"))
        {
            return true;
        }
        else
        {
            qDebug("ERROR!!! Can't Open and Create Database!!!");
            return false;
        }
    }
    qDebug("database opened!");
    return true;
}

void MyDatabase::dbTransaction()
{
    db.transaction();
}

void MyDatabase::dbCommit()
{
    db.commit();
}

bool MyDatabase::createDatabase(QString path)
{    
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.setUserName("ilug");
    db.setPassword("ilug");
    db.open();
    QSqlQuery query;

    query.exec("CREATE TABLE dueDay ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
               "date DATE NOT NULL)");
    query.exec("CREATE TABLE person ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
               "code TEXT UNIQUE,"
               "firstName TEXT NOT NULL,"
               "lastName TEXT NOT NULL,"
               "sessionCounter INTEGER,"
               "email TEXT,"
               "registerDay TEXT)");
    query.exec("CREATE TABLE attendant ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
               "personId INTEGER NOT NULL,"
               "dateId INTEGER NOT NULL,"
               "FOREIGN KEY (personId) REFERENCES person(id),"
               "FOREIGN KEY (dateId) REFERENCES dueDay(id))");

    qDebug("database Created!");
    return true;

}

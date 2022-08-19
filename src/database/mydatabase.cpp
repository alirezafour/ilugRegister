#include "mydatabase.h"
#include <QDebug>
#include <QSqlError>

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

    if (!db.open()) {
        qDebug() << db.lastError().text();
        return false;
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
    if(!db.open())
    {
        qDebug() << db.lastError().text();
        return false;
    }
    QSqlQuery query;

    query.exec("CREATE TABLE dueDay ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
               "day DATE NOT NULL,"
               "dayNumber INTEGER,"
               "persianDay TEXT);");
    if(query.lastError().isValid())
    {
        qDebug() << query.lastError().text();
    }
    query.exec("CREATE TABLE person ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
               "code TEXT UNIQUE,"
               "firstName TEXT NOT NULL,"
               "lastName TEXT NOT NULL,"
               "sessionCounter INTEGER,"
               "email TEXT,"
               "registerDay TEXT);");
    if(query.lastError().isValid())
    {
        qDebug() << query.lastError().text();
    }
    query.exec("CREATE TABLE attendant ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
               "personId INTEGER NOT NULL,"
               "dueDayId INTEGER NOT NULL,"
               "FOREIGN KEY (personId) REFERENCES person(id),"
               "FOREIGN KEY (dueDayId) REFERENCES dueDay(id));");
    if(query.lastError().isValid())
    {
        qDebug() << query.lastError().text();
    }
    query.exec("CREATE VIEW attendant_view AS "
               "SELECT person.code AS code, person.firstName AS firstName, person.lastName AS lastName, dueDay.day AS day "
               "FROM person, dueDay, attendant "
               "WHERE atendant.personId = person.id AND attendant.dueDayId = dueDay.id;");
    if(query.lastError().isValid())
    {
        qDebug() << query.lastError().text();
    }

    qDebug("database Created!");
    return true;

}

bool MyDatabase::close()
{
    db.close();
    return true;
}

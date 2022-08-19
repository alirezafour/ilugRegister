#include "ilugapicontroller.h"

#include <QDebug>
#include <QSqlQuery>
#include <QPointer>

#include "src/database_export.h"

ILugApiController::ILugApiController(QObject *parent) : QObject(parent)
{
    curentDate = QDate::currentDate();
    curentDate_Str = curentDate.toString(Qt::ISODate);
}

bool ILugApiController::openDatabase()
{
    if(m_db.open())
        return true;
    return false;
}

//Find data From Database by Code Function
//**************
Person ILugApiController::findPersonByCode(const QString &code)
{
    return Person();
}

//Add data to Database Function
//**************
bool ILugApiController::addPerson(const Person &person)
{
    return true;
}

//this Function for Delete Data From person Table and folow Delete From attendant by Code
//*******************
bool ILugApiController::deletePerson(const QString &personCode)
{
    return true;
}

//this Function for Update data in Main tab
//*******************
bool ILugApiController::updatePerson(const Person &person)
{
    return true;
}

//this function for export date in date line to text file
//******************************
bool ILugApiController::exportToTextByDate(const QString &date, bool toDocu)
{
    QSqlQuery query;
    query.exec("SELECT firstName, lastName FROM dueDay, person, attendant"
               " WHERE dueDay.id == attendant.dateId and"
               " person.id == attendant.personId and"
               " dueDay.date == '"+ date + "';");
    if(!(query.lastError().text() == " "))
    {
        qDebug() << query.lastError().text();
        return false;
    }

    QString location = "Export/";
    if(toDocu)
    {
        location = location + "DucoWiki " + date + ".txt";
    }
    else
    {
        location = location + date + ".txt";
    }

    database_Export dbExport;
    if(!dbExport.openFile(location))
    {
        qDebug() << "Failed to open File";
        return false;
    }
    while(query.next())
    {
        QString firstName = query.value(0).toString();
        QString lastName = query.value(1).toString();
        if(toDocu)
        {
            dbExport.docuExport(firstName, lastName);
        }
        else
        {
            dbExport.insertToFile(firstName , lastName);
        }
    }
    dbExport.closeFile();
    return true;
}

//this function for searching name in database and show to table in search tab
//****************************
bool ILugApiController::searchPersonByFirstName(const QString &firstName, QSqlTableModel *model)
{
    return true;
}

//this function for searching family in database and show to table in search tab
//***********************************
bool ILugApiController::searchPersonByLastName(const QString &lastName, QSqlTableModel *model)
{
    return true;
}

bool ILugApiController::countForElection(const QString &code, QSqlQueryModel *model)
{
    int count = 0; //count the number of session he/she was present
    QSqlQuery query;    //query
    QSqlQuery query2;   //query
    QString date;
    query.exec("SELECT date FROM dueDay ORDER BY date(Date) DESC Limit 15");
    while(query.next())
    {
        date = query.value(0).toString();
    }
    qDebug() << date;

    query2.exec("select firstName, lastName, dueDay.date "
                "From person, dueDay, attendant "
                "WHERE attendant.personId = person.id "
                  "and attendant.dateId = dueDay.id "
                  "and code = " + code + " "
                  "AND date(date) >= '" + date + "';");

    while(query2.next())
    {
        count++;
    }
    model->setQuery(std::move(query2));
    if(count >= 10)
    {
        return true;
    }
    return false;
}

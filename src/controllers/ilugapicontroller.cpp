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
    else
        return false;
}

//Find data From Database by Code Function
//**************
Person ILugApiController::findPersonByCode(const QString &code)
{
    PersonModel personModel; //= std::make_unique<PersonModel>();
    personModel.setHeaders();
    if(int row = personModel.findPersonAndIncreaseSection(code) < 0)
    {
        qDebug() << "row didn't found " << row << "\n";
        personModel.revertAll();
        return Person();
    }

    QSqlRecord record = personModel.record(0);
    QString name = record.value(QString("firstName")).toString();
    QString family = record.value(QString("lastName")).toString();
    QString email = record.value(QString("email")).toString();

    Person person;
    person.setFirstName(name);
    person.setLastName(family);
    person.setEmail(email);

    std::unique_ptr<QSqlTableModel> modelD = std::make_unique<QSqlTableModel>();
    std::unique_ptr<QSqlTableModel> modelA = std::make_unique<QSqlTableModel>();

    m_dueDayModel.setModel(modelD);
    m_dueDayModel.addNewDay(modelD, curentDate_Str);

    modelD->submitAll();
    m_attendantModel.setModel(modelA);

    if(!m_attendantModel.addAttendant(modelA, code, curentDate_Str))
    {
        qDebug() << "attendant not added (from Controller)";

        //undo changes
        modelA->revertAll();
        modelD->revertAll();
        return person;
    }

    m_db.dbTransaction();
    //save changes
    modelA->submitAll();
    modelP->submitAll();
    m_db.dbCommit();

    return person;
}

//Add data to Database Function
//**************
bool ILugApiController::addPerson(const Person &person)
{
    QString code = person.getCode();
    QString firstName = person.getFirstName();
    QString lastName = person.getLastName();
    QString email = person.getEmail();


    //check fileds is empty make error
    if(code=="" || firstName=="" || lastName=="") return false;

    //find the person in database
    QPointer<QSqlTableModel> model = new QSqlTableModel();
    m_personModel.setHeaders(model);
    bool isAdded = m_personModel.addPerson(model, code, firstName, lastName, email);
    if(!isAdded)
    {
        qDebug() << "person Not added (from Controller)";
        model->revertAll();
        return false;
    }
    model->submitAll();
    return true;
}

//this Function for Delete Data From person Table and folow Delete From attendant by Code
//*******************
bool ILugApiController::deletePerson(const QString &personCode)
{
    //make error is code field is empty
    if(personCode.isEmpty()) return false;

    //delete person data from 2 table of database
    QPointer<QSqlTableModel> modelP = new QSqlTableModel();
    m_personModel.setHeaders(modelP);
    bool isDeleted = m_personModel.deletePerson(modelP, personCode);
    if(!isDeleted)
    {
        qDebug() << "delete person failed (from Controller)";
        modelP->revertAll();
        delete modelP;
        return false;
    }

    //WARNING: we delete attendant data too
    QPointer<QSqlTableModel> modelA = new QSqlTableModel();
    m_attendantModel.setModel(modelA);
    isDeleted = m_attendantModel.deleteAttendant(modelA, personCode);
    if(!isDeleted)
    {
        qDebug() << "delete attendent failed (from Controller)";
        modelA->revertAll();
        modelP->revertAll();
        return false;
    }
    m_db.dbTransaction();
    modelA->submitAll();
    modelP->submitAll();
    m_db.dbCommit();
    return true;
}

//this Function for Update data in Main tab
//*******************
bool ILugApiController::updatePerson(const Person &person)
{
    //make error is code, name or family is empty
    if(person.getCode().isEmpty() || person.getFirstName().isEmpty() || person.getLastName().isEmpty()) return false;

    //update person table data
    QPointer<QSqlTableModel> modelP = new QSqlTableModel();
    m_personModel.setHeaders(modelP);
    m_personModel.findPerson(modelP, person.getCode(), "");
    bool isUpdated = m_personModel.updatePerson(modelP, person.getCode(), person.getFirstName(), person.getLastName(), person.getEmail());
    if(!isUpdated)
    {
        qDebug() << "update person failed (from Controller)";
        modelP->revertAll();
        return false;
    }
    modelP->submitAll();
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
    QString filter = "firstName LIKE '%" + firstName + "%'";
    m_personModel.setHeaders(model);
    model->setFilter(filter);
    return true;
}

//this function for searching family in database and show to table in search tab
//***********************************
bool ILugApiController::searchPersonByLastName(const QString &lastName, QSqlTableModel *model)
{
    QString filter = "lastName LIKE '%" + lastName + "%'";
    m_personModel.setHeaders(model);
    model->setFilter(filter);
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
    model->setQuery(query2);
    if(count >= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

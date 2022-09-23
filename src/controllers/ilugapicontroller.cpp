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
    if(!m_db.open())
        return false;

    m_PersonModel = std::make_unique<PersonModel>();
    m_PersonModel->setHeaders();

    m_AttendantModel = std::make_unique<AttendantModel>();
    m_AttendantModel->setHeaders();

    m_DueDayModel = std::make_unique<DueDayModel>();
    m_DueDayModel->setHeaders();

    return true;
}

//Find data From Database by Code Function
//**************
Person ILugApiController::findPersonByCode(const QString &code)
{
    int row = m_PersonModel->findPerson(code);
    if(row == -1)
    {
        return Person();
    }

    QSqlRecord record = m_PersonModel->record(row);
    QString name = record.value(QString("firstName")).toString();
    QString lastname = record.value(QString("lastName")).toString();
    QString email = record.value(QString("email")).toString();

    Person person;
    person.setFirstName(name);
    person.setLastName(lastname);
    person.setEmail(email);

    int id = m_DueDayModel->addNewDay();
    m_DueDayModel->submitAll();

    if(!m_AttendantModel->addAttendant(code.toInt(), id))
    {
        m_AttendantModel->revertAll();
    }
    else
    {
        if (m_PersonModel->addSessionCount(code))
        {
            m_AttendantModel->submitAll();
            m_PersonModel->submitAll();
            m_db.dbCommit();
        }
        else
        {
            m_AttendantModel->revertAll();
            m_PersonModel->revertAll();
        }
    }

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
    if(code.toInt() == 0 || firstName == "" || lastName == "")
        return false;
    if(!m_PersonModel->addPerson(code, firstName, lastName, email)) // if return -1 means it failed
    {
        qDebug() << "failed to add person.";
        m_PersonModel->revertAll();
        return false;
    }
    m_PersonModel->submitAll();
    m_db.dbCommit();

    return true;
}

//this Function for Delete Data From person Table and folow Delete From attendant by Code
//*******************
bool ILugApiController::deletePerson(const QString &personCode)
{
    if(personCode.isEmpty())
        return false;

    if(!m_PersonModel->deletePerson(personCode))
    {
        m_PersonModel->revertAll();
        return false;
    }
    if(!m_AttendantModel->deleteAttendant(personCode.toInt()))
    {
        m_PersonModel->revertAll();
        m_AttendantModel->revertAll();
        qDebug() << "Failed to delete person\n";
        return false;
    }

    m_PersonModel->submitAll();
    m_AttendantModel->submitAll();
    m_db.dbCommit();
    return true;
}

//this Function for Update data in Main tab
//*******************
bool ILugApiController::updatePerson(const Person &person)
{
    //make error is code, name or family is empty
    if(person.getCode().isEmpty() || person.getFirstName().isEmpty() || person.getLastName().isEmpty())
        return false;
    if(!m_PersonModel->updatePerson(person.getCode(), person.getFirstName(), person.getLastName(), person.getEmail()))
    {
        m_PersonModel->revertAll();
        return false;
    }

    m_PersonModel->submitAll();
    m_db.dbCommit();
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
bool ILugApiController::searchPersonByFirstName(const QString& firstName)
{
    if(m_PersonModel->findPersonByName(firstName) != -1)
        return true;
    return false;
}

//this function for searching family in database and show to table in search tab
//***********************************
bool ILugApiController::searchPersonByLastName(const QString& lastName)
{
	if (m_PersonModel->findPersonByName("", lastName) != -1)
		return true;
	return false;
}

bool ILugApiController::countForElection(const QString& code)
{
    // if -1 means couldn't find that person
    int count = m_PersonModel->getSessionCount(code);
    
    if(count >= m_MinimumSessionForVote)
    {
        return true;
    }
    return false;
}

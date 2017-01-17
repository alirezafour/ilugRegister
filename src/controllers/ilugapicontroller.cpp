#include "ilugapicontroller.h"
#include <QDebug>
#include "src/database_export.h"

ILugApiController::ILugApiController(QObject *parent) : QObject(parent)
{
    curentDate = QDate::currentDate();
    curentDate_Str = curentDate.toString(Qt::ISODate);
}

//Find data From Database by Code Function
//**************
Person ILugApiController::findPersonByCode(const QString &code)
{
    QSqlTableModel * modelD = new QSqlTableModel();
    QSqlTableModel * modelA = new QSqlTableModel();

    bool isAdded = false;

    m_dueDayModel.setModel(modelD);
    isAdded = m_dueDayModel.addNewDay(modelD, curentDate_Str);

    modelD->submitAll();
    m_attendantModel.setModel(modelA);
    isAdded = m_attendantModel.addAttendant(modelA, code, curentDate_Str);



    if(!isAdded)
    {
        qDebug() << "attendant not added (from Controller)";

        //undo changes
        modelA->revertAll();
        modelD->revertAll();
        delete modelA;
        delete modelD;
        return Person();
    }
    QSqlTableModel * modelP = new QSqlTableModel();
    m_personModel.setModel(modelP);
    bool isFinded = m_personModel.findPerson(modelP, code);
    if(!isFinded)
    {
        qDebug() << "person Find problem (from Controller)";

        //undo changes
        modelA->revertAll();
        modelP->revertAll();
        delete modelA;
        delete modelD;
        delete modelP;
        return Person();
    }
    m_db.dbTransaction();
    //save changes
    modelA->submitAll();
    modelP->submitAll();
    m_db.dbCommit();


    QSqlRecord record = modelP->record(0);
    QString name = record.value(QString("firstName")).toString();
    QString family = record.value(QString("lastName")).toString();
    QString email = record.value(QString("email")).toString();

    Person person;
    person.setFirstName(name);
    person.setLastName(family);
    person.setEmail(email);

    delete modelA;
    delete modelD;
    delete modelP;
    return person;
}

//Add data to Database Function
//**************
bool ILugApiController::addPerson(const Person &person)
{
    QString code = person.code();
    QString firstName = person.firstName();
    QString lastName = person.lastName();
    QString email = person.email();


    //check fileds is empty make error
    if(code==0 || firstName=="" || lastName=="") return false;

    //find the person in database
    QSqlTableModel *model = new QSqlTableModel();
    m_personModel.setModel(model);
    bool isAdded = m_personModel.addPerson(model, code, firstName, lastName, email);
    if(!isAdded)
    {
        qDebug() << "person Not added (from Controller)";
        model->revertAll();
        delete model;
        return false;
    }
    model->submitAll();
    delete model;
    return true;
}

//this Function for Delete Data From person Table and folow Delete From attendant by Code
//*******************
bool ILugApiController::deletePerson(const QString &personCode)
{
    //make error is code field is empty
    if(personCode.isEmpty()) return false;

    //delete person data from 2 table of database
    QSqlTableModel *modelP = new QSqlTableModel();
    m_personModel.setModel(modelP);
    bool isDeleted = m_personModel.deletePerson(modelP, personCode);
    if(!isDeleted)
    {
        qDebug() << "delete person failed (from Controller)";
        modelP->revertAll();
        delete modelP;
        return false;
    }

    //WARNING: we delete attendant data too
    QSqlTableModel *modelA = new QSqlTableModel();
    m_attendantModel.setModel(modelA);
    isDeleted = m_attendantModel.deleteAttendant(modelA, personCode);
    if(!isDeleted)
    {
        qDebug() << "delete attendent failed (from Controller)";
        modelA->revertAll();
        modelP->revertAll();
        delete modelA;
        delete modelP;
        return false;
    }
    m_db.dbTransaction();
    modelA->submitAll();
    modelP->submitAll();
    m_db.dbCommit();
    delete modelA;
    delete modelP;
    return true;
}

//this Function for Update data in Main tab
//*******************
bool ILugApiController::updatePerson(const Person &person)
{
    //make error is code, name or family is empty
    if(person.code().isEmpty() || person.firstName().isEmpty() || person.lastName().isEmpty()) return false;

    //update person table data
    QSqlTableModel *modelP = new QSqlTableModel();
    m_personModel.setModel(modelP);
    m_personModel.findPerson(modelP, person.code(), "");
    bool isUpdated = m_personModel.updatePerson(modelP, person.code(), person.firstName(), person.lastName(), person.email());
    if(!isUpdated)
    {
        qDebug() << "update person failed (from Controller)";
        modelP->revertAll();
        delete modelP;
        return false;
    }
    modelP->submitAll();
    delete modelP;
    return true;
}

//this function for export date in date line to text file
//******************************
bool ILugApiController::exportToTextByDate(const QString &date)
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

    database_Export dbExport;
    if(!dbExport.openFile("Export/" + date + ".txt"))
    {
        qDebug() << "Failed to open File";
        return false;
    }
    while(query.next())
    {
        QString firstName = query.value(0).toString();
        QString lastName = query.value(1).toString();
        dbExport.insertToFile(firstName , lastName);
    }
    dbExport.closeFile();
    return true;
}

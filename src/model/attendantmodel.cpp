#include "attendantmodel.h"
#include <QDebug>

AttendantModel::AttendantModel(QObject *parent) : QObject(parent)
{

}

bool AttendantModel::setModel(QSqlTableModel *model)
{
    model->clear();

    model->setTable("attendant");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(0, Qt::Horizontal, tr("Person ID"));
    model->setHeaderData(0, Qt::Horizontal, tr("Date ID"));
    return true;
}

bool AttendantModel::addAttendant(QSqlTableModel *model, QString personCode, QString date)
{
    int personID = personModel.personID(personCode);
    if (personID == 0)
    {
        qDebug() << "person code not finded.";
        return false; // if not finded
    }

    int dateID = dateModel.dateID(date);
    if( dateID == 0)
    {
        qDebug() << "date not finded.";
        return false;  //if not finded
    }

    if(this->findAttendant(model, personID, dateID))
    {
        qDebug() << "attendant already exist.";
        return false;
    }

    QSqlRecord record = model->record();
    record.setValue(QString("personId"), QVariant(personID));
    record.setValue(QString("dateId"), QVariant(dateID));
    qDebug() << record.value(0);

    if(model->insertRecord(-1, record))
    {
        qDebug("Record Inserted!");
    }
    else
    {
        qDebug("Inserting record failed!");
        qDebug() << model->lastError().text();
        return false;
    }
    return true;
}

bool AttendantModel::deleteAttendant(QSqlTableModel *model, QString personCode)
{
    int personID = personModel.personID(personCode);
    if(personID == 0)
    {
        qDebug() << "person Id does not exist.";
        return false;
    }
    if(!this->findAttendant(model, personID, 0))
    {
        qDebug() << "person Id not find in attendant.";
        return false;
    }

    for(int i = 0; i < model->rowCount(); i++)
    {
        if(!model->removeRow(i))
        {
            qDebug() << "delete row in attendant make an Error: ";
            qDebug() << model->lastError().text();
            return false;
        }
    }
    return true;
}

bool AttendantModel::findAttendant(QSqlTableModel *model, int personId, int dueDayId)
{
    QString filter = createFilters(personId, dueDayId);
    qDebug() << filter;
    if(filter.isEmpty())
    {
        qDebug("No filter seted for method!");
        return false;
    }
    model->setFilter(filter);
    qDebug("Filter seted for model!");
    model->select();
    if(model->rowCount() == 0)
    {
        qDebug() << "no row find in attendant table";
        return false;
    }
    return true;
}

bool AttendantModel::findAttendant(QSqlTableModel *model, QString personCode, QString date)
{
    int personID = personModel.personID(personCode);
    int dateID = dateModel.dateID(date);
    if (personID == 0 && dateID == 0)
    {
        qDebug() << "person ID and date ID not finded.";
        return false; // if not finded
    }

    if(this->findAttendant(model, personID, dateID))
    {
        qDebug() << "attendant record finded.";
        return true;
    }
    else
    {
        return false;
    }
}

QString AttendantModel::createFilters(int personId, int dueDayId)
{
    QString filter;
    QStringList filterList;
    if(personId != 0)
    {
        filterList.append(QString("personId = %1").arg(personId));
    }
    if(dueDayId != 0)
    {
        filterList.append(QString("dateId = %1").arg(dueDayId));
    }

    if(filterList.isEmpty())
    {
        return 0;  //if all data was empty
    }
    else
    {
        filter = filterList.join(" and ");
        return filter;
    }
}


#include "attendantmodel.h"
#include <QDebug>

AttendantModel::AttendantModel(QObject *parent) : QSqlTableModel(parent)
{

}

AttendantModel::~AttendantModel()
{

}

void AttendantModel::setHeaders()
{
    this->clear();

    this->setTable("attendant");
    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->select();
    this->setHeaderData(0, Qt::Horizontal, tr("id"));
    this->setHeaderData(1, Qt::Horizontal, tr("personId"));
    this->setHeaderData(2, Qt::Horizontal, tr("dueDayId"));
}

int AttendantModel::findAttendant(int id)
{
    for(int i = 0; i < this->rowCount(); ++i)
    {
        int inId = this->record(i).value("id").toInt();
        if(id == inId)
        {
            return i;
        }
    }
    return -1;
}

int AttendantModel::findAttendant(int personId, int dueDayId)
{
    for(int i = 0; i < this->rowCount(); ++i)
    {
        int inPersonId = this->record(i).value("personId").toInt();
        int inDueDayId = this->record(i).value("dueDayId").toInt();
        if((personId == inPersonId) && (dueDayId == inDueDayId))
        {
            return i;
        }
    }
    return -1;
}

bool AttendantModel::addAttendant(int personId, int dueDayId)
{
    int row = findAttendant(personId, dueDayId);
    if( row != -1)
    {
        if(this->lastError().isValid())
            qDebug() << this->lastError().text();
        else
            qDebug() << "Error to add attendant.";
        return false;
    }
    QSqlRecord record = this->record();
    record.setValue(QString("personId"), QVariant(personId));
    record.setValue(QString("dueDayId"), QVariant(dueDayId));
    if(this->insertRecord(-1, record))
    {
        return true;
    }
    else
    {
        if(this->lastError().isValid())
            qDebug() <<  this->lastError().text();
        else
            qDebug() << "Insert record to attendant failed.";
        return false;
    }
}

bool AttendantModel::deleteAttendant(int personId, int dueDayId)
{
    int row = this->findAttendant(personId, dueDayId);
    if(row == -1)
    {
        qDebug() << "Failed to find attendant with personId = " << personId << " and dueDayId = " << dueDayId << ".";
        return false;
    }
    if(this->removeRow(row))
    {
        return true;
    }
    else
    {
        if(this->lastError().isValid())
        {
            qDebug() << this->lastError().text();
        }
        else
        {
            qDebug() << "Failed to delete attendant data.";
        }
        return false;
    }
}

bool AttendantModel::deleteAttendant(int personId)
{
    bool found = false;
    for(int i = 0; i < this->rowCount(); ++i)
    {
        int inPersonId = record(i).value("personId").toInt();
        if(personId == inPersonId)
        {
            found = true;
            removeRow(i);
        }
    }
    return found;
}

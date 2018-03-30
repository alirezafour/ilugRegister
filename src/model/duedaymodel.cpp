#include "duedaymodel.h"
#include <QDebug>

DueDayModel::DueDayModel(QObject *parent) : QSqlTableModel(parent)
{

}

DueDayModel::~DueDayModel()
{

}

void DueDayModel::setHeaders()
{
    this->clear();

    this->setTable("dueDay");
    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->select();
    this->setHeaderData(0, Qt::Horizontal, tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, tr("Day"));
    this->setHeaderData(2, Qt::Horizontal, tr("Day Number"));
    this->setHeaderData(3, Qt::Horizontal, tr("Persian Day"));
}

int DueDayModel::findDueDay(const QString &day) const
{
    for(int i = 0; i < this->rowCount(); ++i)
    {
        const QString &inDay = this->record(i).value("day").toString();
        if(day == inDay)
        {
            return i;
        }
    }
    //if it didn't find the they it return -1
    return -1;
}

int DueDayModel::addNewDay(const QString &day, const QString &dayNumber, const QString &persianDay)
{
    //check day exist or not
    int row = this->findDueDay(day);
    if(row != -1)
    {
        if(this->lastError().isValid())
            qDebug() << this->lastError().text();
        else
            qDebug() << "Error adding new day : " << day;
        return row;
    }

    //if day is not exist add new day
    QSqlRecord record = this->record();
    record.setValue(QString("day"), QVariant(day));
    record.setValue(QString("dayNumber"), dayNumber);
    record.setValue(QString("persianDay"), persianDay);
    if(this->insertRecord(-1, record))
    {
        return this->rowCount() - 1;
    }
    else
    {
        if(this->lastError().isValid())
            qDebug() <<  this->lastError().text();
        else
            qDebug() << "Insert record to dueDay failed.";
        return row;
    }
}

bool DueDayModel::deleteDueDay(const QString &day, const QString &dayNumber, const QString &persianDay)
{
    int row = this->findDueDay(day);
    if(row == -1)
    {
        qDebug() << "failed to find dueDay = " << day << " for deleting.";
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
            qDebug() << "Failed to delete row " << row << " to delete in dueDay.";
        }
    }
    return false;
}

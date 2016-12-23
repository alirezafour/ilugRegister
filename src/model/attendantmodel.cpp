#include "attendantmodel.h"
#include <QDebug>

AttendantModel::AttendantModel(QObject *parent) : QObject(parent)
{

}

bool AttendantModel::setModel(QSqlTableModel *model)
{
    model->clear();

    model->setTable("attendant");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
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

    QSqlRecord record = model->record();
    record.setValue(QString("personId"), QVariant(personID));
    record.setValue(QString("dateId"), QVariant(dateID));

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


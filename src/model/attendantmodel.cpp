#include "attendantmodel.h"


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
    QString personID = personModel.personID(personCode);
    QString dateID = dateModel.dateID(date);

    //TODO : fix me (complete me)

    return true;
}


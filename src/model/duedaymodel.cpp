#include "duedaymodel.h"
#include <QDebug>

DueDayModel::DueDayModel(QObject *parent) : QObject(parent)
{
    m_date = QDate::currentDate().toString(Qt::ISODate);

}

bool DueDayModel::setModel(QSqlTableModel *model)
{
    model->setTable("dueDay");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    return true;
}

void DueDayModel::setDate(QString &date)
{
    m_date = date;
}

bool DueDayModel::findDate(QSqlTableModel *model, QString date)
{
    QString filter = createFilter(date);
    if(filter.isEmpty())
    {
        qDebug("No filter seted for method!");
        return false;
    }
    model->setFilter(filter);
    model->select();
    qDebug("filter set to model!");
    return true;
}

bool DueDayModel::addNewDay(QSqlTableModel *model, QString date)
{
    //check day exist or not
    if(this->findDate(model, date))
    {
        qDebug() << "Day Exist.";
        return false;
    }

    //if day is not exist add new day
    QSqlRecord record = model->record();
    record.setValue(QString("date"), QVariant(date));

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

int DueDayModel::dateID(QString &date)
{
    int result;
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("dueDay");
    QString filter = createFilter(date);
    if(filter.isEmpty())
    {
        qDebug("No filter seted for method!");
        return 0;
    }
    model->setFilter(filter);
    model->select();
    QSqlRecord record = model->record(0);
    result = record.value(QString("id")).toInt();
    return result;
}

QString DueDayModel::createFilter(QString &date)
{
    QString filter;
    if(!date.isEmpty())
    {
        filter = QString("date = '%1'").arg(date);
    }
    return filter;
}

QString DueDayModel::date() const
{
    return m_date;
}

#include "duedaymodel.h"

DueDayModel::DueDayModel(QObject *parent) : QObject(parent)
{

}

bool DueDayModel::setModel(QSqlTableModel *model)
{
    model->setTable("dueDay");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    return true;
}

bool DueDayModel::setDate(QSqlTableModel *model, QString &date)
{
    this->m_date = new QDate::s
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

QString DueDayModel::createFilter(QString &date)
{
    QString filter;
    if(!date.isEmpty())
    {
        filter = QString("date = '%1'").arg(date);
    }
    return filter;
}

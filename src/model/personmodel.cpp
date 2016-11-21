#include "personmodel.h"
#include <QDebug>

PersonModel::PersonModel(QObject *parent) : QObject(parent)
{

}

PersonModel::~PersonModel()
{

}

void PersonModel::setModel(QSqlTableModel *model)
{
    model->clear();

    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Code"));
    model->setHeaderData(2, Qt::Horizontal, tr("First Name"));
    model->setHeaderData(3, Qt::Horizontal, tr("Last Name"));
    model->setHeaderData(4, Qt::Horizontal, tr("Sesstion Counter"));
    model->setHeaderData(5, Qt::Horizontal, tr("Email"));
}

bool PersonModel::findPerson(QSqlTableModel *model, QString code)
{
    this->findPerson(model, code, "", "", "");
    QSqlRecord record = model->record(0);
    int value = record.value(QString("sessionCounter")).toInt();
    value++;
    record.setValue(QString("sessionCounter"), QVariant(value));
    if(model->setRecord(0,record))
    {
        qDebug("Record session counter Updated!");
    }
    else
    {
        qDebug() << model->lastError().text();
        qDebug("Inserting record failed!");
        return false;
    }
    return true;
}

bool PersonModel::findPerson(QSqlTableModel *model, QString code, QString name,
                             QString family, QString email)
{
    QString filter = createFilters(code, name, family, email);
    if(filter == "")
    {
        qDebug("No filter seted for method!");
        return false;
    }
    model->setFilter(filter);
    qDebug("Filter seted for model!");
    model->select();
    return true;
}

bool PersonModel::addPerson(QSqlTableModel *model, QString code, QString name,
                            QString family, QString email)
{
    QSqlRecord record = model->record();
    record.setValue(QString("code"), QVariant(code));
    record.setValue(QString("firstName"), QVariant(name));
    record.setValue(QString("lastName"), QVariant(family));
    record.setValue(QString("sessionCounter"), QVariant(0));
    record.setValue(QString("email"), QVariant(email));
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


bool PersonModel::deletePerson(QSqlTableModel *model, QString code)
{
    this->findPerson(model, code);
    if(model->removeRow(0))
    {
        qDebug() << code + " deleted!";
    }
    else
    {
        qDebug("Can't delete row 0!");
        return false;
    }
    return true;
}


bool PersonModel::deletePerson(QSqlTableModel *model, QString name, QString family)
{
    this->findPerson(model, "", name, family);
    if(model->removeRow(0))
    {
        qDebug() << name + " " + family + " deleted!";

    }
    else
    {
        qDebug("Can't delete row 0!");
        return false;
    }
    return true;
}

bool PersonModel::updatePerson(QSqlTableModel *model, QString code, QString name, QString family, QString email)
{
    qDebug() << " value is : "<< model->record(0).value(2);

    QSqlRecord record = model->record(0);
    this->createRecord(&record, code, name, family, email);
    qDebug() << " record value is : "<< record.value(2);
    if(model->setRecord(0, record))
    {
        qDebug("record updated!");
    }
    else
    {
        qDebug("ERROR");
        qDebug() << model->lastError().text();
        qDebug("record not updated in updatePerson");
        return false;
    }
    return true;
}



QString PersonModel::createFilters(QString code, QString name, QString family, QString email)
{
    QString filter;
    QStringList filterList;
    if(code != "")
    {
        code = QString("code = '%1'").arg(code);
        filterList.append(code);
    }
    if(name != "")
    {
        name = QString("firstName = '%1'").arg(name);
        filterList.append(name);
    }
    if(family != "")
    {
        family = QString("lastName = '%1'").arg(family);
        filterList.append(family);
    }
    if(email != "")
    {
        email = QString("email = '%1'").arg(email);
        filterList.append(email);
    }
    if(filterList.isEmpty())
    {
        return "";  //if all data was empty
    }
    else
    {
        filter = filterList.join(" and ");
        return filter;
    }
}



void PersonModel::createRecord(QSqlRecord *record, QString code, QString name, QString family, QString email)
{
    if(!code.isEmpty())
    {
        record->setValue(QString("code"), QVariant(code));
    }
    if(!name.isEmpty())
    {
        record->setValue(QString("firstName"), QVariant(name));
    }
    if(!family.isEmpty())
    {
        record->setValue(QString("lastName"), QVariant(family));
    }
    if(!email.isEmpty())
    {
        record->setValue(QString("email"), QVariant(email));
    }
}

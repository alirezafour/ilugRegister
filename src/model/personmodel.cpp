#include "personmodel.h"

PersonModel::PersonModel(QObject *parent) : QSqlTableModel(parent)
{

}

PersonModel::~PersonModel()
{

}

void PersonModel::setHeaders()
{
    this->clear();

    this->setTable("person");
    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->select();
    this->setHeaderData(0, Qt::Horizontal, tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, tr("Code"));
    this->setHeaderData(2, Qt::Horizontal, tr("First Name"));
    this->setHeaderData(3, Qt::Horizontal, tr("Last Name"));
    this->setHeaderData(4, Qt::Horizontal, tr("Sesstion Counter"));
    this->setHeaderData(5, Qt::Horizontal, tr("Email"));
}

int PersonModel::findPersonAndIncreaseSection(const QString &code)
{
    int row = this->findPerson(code, 0, 0, 0);
    if(row == -1)
    {
        return row;
    }
    QSqlRecord record = this->record(row);
    int sc = record.value("sessionCounter").toInt();
    sc++;
    record.setValue("sessionCounter", QVariant(sc));
    if(!this->setRecord(row, record))
    {
        //throw something
        if(this->lastError().isValid())
            qDebug() << this->lastError().text();
        else
            qDebug() << "Error updating session counter in person table.";
        return row;
    }
    return row;
}

int PersonModel::findPerson(const QString &code, const QString &name,
                             const QString &family, const QString &email) const
{
    for(int i = 0; i < this->rowCount(); ++i)
    {
        const QString &inCode = record(i).value("code").toString();
        if(code == inCode)
        {
            return i;
        }
        else if(name.isEmpty() && family.isEmpty() && email.isEmpty())
        {
            continue;
        }
        const QString &inName = record(i).value("firstName").toString();
        const QString &inFamily = record(i).value("lastName").toString();
        const QString &inEmail = record(i).value("email").toString();
        if((name.isEmpty() || name == inName) && (family.isEmpty() || family == inFamily) && (email.isEmpty() || email == inEmail))
        {
            return i;
        }
    }
    return -1;
}

int PersonModel::addPerson(const QString &code, const QString &name,
                            const QString &family, const QString &email)
{
    int row = findPersonAndIncreaseSection(code);
    if(row != -1)
    {
        if(lastError().isValid())
            qDebug() << lastError().text();
        else
            qDebug() << "Error to add person by code " << code;
        return row;
    }
    QSqlRecord record = this->record();
    record.setValue(QString("code"), QVariant(code));
    record.setValue(QString("firstName"), QVariant(name));
    record.setValue(QString("lastName"), QVariant(family));
    record.setValue(QString("sessionCounter"), QVariant(0));
    record.setValue(QString("email"), QVariant(email));
    record.setValue(QString("registerDay"), QDate::currentDate().toString(Qt::ISODate));
    if(insertRecord(-1, record))
    {
        return rowCount();
    }
    else
    {
        if(lastError().isValid())
            qDebug() <<  lastError().text();
        else
            qDebug() << "Insert record to person failed.";
        return row;
    }
}

bool PersonModel::deletePerson(const QString &code)
{
    int row = findPerson(code, 0);
    if(row == -1)
    {
        qDebug() << "Failed to find person with " << code << " for deleting it.";
        return false;
    }
    if(removeRow(row))
    {
        return true;
    }
    else
    {
        if(lastError().isValid())
            qDebug() << lastError().text();
        else
            qDebug() << "Failed to delete row " << row << " from person table.";
        return false;
    } 
}

bool PersonModel::deletePerson(const QString &name, const QString &family)
{
    int row = findPerson("", name, family);
    if(removeRow(row))
    {
        return true;
    }
    else
    {
        if(lastError().isValid())
            qDebug() << lastError().text();
        else
            qDebug() << "Failed to delete row " << row;
        return false;
    }
}

int PersonModel::personID(const QString &code) const
{
    for(int i = 0; i < rowCount(); ++i )
    {
        if(record(i).value("code").toString() == code)
            return record(i).value("id").toInt();
    }
    return -1;
}

bool PersonModel::updatePerson(const QString& code, const QString& firstName, const QString& lastName, const QString& email)
{
    int row = findPerson(code, 0);
    if(row == -1)
        return false;

    QSqlRecord record = this->record(row);
    record.setValue(QString("code"), QVariant(code));
    record.setValue(QString("firstName"), QVariant(firstName));
    record.setValue(QString("lastName"), QVariant(lastName));
    record.setValue(QString("email"), QVariant(email));

    return updateRowInTable(row, record);
}

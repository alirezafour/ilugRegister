#include "personmodel.h"

PersonModel::PersonModel(QObject *parent) 
    : QSqlTableModel(parent)
{

}

void PersonModel::setHeaders()
{
    clear();

    setTable("person");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    select();
    setHeaderData(0, Qt::Horizontal, tr("ID"));
    setHeaderData(1, Qt::Horizontal, tr("Code"));
    setHeaderData(2, Qt::Horizontal, tr("First Name"));
    setHeaderData(3, Qt::Horizontal, tr("Last Name"));
    setHeaderData(4, Qt::Horizontal, tr("Session Counter"));
    setHeaderData(5, Qt::Horizontal, tr("Email"));
}

bool PersonModel::addSessionCount(const QString& code)
{
    int row = findPerson(code);
    if(row == -1)
    {
        return false;
    }
    QSqlRecord sqlRecord = record(row);
    int sc = sqlRecord.value("sessionCounter").toInt();
    sc++;
    sqlRecord.setValue("sessionCounter", QVariant(sc));
    if(!setRecord(row, sqlRecord))
    {
        if(lastError().isValid())
            qDebug() << lastError().text();
        else
            qDebug() << "Error updating session counter in person table.";
        return false;
    }
    return true;
}

int PersonModel::findPerson(const QString& code, const QString& name,
                             const QString& family, const QString& email) const
{
    for(int i = 0; i < rowCount(); ++i)
    {
        const QString& inCode = record(i).value("code").toString();
        if(code == inCode)
        {
            return i;
        }
        else if(name.isEmpty() && family.isEmpty() && email.isEmpty())
        {
            continue;
        }
        const QString& inName = record(i).value("firstName").toString();
        const QString& inFamily = record(i).value("lastName").toString();
        const QString& inEmail = record(i).value("email").toString();
        if((name.isEmpty() || name == inName) && (family.isEmpty() || family == inFamily) && (email.isEmpty() || email == inEmail))
        {
            return i;
        }
    }
    return -1;
}

int PersonModel::findPersonByName(const QString& firstName, const QString& lastName /*= ""*/) const
{
	// if both set
	if (!firstName.isEmpty() && !lastName.isEmpty())
	{
		for (int i = 0; i < rowCount(); ++i)
		{
			const QString& inFirstName = record(i).value("firstName").toString();
			const QString& inLastName = record(i).value("lastName").toString();
			if (firstName == inFirstName && lastName == inLastName)
			{
				return i;
			}
		}
		return -1;
	}

	// if name set
	if (!firstName.isEmpty())
	{
		for (int i = 0; i < rowCount(); ++i)
		{
			const QString& inFirstName = record(i).value("firstName").toString();
			if (firstName == inFirstName)
			{
				return i;
			}
		}
		return -1;
	}

	// if last name set
	if (!lastName.isEmpty())
	{
		for (int i = 0; i < rowCount(); ++i)
		{
			const QString& inLastName = record(i).value("lastName").toString();
			if (lastName == inLastName)
			{
				return i;
			}
		}
		return -1;
	}

	// if nothing is set
	return -1;
}

bool PersonModel::addPerson(const QString &code, const QString &name,
                            const QString &family, const QString &email)
{
    if(findPerson(code) != -1)
    {
        qDebug() << "this person with " << code << " already exist.";
        return false;
    }
    QSqlRecord sqlRecord = record();
    sqlRecord.setValue(QString("code"), QVariant(code));
    sqlRecord.setValue(QString("firstName"), QVariant(name));
    sqlRecord.setValue(QString("lastName"), QVariant(family));
    sqlRecord.setValue(QString("sessionCounter"), QVariant(0));
    sqlRecord.setValue(QString("email"), QVariant(email));
    sqlRecord.setValue(QString("registerDay"), QDate::currentDate().toString(Qt::ISODate));
    if(insertRecord(-1, sqlRecord))
    {
        return true;
    }
    if(lastError().isValid())
            qDebug() <<  lastError().text();
    else
        qDebug() << "Insert record to person failed.";
    return false;
}

bool PersonModel::deletePerson(const QString &code)
{
    int row = findPerson(code);
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

int PersonModel::getPersonId(const QString &code) const
{
    for(int i = 0; i < rowCount(); ++i )
    {
        if(record(i).value("code").toString() == code)
            return record(i).value("id").toInt();
    }
    return -1;
}

int PersonModel::getSessionCount(const QString& code) const
{
    if (int row = findPerson(code); row != -1)
    {
        return record(row).value("sessionCounter").toInt();
    }
    return -1;
}

bool PersonModel::updatePerson(const QString& code, const QString& firstName, const QString& lastName, const QString& email)
{
    int row = findPerson(code);
    if(row == -1)
        return false;

    QSqlRecord sqlRecord = record(row);
    sqlRecord.setValue(QString("code"), QVariant(code));
    sqlRecord.setValue(QString("firstName"), QVariant(firstName));
    sqlRecord.setValue(QString("lastName"), QVariant(lastName));
    sqlRecord.setValue(QString("email"), QVariant(email));

    return updateRowInTable(row, sqlRecord);
}

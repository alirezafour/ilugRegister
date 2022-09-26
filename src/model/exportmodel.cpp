#include "exportmodel.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

ExportModel::ExportModel(QObject* parent /*= nullptr*/)
	: QSqlTableModel(parent)
{

}

void ExportModel::setHeaders()
{
	clear();

	QSqlQueryModel::setQuery("Select attendant.id, person.code, person.firstName, person.lastName, dueDay.day "
		"FROM person, dueDay "
		"INNER JOIN attendant "
		"ON attendant.personId = person.id "
		"AND dueDay.id = attendant.dueDayId;");

	if (lastError().isValid())
	{
		qDebug() << lastError().text();
	}

	select();
	setHeaderData(0, Qt::Horizontal, tr("Id"));
	setHeaderData(1, Qt::Horizontal, tr("Code"));
	setHeaderData(2, Qt::Horizontal, tr("First Name"));
	setHeaderData(3, Qt::Horizontal, tr("Last Name"));
	setHeaderData(4, Qt::Horizontal, tr("Day"));
}

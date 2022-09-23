#pragma once
#include <QSqlQueryModel>

class ExportModel : public QSqlQueryModel
{
public:
	ExportModel(QObject* parent = nullptr);
	void setHeaders();
};
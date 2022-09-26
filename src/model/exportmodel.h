#pragma once
#include <QSqlTableModel>

class ExportModel : public QSqlTableModel
{
public:
	ExportModel(QObject* parent = nullptr);
	void setHeaders();
};
#ifndef DATABASE_EXPORT_H
#define DATABASE_EXPORT_H

#include <QFile>
#include <stdio.h>
#include <QTextStream>
#include <QDebug>

class database_Export
{
public:
    database_Export();
    bool openFile(QString location);
    bool closeFile();
    bool insertToFile(QString name, QString Family);
    bool docuExport(int code, QString name, QString Family);

private:
    QFile file;
};

#endif // DATABASE_EXPORT_H

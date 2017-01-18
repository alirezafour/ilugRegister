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
    bool openFile(const QString &location);
    bool closeFile();
    bool insertToFile(const QString &name, const QString &family);
    bool docuExport(const QString &name, const QString &family);
    bool addToFile(const QString &text);

private:
    QFile file;
};

#endif // DATABASE_EXPORT_H

#include "database_export.h"

database_Export::database_Export()
{
}


bool database_Export::openFile(QString location)
{
    file.setFileName(location);
    if(file.open(QIODevice::ReadWrite))
    {
        file.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::WriteGroup|QFile::ExeGroup|QFile::ReadOther|QFile::WriteOther|QFile::ExeOther);
        return true;
    }
    else
        return false;
}

bool database_Export::closeFile()
{
    file.close();
    return true;
}

bool database_Export::insertToFile(QString name, QString Family)
{
    QString textLine;
    textLine = QString(name + " " + Family);
    QTextStream fileOut(&file);
    fileOut<< endl;
    fileOut<< textLine;
    return true;
}

bool database_Export::docuExport(int code, QString name, QString Family)
{
    QString textLine;
    if (code < 100 || code > 999)
        textLine = QString("[[صفحات شخصی:" + name + " " + Family + ":]]\\\\");
    else
        textLine = QString(name + " " + Family + "\\\\");
    QTextStream fileOut(&file);
    fileOut<< endl;
    fileOut<< textLine;
    return true;
}

bool database_Export::addToFile(QString text)
{
    file.seek(0);
    QTextStream fileOut(&file);
    fileOut<< text;
    fileOut<< endl;
    return true;
}


#include "src/database_export.h"

database_Export::database_Export()
{

}


bool database_Export::openFile(const QString &location)
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

bool database_Export::insertToFile(const QString &name, const QString &family)
{
    QString textLine;
    textLine = QString(name + " " + family);
    QTextStream fileOut(&file);
    fileOut<< "\n";
    fileOut<< textLine;
    return true;
}

bool database_Export::docuExport(const QString &name, const QString &family)
{
    QString textLine;
    //if he/she is not a new member he/she should have docuwiki link to his/her page.
    textLine = QString("[[صفحات شخصی:" + name + " " + family + ":]]\\\\");
    //textLine = QString(name + " " + family + "\\\\");
    QTextStream fileOut(&file);
    fileOut<< "\n";
    fileOut<< textLine;
    return true;
}

bool database_Export::addToFile(const QString &text)
{
    file.seek(0);
    QTextStream fileOut(&file);
    fileOut<< text;
    fileOut<< "\n";
    return true;
}


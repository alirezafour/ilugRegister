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

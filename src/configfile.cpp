#include "src/configfile.h"

ConfigFile::ConfigFile()
{

}

bool ConfigFile::openConfigFile(QString location)
{
    file.setFileName(location);

    if(!file.exists()) {
        file.setFileName(location);
        file.open(QIODevice::ReadWrite);
        file.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::WriteGroup|QFile::ExeGroup|QFile::ReadOther|QFile::WriteOther|QFile::ExeOther);
        QByteArray text = "last new user number = 100";
        file.write(text);
        return 0;
    }

    return 0;
}

void ConfigFile::closeConfigFile()
{
    file.close();
}

int ConfigFile::lastNewUserNumber()
{
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        if(line.startsWith("last new user number =")) {
            line.remove("last new user number = ");
        }
    }
    return line.toInt();
}
    void ConfigFile::addToLastNewUserNumber()
    {
        int num = lastNewUserNumber();
        QTextStream in(&file);
        num++;
        QString text("last new user number = " + num);
        in << endl << text;
        return;

    }

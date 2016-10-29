#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QFile>
#include <stdio.h>
#include <QTextStream>

class ConfigFile
{
private:
    QFile file;
public:
    ConfigFile();
    bool openConfigFile(QString location);
    void closeConfigFile();
    int lastNewUserNumber();
    void addToLastNewUserNumber();
};

#endif // CONFIGFILE_H

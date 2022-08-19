#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QSqlQuery>

class MyDatabase : public QObject
{
    Q_OBJECT
public:
    explicit MyDatabase(QObject *parent = 0);
    ~MyDatabase();
    bool open();
    void dbTransaction();
    void dbCommit();
    bool createDatabase(QString path);
    bool close();

signals:

public slots:
private:
    QSqlDatabase db;

};

#endif // MYDATABASE_H

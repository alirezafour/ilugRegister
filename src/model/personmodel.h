#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QSqlError>

class PersonModel : public QObject
{
    Q_OBJECT
public:
    explicit PersonModel(QObject *parent = 0);
    ~PersonModel();
    void setModel(QSqlTableModel *model);
    bool findPerson(QSqlTableModel *model, QString code);
    bool findPerson(QSqlTableModel *model, QString code, QString name,
                    QString family = "", QString email = "");
    bool addPerson(QSqlTableModel *model, QString code, QString name, QString family,
                   QString email);
    bool deletePerson(QSqlTableModel *model, QString code);

    bool deletePerson(QSqlTableModel *model, QString name, QString family);
    bool updatePerson(QSqlTableModel *model, QString code, QString name = "", QString family = "",
                      QString email = "");
    bool updatePerson(QSqlTableModel *model, int id);

signals:

public slots:
private:
    QString createFilters(QString code, QString name, QString family,
                          QString email);
    void createRecord(QSqlRecord *record, QString code, QString name, QString family,
                      QString email);

};

#endif // PERSONMODEL_H

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

signals:

public slots:
private:
    QString createFilters(QString code, QString name, QString family,
                          QString email);

};

#endif // PERSONMODEL_H

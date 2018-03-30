#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QDate>

class PersonModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit PersonModel(QObject *parent = 0);
    ~PersonModel();
    void setHeaders();
    int findPersonAndIncreaseSection(const QString &code);
    int findPerson(const QString &code, const QString &name,
                    const QString &family = "", const QString &email = "") const;
    int addPerson(const QString &code, const QString &name, const QString &family,
                   const QString &email);
    bool deletePerson(const QString &code);

    bool deletePerson(const QString &name, const QString &family);
    int updatePerson(const QString &code, const QString &name = "", const QString &family = "",
                      const QString &email = "");
    int personID(const QString &code) const;
};

#endif // PERSONMODEL_H

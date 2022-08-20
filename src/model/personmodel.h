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

    /**
     * @brief set table view headers name and model
     */
    void setHeaders();
    bool addSessionCount(const QString &code);

    /**
     * @brief find Person
     * @param string of Person code, name , family, email
     * @return row number that added if failed return -1
     */
    int findPerson(const QString &code, const QString &name = "",
                    const QString &family = "", const QString &email = "") const;
    bool addPerson(const QString &code, const QString &name, const QString &family,
                   const QString &email);
    bool deletePerson(const QString &code);
    bool deletePerson(const QString &name, const QString &family);
    bool updatePerson(const QString &code, const QString &name = "", const QString &family = "",
                      const QString &email = "");
    int personID(const QString &code) const;
};

#endif // PERSONMODEL_H

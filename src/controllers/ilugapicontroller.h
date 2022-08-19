#ifndef ILUGAPICONTROLLER_H
#define ILUGAPICONTROLLER_H

#include <QObject>
#include <QDate>

#include "src/model/duedaymodel.h"
#include "src/model/personmodel.h"
#include "src/model/attendantmodel.h"
#include "src/database/mydatabase.h"
#include "src/model/person.h"

class ILugApiController : public QObject
{
    Q_OBJECT
    MyDatabase m_db;
    AttendantModel m_attendantModel;
    PersonModel m_personModel;
    DueDayModel m_dueDayModel;
    QDate curentDate;
    QString curentDate_Str;
public:
    explicit ILugApiController(QObject *parent = 0);
    bool openDatabase();
    Person findPersonByCode(const QString &code);
    bool addPerson(const Person &person);
    bool deletePerson(const QString &personCode);
    bool updatePerson(const Person &person);
    bool exportToTextByDate(const QString &date, bool toDocu = false);
    bool searchPersonByFirstName(const QString &name, QSqlTableModel *model);
    bool searchPersonByLastName(const QString &lastName, QSqlTableModel *model);
    bool countForElection(const QString &code, QSqlQueryModel *model);

signals:

public slots:
};

#endif // ILUGAPICONTROLLER_H

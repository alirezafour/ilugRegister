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
public:
    explicit ILugApiController(QObject *parent = 0);
    bool openDatabase();
    Person findPersonByCode(const QString& code);
    bool addPerson(const Person& person);
    bool deletePerson(const QString& personCode);
    bool updatePerson(const Person& person);
    bool exportToTextByDate(const QString& date, bool toDocu = false);
    bool searchPersonByFirstName(const QString& name);
    bool searchPersonByLastName(const QString& lastName);
    bool countForElection(const QString& code);

    inline QSqlTableModel* GetPersonModel() const { return m_PersonModel.get(); }
    inline QSqlTableModel* GetAttendantModel() const { return m_AttendantModel.get(); }

signals:

public slots:
private:
    std::unique_ptr<PersonModel> m_PersonModel;
    std::unique_ptr<AttendantModel> m_AttendantModel;
    std::unique_ptr<DueDayModel> m_DueDayModel;
    MyDatabase m_db;
    QDate curentDate;
    QString curentDate_Str;
    int m_MinimumSessionForVote = 10;
};

#endif // ILUGAPICONTROLLER_H

#include <QObject>
#include <QtTest>
#include <QSqlTableModel>
#include <QFile>
#include "database/mydatabase.h"
#include "model/personmodel.h"
#include "model/duedaymodel.h"
#include "model/attendantmodel.h"

class TestLug : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();

    void testCase1();
    void databaseTest();
    void addPersonModel();
    void findPersonModel();
    void addPersonSession();
    void deletePersonModel();
    void addDayDueDayModel();
    void findDayDueDayModel();
    void deleteDayDUeDayModel();
    void addAttendantModel();
    void findAttendantModel();
    void deleteAttendantModel();

    void cleanupTestCase();

private:
    MyDatabase database;

    std::unique_ptr<PersonModel> personModel;
    std::unique_ptr<DueDayModel> dueDayModel;
    std::unique_ptr<AttendantModel> attendantModel;
};



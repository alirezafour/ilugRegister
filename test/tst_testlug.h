#include <QObject>
#include <QtTest>
#include <QSqlTableModel>
#include <QFile>
#include "../src/database/mydatabase.h"
#include "../src/model/personmodel.h"
#include "../src/model/duedaymodel.h"
#include "../src/model/attendantmodel.h"

class QTime;

class TestLug : public QObject
{
    Q_OBJECT

    MyDatabase database;

    std::unique_ptr<PersonModel> personModel;
    std::unique_ptr<DueDayModel> dueDayModel;
    std::unique_ptr<AttendantModel> attendantModel;
    //QTime myTimer;

public:
    TestLug();


private Q_SLOTS:
    void initTestCase();

    void testCase1();
    void databaseTest();
    void addPersonModel();
    void findPersonModel();
    void deletePersonModel();
    void addDayDueDayModel();
    void findDayDueDayModel();
    void deleteDayDUeDayModel();
    void addAttendantModel();
    void findAttendantModel();
    void deleteAttendantModel();

    void cleanupTestCase();

};



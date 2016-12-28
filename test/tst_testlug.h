#include <QObject>
#include <QtTest>
#include <QSqlTableModel>
#include "../src/database/mydatabase.h"
#include "../src/model/personmodel.h"
#include "../src/model/duedaymodel.h"
#include "../src/model/attendantmodel.h"

class QTime;

class TestLug : public QObject
{
    Q_OBJECT

    MyDatabase database;
    QSqlTableModel *model;
    PersonModel personModel;
    DueDayModel dueDayModel;
    AttendantModel attendantModel;
    QTime myTimer;

public:
    TestLug();


private Q_SLOTS:
    void testCase1();
    void databaseTest();
    void addPersonModel();
    void findPersonModel();
    void updatePersonModel();
    void deletePersonModel();
    void addDayDueDayModel();
    void findDayDueDayModel();
    void addAttendantModel();
    void findAttendantModel();
    void findAttendantModelByPersonCode();
    void findAttendantModelByDate();
    void deleteAttendantModelByPersonCode();

    void deleteDataBase();

};



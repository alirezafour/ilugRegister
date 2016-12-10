#include <QObject>
#include <QtTest>
#include <QSqlTableModel>
#include "../src/database/mydatabase.h"
#include "../src/model/personmodel.h"
#include "../src/model/duedaymodel.h"

class TestLug : public QObject
{
    Q_OBJECT

    MyDatabase database;
    QSqlTableModel *model;
    PersonModel personModel;
    DueDayModel dueDayModel;

public:
    TestLug();


private Q_SLOTS:
    void testCase1();
    void databaseTest();
    void addPersonModel();
    void findPersonModel();
    void updatePersonModel();
    void deletePersonModel();
    void findDayDueDayModel();
};



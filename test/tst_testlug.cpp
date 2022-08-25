#include "tst_testlug.h"

void TestLug::initTestCase()
{
    QFile::remove("lug.db");
}

void TestLug::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestLug::databaseTest()
{
    Q_ASSERT_X(database.open(), "opening database", "failed to open");

    personModel = std::make_unique<PersonModel>();
    personModel->setHeaders();

    attendantModel = std::make_unique<AttendantModel>();
    attendantModel->setHeaders();

    dueDayModel = std::make_unique<DueDayModel>();
    dueDayModel->setHeaders();

}

void TestLug::addPersonModel()
{
    bool result = personModel->addPerson("12222233", "alireza", "hor", "a2l22i2ael222i@lkfdj.com");

    QCOMPARE(0, result);
    personModel->submitAll();
    database.dbCommit();
}

void TestLug::findPersonModel()
{
    int row = personModel->findPerson("12222233");
    QCOMPARE(0, row);

    QString name = personModel->record(row).value("firstName").toString();
    QCOMPARE(name, QString("alireza"));

    QCOMPARE(true, personModel->addSessionCount("12222233"));
    personModel->submitAll();
    int count = personModel->record(row).value("sessionCount").toInt();
    QCOMPARE(count, 1);

}

void TestLug::deletePersonModel()
{
    Q_ASSERT_X(personModel->deletePerson("12222233"), "deleting person", "failed to delete person");
    personModel->submitAll();
}

void TestLug::addDayDueDayModel()
{
    int curRow = dueDayModel->addNewDay();
    QCOMPARE(curRow, 0);
    int row = dueDayModel->addNewDay("2014-12-12");
    QCOMPARE(row , 1);
    dueDayModel->submitAll();
}

void TestLug::findDayDueDayModel()
{
    dueDayModel->addNewDay("2016-12-12");
    dueDayModel->submitAll();

    int row = dueDayModel->findDueDay("2016-12-12");
    QCOMPARE(row, dueDayModel->rowCount() - 1);

}

void TestLug::deleteDayDUeDayModel()
{
    dueDayModel->addNewDay("2011-12-1");
    dueDayModel->submitAll();

    Q_ASSERT_X( dueDayModel->deleteDueDay("2011-12-1"), "day deleted.", "failed to delete day.");
}

void TestLug::addAttendantModel()
{
    // adding persons first
    int oldpRow = personModel->rowCount() - 1;
    int row = personModel->addPerson("1222234233", "a22lirezds2222a32", "hosgdfd222dsr", "a2lw22i2ael222i@lkfdj.com");
    QCOMPARE(oldpRow+1, row);
    personModel->submitAll();

    //adding a dueDay
    int oldRow = dueDayModel->rowCount() - 1;
    int newRow = dueDayModel->addNewDay("2017-12-22");
    QCOMPARE(oldRow+1, newRow);
    dueDayModel->submitAll();

    int personId = personModel->record(0).value("id").toInt();
    int dueDayId = dueDayModel->record(0).value("id").toInt();
    int attRow = attendantModel->addAttendant(personId, dueDayId);
    QCOMPARE(attRow, 0);
    attendantModel->submitAll();
}

void TestLug::findAttendantModel()
{
    // adding persons first
    int oldpRow = personModel->rowCount() - 1;
    int row = personModel->addPerson("56565656", "a212li2a32", "rrghjere", "a2lw2rdtggl222i@lkfdj.com");
    QCOMPARE(oldpRow+1, row);
    personModel->submitAll();

    //adding a dueDay
    int oldRow = dueDayModel->rowCount() - 1;
    int newRow = dueDayModel->addNewDay("2017-04-02");
    QCOMPARE(oldRow+1, newRow);
    dueDayModel->submitAll();

    //adding them in attendant
    attendantModel = std::make_unique<AttendantModel>();
    attendantModel->setHeaders();
    int personId = personModel->record(0).value("id").toInt();
    int dueDayId = dueDayModel->record(0).value("id").toInt();
    int attRow = attendantModel->addAttendant(personId, dueDayId);
    QCOMPARE(attRow, 0);
    attendantModel->submitAll();

    int theRow = attendantModel->findAttendant(personId, dueDayId);
    QCOMPARE(theRow, 0);


}

void TestLug::deleteAttendantModel()
{
    // adding persons first
    int oldpRow = personModel->rowCount() - 1;
    int row = personModel->addPerson("56511156", "a111li2a32", "rrghj11ere", "a2l1111dtggl222i@lkfdj.com");
    QCOMPARE(oldpRow+1, row);
    personModel->submitAll();

    //adding a dueDay
    int oldRow = dueDayModel->rowCount() - 1;
    int newRow = dueDayModel->addNewDay("2010-11-01");
    QCOMPARE(oldRow+1, newRow);
    dueDayModel->submitAll();

    //adding them in attendant
    attendantModel = std::make_unique<AttendantModel>();
    attendantModel->setHeaders();
    int personId = personModel->record(0).value("id").toInt();
    int dueDayId = dueDayModel->record(0).value("id").toInt();
    int attRow = attendantModel->addAttendant(personId, dueDayId);
    QCOMPARE(attRow, 0);
    attendantModel->submitAll();

    bool ok = attendantModel->deleteAttendant(personId, dueDayId);
    Q_ASSERT_X(ok, "deleting from attendantModel was successful.", "failed deleting from attendantModel.");
}

void TestLug::cleanupTestCase()
{
    database.close();
    Q_ASSERT_X(QFile::remove("lug.db"), "deleting database", "delete failed");
}


QTEST_MAIN(TestLug)


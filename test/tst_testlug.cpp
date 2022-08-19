#include "tst_testlug.h"

TestLug::TestLug()
{
}

void TestLug::initTestCase()
{

}

void TestLug::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestLug::databaseTest()
{
    Q_ASSERT_X(database.open(), "opening database", "failed to open");
}

void TestLug::addPersonModel()
{
    personModel = std::make_unique<PersonModel>();
    personModel->setHeaders();

    //myTimer.start();
    database.dbTransaction();
    int row = personModel->addPerson("12222233", "a22lirez2222a32", "hosd222dsr", "a2l22i2ael222i@lkfdj.com");
    personModel->submitAll();
    personModel->addPerson("1111", "alieaza", "allbkbklabjk", "alireza@lkfdj.com");
    personModel->submitAll();
    personModel->addPerson("23546434", "mohamad", "silver", "silveri@lkfdj.com");
    personModel->submitAll();
    personModel->addPerson("333333333", "reza", "bagher", "saghari@lkfdj.com");
    personModel->submitAll();
    personModel->addPerson("22221342222", "javad", "sorayayi", "soraya@lkfdj.com");
    personModel->submitAll();
    database.dbCommit();

    QCOMPARE(0, row);
}

void TestLug::findPersonModel()
{
    int testAdd = personModel->addPerson("12345678", "javad", "sorayayi", "soraya@lkfdj.com");
    personModel->submitAll();
    QCOMPARE(testAdd, personModel->rowCount() - 1);

    int row = personModel->findPersonAndIncreaseSection("12345678");
    QCOMPARE(row, personModel->rowCount() - 1);

    QString a = personModel->record(row).value("firstName").toString();
    QCOMPARE(a, QString("javad"));
}

void TestLug::deletePersonModel()
{
    database.dbTransaction();
    Q_ASSERT(personModel->addPerson("122233", "alieasd", "falskdjf", "alskdjf@dklsfaj.com"));
    personModel->submitAll();

    Q_ASSERT_X(personModel->deletePerson("122233"), "deleting person", "failed to delete person");
    personModel->submitAll();
    database.dbCommit();
}

void TestLug::addDayDueDayModel()
{
    dueDayModel = std::make_unique<DueDayModel>();
    dueDayModel->setHeaders();
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

    //adding them in attendant
    attendantModel = std::make_unique<AttendantModel>();
    attendantModel->setHeaders();
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


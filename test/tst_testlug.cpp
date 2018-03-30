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
    personModel = new PersonModel();
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
    dueDayModel = new DueDayModel();
    dueDayModel->setHeaders();
    dueDayModel->addNewDay();
    dueDayModel->addNewDay("2014-12-12");
    dueDayModel->submitAll();

}

void TestLug::findDayDueDayModel()
{

    dueDayModel->addNewDay("2016-12-12");
    dueDayModel->submitAll();

    int row = dueDayModel->findDueDay("2016-12-12");
    QCOMPARE(row, dueDayModel->rowCount() - 1);

}

void TestLug::cleanupTestCase()
{
    delete personModel;
    delete dueDayModel;
    database.close();
    Q_ASSERT_X(QFile::remove("lug.db"), "deleting database", "delete failed");
}


QTEST_MAIN(TestLug)


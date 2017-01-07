#include "tst_testlug.h"
#include <QTime>

TestLug::TestLug()
{
    qDebug() << "test Public test func";
}

void TestLug::initTestCase()
{
    qDebug() << "init nothing yet";
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
    model = new QSqlTableModel();
    personModel.setModel(model);

    myTimer.start();
    database.dbTransaction();
    bool ok = personModel.addPerson(model, "12222233", "a22lirez2222a32", "hosd222dsr", "a2l22i2ael222i@lkfdj.com");
    model->submitAll();
    personModel.addPerson(model, "1111", "alieaza", "allbkbklabjk", "alireza@lkfdj.com");
    model->submitAll();
    personModel.addPerson(model, "23546434", "mohamad", "silver", "silveri@lkfdj.com");
    model->submitAll();
    personModel.addPerson(model, "333333333", "reza", "bagher", "saghari@lkfdj.com");
    model->submitAll();
    personModel.addPerson(model, "22221342222", "javad", "sorayayi", "soraya@lkfdj.com");
    model->submitAll();
    database.dbCommit();
    qDebug() << myTimer.elapsed();
    //    QModelIndex index = model->index(0,1);
    //    qDebug() << "Code : " << index.data().toInt();

    //if exist return false
    QCOMPARE(true, ok);

    //    personModel.setModel(model);
    //    int row = 1;
    //    qDebug() << "id: " << model->index(row, 0).data();
    //    qDebug() << "code: " << model->index(row, 1).data();
    //    qDebug() << "name: " << model->index(row, 2).data();
    //    qDebug() << "family: " << model->index(row, 3).data();
    //    qDebug() << "session cointer: " << model->index(row, 4).data();
    //    qDebug() << "email: " << model->index(row, 5).data();
    //    qDebug() << "register day: " << model->index(row, 6).data();

}

void TestLug::findPersonModel()
{
    personModel.setModel(model);
    bool testAdd = personModel.addPerson(model, "12345678", "javad", "sorayayi", "soraya@lkfdj.com");
    model->submitAll();
    Q_ASSERT(testAdd);

    QModelIndex index;
    personModel.setModel(model);
    bool ok = personModel.findPerson(model,"12345678");
    Q_ASSERT(ok);

    QString a = model->record(0).value("firstName").toString();
    QCOMPARE(a, QString("javad"));

    index = model->index(0,4);
    qDebug() << "session counter : " << index.data();
}

void TestLug::updatePersonModel()
{
    myTimer.restart();
    database.dbTransaction();
    QModelIndex index;
    personModel.setModel(model);
    personModel.setModel(model);
    bool testAdd = personModel.addPerson(model, "1434232", "jaasdfasfavad", "sorsdfasayayi", "soraya@lkfdj.com");
    if(!testAdd)
    {
        testAdd = personModel.findPerson(model, "1434232", 0);
    }
    model->submitAll();
    Q_ASSERT(testAdd);

    personModel.setModel(model);
    personModel.findPerson(model, "1434232", 0);
    qDebug() << "befor changing data code = " << model->index(0, 1).data() << testAdd;
    qDebug() << "befor changing data name = " << model->index(0, 2).data() << testAdd;
    bool ok = personModel.updatePerson(model, 0, "aaaaaaaa");
    model->submitAll();
    database.dbCommit();
    index = model->index(0,2);
    qDebug() << "After Updating : " << index.data() << ok;

    Q_ASSERT(ok);
    qDebug() << myTimer.elapsed();


}

void TestLug::deletePersonModel()
{
    database.dbTransaction();
    personModel.setModel(model);
    Q_ASSERT(personModel.addPerson(model, "122233", "alieasd", "falskdjf", "alskdjf@dklsfaj.com"));
    model->submitAll();

    personModel.setModel(model);
    Q_ASSERT_X(personModel.deletePerson(model, "122233"), "deleting person", "failed to delete person");
    model->submitAll();
    database.dbCommit();
}

void TestLug::addDayDueDayModel()
{
    dueDayModel.setModel(model);
    Q_ASSERT_X(dueDayModel.addNewDay(model, QDate::currentDate().toString(Qt::ISODate)), "adding date", "failed to add");
    model->submitAll();
}

void TestLug::findDayDueDayModel()
{

    dueDayModel.setModel(model);
    dueDayModel.addNewDay(model, "2016-12-12");
    model->submitAll();

    dueDayModel.setModel(model);
    Q_ASSERT_X(dueDayModel.findDate(model, "2016-12-12"), "finding date", "failed to find");

}

void TestLug::addAttendantModel()
{
    database.dbTransaction();
    personModel.setModel(model);
    personModel.addPerson(model, "2231441", "ehsan", "sorayayi", "soraya@lkfdj.com");
    model->submitAll();

    dueDayModel.setModel(model);
    dueDayModel.addNewDay(model, "2011-12-13");
    model->submitAll();

    attendantModel.setModel(model);
    Q_ASSERT_X(attendantModel.addAttendant(model, "1434232", "2011-12-13"), "adding attedant", "faild to add");
    model->submitAll();
    database.dbCommit();

}

void TestLug::findAttendantModel()
{

    //    attendantModel.setModel(model);
    //    bool ok = attendantModel.findAttendant(model, 79, 11);
    //    QCOMPARE(true, ok);
}

void TestLug::findAttendantModelByPersonCode()
{
    database.dbTransaction();
    personModel.setModel(model);
    personModel.addPerson(model, "2231441", "ehsan", "sorayayi", "soraya@lkfdj.com");
    model->submitAll();

    dueDayModel.setModel(model);
    dueDayModel.addNewDay(model, "2011-10-11");
    model->submitAll();

    attendantModel.setModel(model);
    attendantModel.addAttendant(model, "2231441", "2011-10-11");
    model->submitAll();

    attendantModel.setModel(model);
    Q_ASSERT_X(attendantModel.findAttendant(model, "2231441", 0), "finding attendant", "faild to find");
    database.dbCommit();
}

void TestLug::findAttendantModelByDate()
{
    database.dbTransaction();
    personModel.setModel(model);
    personModel.addPerson(model, "123321123", "ehsan", "sorayayi", "soraya@lkfdj.com");
    model->submitAll();

    dueDayModel.setModel(model);
    dueDayModel.addNewDay(model, "2011-12-21");
    model->submitAll();

    attendantModel.setModel(model);
    attendantModel.addAttendant(model, "123321123", "2011-12-21");
    model->submitAll();

    attendantModel.setModel(model);
    Q_ASSERT_X(attendantModel.findAttendant(model, 0, "2011-12-21"), "finding attendant by date", "faild to find");
    //qDebug() << model->index(0,2).data();
    database.dbCommit();

}

void TestLug::deleteAttendantModelByPersonCode()
{
    database.dbTransaction();
    personModel.setModel(model);
    personModel.addPerson(model, "54234234", "ssossoss", "sorayayi", "soraya@lkfdj.com");
    model->submitAll();

    dueDayModel.setModel(model);
    dueDayModel.addNewDay(model, "2011-11-11");
    model->submitAll();

    attendantModel.setModel(model);
    attendantModel.addAttendant(model, "54234234", "2011-11-11");
    model->submitAll();

    attendantModel.setModel(model);
    Q_ASSERT_X(attendantModel.deleteAttendant(model, "54234234"), "finding attendant by date", "faild to find");
    model->submitAll();
    database.dbCommit();
}

void TestLug::cleanupTestCase()
{
    database.~MyDatabase();
    Q_ASSERT_X(QFile::remove("lug.db"), "deleting database", "delete failed");
    qDebug() << "database deleted.";
}


QTEST_MAIN(TestLug)


#include "tst_testlug.h"
#include <QTime>

TestLug::TestLug()
{
}

void TestLug::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestLug::databaseTest()
{
    bool ok = database.open();
    QCOMPARE(true, ok);
}

void TestLug::addPersonModel()
{
    model = new QSqlTableModel();
    personModel.setModel(model);

    qDebug() << model->index(0,1).data();
    qDebug() << model->index(1,1).data();
    qDebug() << model->index(2,1).data();

    /**
     * @brief ok = true if Data successfully add to database
     *  and ok = false if Data exist or can't add to database
     */
    myTimer.start();
    //database.dbTransaction();
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
    //database.dbCommit();
    qDebug() << myTimer.elapsed();
    QModelIndex index = model->index(0,1);
    qDebug() << "Code : " << index.data().toInt();

    //if exist return false
    QCOMPARE(true, ok);
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


}

void TestLug::deletePersonModel()
{
    personModel.setModel(model);
    Q_ASSERT(personModel.addPerson(model, "122233", "alieasd", "falskdjf", "alskdjf@dklsfaj.com"));
    model->submitAll();

    database.dbTransaction();
    model = new QSqlTableModel();
    personModel.setModel(model);
    Q_ASSERT_X(personModel.deletePerson(model, "122233"), "deleting person", "failed to delete person");
    model->submitAll();
    database.dbCommit();
}

void TestLug::addDayDueDayModel()
{
    database.dbTransaction();
    model = new QSqlTableModel();
    dueDayModel.setModel(model);

    Q_ASSERT_X(dueDayModel.addNewDay(model, QDate::currentDate().toString(Qt::ISODate)), "adding date", "failed to add");
    model->submitAll();
    database.dbCommit();

}

void TestLug::findDayDueDayModel()
{
    dueDayModel.setModel(model);
    Q_ASSERT_X(dueDayModel.findDate(model, QDate::currentDate().toString(Qt::ISODate)), "finding date", "failed to find");

}

void TestLug::addAttendantModel()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    Q_ASSERT_X(attendantModel.addAttendant(model, "1434232", QDate::currentDate().toString(Qt::ISODate)), "adding attedant", "faild to add");
    model->submitAll();

}

void TestLug::findAttendantModel()
{
//    model = new QSqlTableModel();
//    attendantModel.setModel(model);

//    bool ok = attendantModel.findAttendant(model, 79, 11);
//    QCOMPARE(true, ok);
}

void TestLug::findAttendantModelByPersonCode()
{
    attendantModel.setModel(model);

    Q_ASSERT_X(attendantModel.findAttendant(model, "1434232", 0), "finding attendant", "faild to find");

}

void TestLug::findAttendantModelByDate()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    Q_ASSERT_X(attendantModel.findAttendant(model, 0, QDate::currentDate().toString(Qt::ISODate)), "finding attendant by date", "faild to find");
    QModelIndex index = model->index(0,2);
    qDebug() << index.data();
}

void TestLug::deleteAttendantModelByPersonCode()
{
    database.dbTransaction();

    attendantModel.setModel(model);

    Q_ASSERT_X(attendantModel.deleteAttendant(model, "1434232"), "finding attendant by date", "faild to find");
    model->submitAll();
    database.dbCommit();
}

void TestLug::deleteDataBase()
{
    database.~MyDatabase();
    Q_ASSERT_X(QFile::remove("lug.db"), "deleting database", "delete failed");

}


QTEST_MAIN(TestLug)


#include "tst_testlug.h"


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

    /**
     * @brief ok = true if Data successfully add to database
     *  and ok = false if Data exist or can't add to database
     */
    bool ok = personModel.addPerson(model, "1222223", "a22lirez2222a32", "hosd222dsr", "a2l22i2ael222i@lkfdj.com");
//    personModel.addPerson(model, "1111", "alieaza", "allbkbklabjk", "alireza@lkfdj.com");
//    personModel.addPerson(model, "2222", "mohamad", "silver", "silveri@lkfdj.com");
//    personModel.addPerson(model, "3333", "reza", "bagher", "saghari@lkfdj.com");
//    personModel.addPerson(model, "22222", "javad", "sorayayi", "soraya@lkfdj.com");
    QModelIndex index = model->index(0,1);
    qDebug() << "Code : " << index.data().toInt();

    //if exist return false
    QCOMPARE(true, ok);
}

void TestLug::findPersonModel()
{
    QModelIndex index = model->index(0,1);
    qDebug() << "Fist of findPersonModel : " << index.data();
    personModel.setModel(model);
    bool ok = personModel.findPerson(model,"1222223");
    QCOMPARE(true, ok);
    QString a = model->record(0).value("firstName").toString();
    QCOMPARE(a, QString("a22lirez2222a32"));
    index = model->index(0,4);
    qDebug() << "session counter : " << index.data();
}

void TestLug::updatePersonModel()
{
    QModelIndex index = model->index(0,2);
    qDebug() << "Fist of findPersonModel : " << index.data();
    personModel.setModel(model);
    qDebug() << "Fist of findPersonModel : " << index.data();
    personModel.findPerson(model, "1111", "");
    bool ok = personModel.updatePerson(model, "", "aaaaaaaa");
    index = model->index(0,2);
    qDebug() << "After Updating : " << index.data();
    QCOMPARE(true, ok);


}

void TestLug::deletePersonModel()
{
    model = new QSqlTableModel();
    personModel.setModel(model);
    bool ok = personModel.deletePerson(model, "1222223");
    QCOMPARE(true, ok);


}

void TestLug::addDayDueDayModel()
{
    model = new QSqlTableModel();
    dueDayModel.setModel(model);

    bool ok = dueDayModel.addNewDay(model, QDate::currentDate().toString(Qt::ISODate));
    //QCOMPARE(true, ok);
    QCOMPARE(false, ok);

}

void TestLug::findDayDueDayModel()
{
    dueDayModel.setModel(model);
    bool ok = dueDayModel.findDate(model, QDate::currentDate().toString(Qt::ISODate));
    QCOMPARE(true, ok);
}

void TestLug::addAttendantModel()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    bool ok = attendantModel.addAttendant(model, "1111", "2016-12-15");
    QCOMPARE(true, ok);
}

void TestLug::findAttendantModel()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    bool ok = attendantModel.findAttendant(model, 8, 2);
    QCOMPARE(true, ok);
}

void TestLug::findAttendantModelByPersonCode()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    bool ok = attendantModel.findAttendant(model, "1111", 0);
    QCOMPARE(true, ok);
}

void TestLug::findAttendantModelByDate()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    bool ok = attendantModel.findAttendant(model, 0, "2016-12-15");
    QModelIndex index = model->index(0,2);
    qDebug() << index.data();
    QCOMPARE(true, ok);
}

void TestLug::deleteAttendantModelByPersonCode()
{
    model = new QSqlTableModel();
    attendantModel.setModel(model);

    bool ok = attendantModel.deleteAttendant(model, "1111");
    QCOMPARE(true, ok);
}


QTEST_MAIN(TestLug)


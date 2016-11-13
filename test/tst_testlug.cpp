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

    //existed data false
    //not exist data true
    bool ok = personModel.addPerson(model, "1222223", "a22lirez2222a32", "hosd222dsr", "a2l22i2ael222i@lkfdj.com");
    QModelIndex index = model->index(0,1);
    qDebug() << "Code : " << index.data();

    //if exist return false
    QCOMPARE(false, ok);
}

void TestLug::findPersonModel()
{
    QModelIndex index = model->index(0,1);
    qDebug() << "Fist of findPersonModel : " << index.data();
    //model = new QSqlTableModel();
    personModel.setModel(model);
    bool ok = personModel.findPerson(model,"1222223");
    //bool ok2 = personModel.findPerson(model, "", "a22lirez2222a32");
    QString a = model->record(0).value("firstName").toString();

    index = model->index(0,4);
    qDebug() << "session counter : " << index.data();
    QCOMPARE(a, QString("a22lirez2222a32"));
    QCOMPARE(true, ok);
    //QCOMPARE(true, ok2);
}

QTEST_MAIN(TestLug)


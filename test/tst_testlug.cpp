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

QTEST_MAIN(TestLug)


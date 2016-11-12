#include <QObject>
#include <QtTest>
#include "../src/database/mydatabase.h"

class TestLug : public QObject
{
    Q_OBJECT

    MyDatabase database;

public:
    TestLug();


private Q_SLOTS:
    void testCase1();
    void databaseTest();
};



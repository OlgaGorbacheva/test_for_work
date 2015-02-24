#include <QString>
#include <QtTest>

#include "../queue.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private Q_SLOTS:
    void Case1();
};

Test::Test()
{
}

void Test::Case1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"

#include <QtTest>

// add necessary includes here

class testDealerHelper : public QObject
{
    Q_OBJECT

public:
    testDealerHelper();
    ~testDealerHelper();

private slots:
    void test_case1();

};

testDealerHelper::testDealerHelper()
{

}

testDealerHelper::~testDealerHelper()
{

}

void testDealerHelper::test_case1()
{

}

QTEST_APPLESS_MAIN(testDealerHelper)

#include "tst_testdealerhelper.moc"

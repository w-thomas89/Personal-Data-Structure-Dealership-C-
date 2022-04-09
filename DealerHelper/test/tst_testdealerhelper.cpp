#include <QtTest>

// add necessary includes here

class testDealerHelper : public QObject
{
    Q_OBJECT

public:
    testDealerHelper();
    ~testDealerHelper();

private slots:

};

testDealerHelper::testDealerHelper() {}
testDealerHelper::~testDealerHelper() {}


//QTEST_APPLESS_MAIN(testDealerHelper)

#include "tst_testdealerhelper.moc"

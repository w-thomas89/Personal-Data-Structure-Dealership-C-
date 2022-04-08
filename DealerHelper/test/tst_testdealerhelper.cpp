#include "customer.h"
#include <QtTest>

// add necessary includes here

class testDealerHelper : public QObject
{
    Q_OBJECT

public:
    testDealerHelper();
    ~testDealerHelper();

private slots:
    void testCustomer();
    void testVehicle();
    void testDealership();
};

testDealerHelper::testDealerHelper() {}
testDealerHelper::~testDealerHelper() {}

void testDealerHelper::testCustomer()
{
    string fName, lName, phone;
    float max = 25000;
    fName = "John";
    lName = "Doe";
    phone = "515-123-4567";
    customer test = customer(fName, lName, phone);
    test.setMaxCost(max);
    QCOMPARE(fName, test.getFirstName());
    QCOMPARE(lName, test.getLastName());
    QCOMPARE(phone, test.getPhone());
    QCOMPARE(max, test.getMaxCost());
}

void testDealerHelper::testVehicle()
{

}

void testDealerHelper::testDealership()
{

}

QTEST_APPLESS_MAIN(testDealerHelper)

#include "tst_testdealerhelper.moc"

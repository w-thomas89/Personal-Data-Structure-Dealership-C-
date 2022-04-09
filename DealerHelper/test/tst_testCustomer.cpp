#include <QtTest>
#include "customer.h"


class testCustomer : public QObject {

    Q_OBJECT

public:
    testCustomer();
    ~testCustomer();

private slots:
    void testCustomerDefault();
    void testCustomerParameter();
    void testCustomerFirstName();
    void testCustomerLastName();
    void testCustomerPhone();
    void testCustomerMaxCost();
};

testCustomer::testCustomer(){};
testCustomer::~testCustomer(){}

void testCustomer::testCustomerDefault()
{
    customer test = customer();
    string expected, actual;
    expected = "8customer"; //the typeid(x).name() of object
    actual = typeid(test).name();
    QCOMPARE(expected, actual);
}

void testCustomer::testCustomerParameter()
{
    string fName, lName, phone;
    fName = "John";
    lName = "Doe";
    phone = "515-123-4567";
    customer test = customer(fName, lName, phone);
    string expected = "Doe, John\nPhone: (515)123-4567\n";
    string actual = test.toString();
    QCOMPARE(expected, actual);
}

void testCustomer::testCustomerFirstName()
{
    string fName, lName, phone;
    fName = "John";
    lName = "Doe";
    phone = "515-123-4567";
    customer test = customer(fName, lName, phone);
    string actual = test.getFirstName();
    QCOMPARE(fName, actual);
}

void testCustomer::testCustomerLastName()
{
    string fName, lName, phone;
    fName = "John";
    lName = "Doe";
    phone = "515-123-4567";
    customer test = customer(fName, lName, phone);
    string actual = test.getLastName();
    QCOMPARE(lName, actual);
}

void testCustomer::testCustomerPhone()
{
    string fName, lName, phone;
    fName = "John";
    lName = "Doe";
    phone = "(515)123-4567";
    customer test = customer(fName, lName, phone);
    string actual = test.getPhone();
    QCOMPARE(phone, actual);
}

void testCustomer::testCustomerMaxCost()
{
    string fName, lName, phone;
    fName = "John";
    lName = "Doe";
    phone = "515-123-4567";
    customer test = customer(fName, lName, phone);
    float maxCost = 45999;
    test.setMaxCost(maxCost);
    float actual = test.getMaxCost();
    QCOMPARE(maxCost, actual);
};

QTEST_APPLESS_MAIN(testCustomer)

#include "tst_testCustomer.moc"

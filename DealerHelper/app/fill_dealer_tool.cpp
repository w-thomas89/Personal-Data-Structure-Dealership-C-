#include "dealership.h"
#include <time.h>

void fillInventory(Dealership *deal) {
    const int lotSize = deal->getLotSize();
    const int numStaff = 5;

    srand (time(NULL));
    for (int i = 0; i < lotSize; i++) {
        vehicle v = vehicle("Model" + to_string(i), "Color" + to_string(i), true, i%4);
        deal->addInventory(v);
    }
    for (int i = 0; i < numStaff; i++) {
        employee e = employee("Name" + to_string(1), i);
        deal->addEmployee(e);
    }
    customer a = customer("John", "Doe", "515-123-4567");
    customer b = customer("Jane", "Doe", "515-555-9999");
    customer c = customer("Max", "Martin", "888-123-4567");
    customer d = customer("Tyler", "Winkelvoss", "999-999-9999");
    customer e = customer("Sally", "Jones", "(414)555-9823");
    customer f = customer("Courtney", "Salting", "563 999 4455");
    customer g = customer("Test", "Test", "123-456-7890");
    deal->addCustomer(a);
    deal->addCustomer(b);
    deal->addCustomer(c);
    deal->addCustomer(d);
    deal->addCustomer(e);
    deal->addCustomer(f);
    deal->addCustomer(g);
}

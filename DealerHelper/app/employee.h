#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "vehicle.h"
#include "customer.h"
#include <queue>

class employee
{
private:
    string name;
    int id;
    queue<vehicle> sales;
    queue<customer> customers;
public:
    employee();
    employee(string name);
    queue<vehicle> getSales();
    queue<customer> getCustomers;
    void addSale(vehicle toAdd);
    void addCustomer(customer toAdd);
};

#endif // EMPLOYEE_H

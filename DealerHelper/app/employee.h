#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "vehicle.h"
#include "customer.h"
#include <list>
#include <queue>

class employee
{
private:
    string name;
    list<customer> customerList;
    queue<vehicle> salesList;
public:
    int id;
    employee();
    employee(string name, int id);
    void setName(string name);
    string getName();
    void addToCustomer(customer c);
    void addToSales(vehicle v);
    queue<vehicle> getSalesList();
    list<customer> getCustomerList();
    int getNumberSales();
    int getNumberCustomers();
    string printSalesList();
    string toString();
};

#endif // EMPLOYEE_H

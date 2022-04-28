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
<<<<<<< Updated upstream
    int id;
    queue<vehicle> sales;
    queue<customer> customers;
=======
    list<customer> customerList;
    queue<vehicle> salesList;
>>>>>>> Stashed changes
public:
    int id;
    employee();
<<<<<<< Updated upstream
    employee(string name);
    queue<vehicle> getSales();
    queue<customer> getCustomers;
    void addSale(vehicle toAdd);
    void addCustomer(customer toAdd);
=======
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
>>>>>>> Stashed changes
};

#endif // EMPLOYEE_H

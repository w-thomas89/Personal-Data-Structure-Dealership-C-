#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include "customer.h"
#include "vehicle.h"
#include "employee.h"
#include <queue>
#include <list>

class Dealership
{
private:
    string name;
    int lotSize;
    list<vehicle> inventory;
    queue<vehicle> nextInventory;
    list<customer> customers;
    list<employee> employees;
public:
    Dealership();
    Dealership(string name);
    Dealership(string name, int lotSize);
    virtual ~Dealership();
    void setName(string name);
    string getName();
    void setLotSize(int lotSize);
    int getLotSize();
    list<vehicle> getInventory();
    void addInventory(vehicle toAdd);
    list<customer> getCustomers();
    void addCustomer(customer toAdd);
    bool lotIsFull();
    string toString();
    list<employee> getEmployees();
    void addEmployee(employee toAdd);
};

#endif // DEALERSHIP_H

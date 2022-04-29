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
    string name;    //dealers name
    int lotSize;    //lot size - important piece utilized by collaborative data structures
    list<vehicle> inventory;    //list of vehicles for current inventory
    queue<vehicle> nextInventory;   //queue of vehicles for the backorder system
    list<customer> customers;   //list of customers (not necessarily on a salesman's list)
    list<employee> employees;   //list of employees
public:
    Dealership();
    Dealership(string name);
    Dealership(string name, int lotSize);
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
    void makeSale(vehicle toRemove);
    vehicle getNextBackorder();
    void sortCustomers();
};

#endif // DEALERSHIP_H

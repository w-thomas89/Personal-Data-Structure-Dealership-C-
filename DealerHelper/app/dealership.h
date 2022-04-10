#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include "customer.h"
#include "vehicle.h"
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
};

#endif // DEALERSHIP_H

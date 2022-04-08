#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include "customer.h"
#include "vehicle.h"
#include <queue>

class Dealership
{
private:
    string name;
    int lotSize;
    priority_queue<vehicle> inventory;
    vector<customer> customers;
public:
    friend bool operator < (vehicle lhs, vehicle rhs);
    friend bool operator > (vehicle lhs, vehicle rhs);
    Dealership();
    Dealership(string name);
    Dealership(string name, int lotSize);
    virtual ~Dealership();
    void setName(string name);
    string getName();
    void setLotSize(int lotSize);
    int getLotSize();
    vehicle getInventory();
    void addInventory(vehicle toAdd);
    vector<customer> getCustomers();
    void addCustomer(customer toAdd);
    float getLotFull();
};

#endif // DEALERSHIP_H

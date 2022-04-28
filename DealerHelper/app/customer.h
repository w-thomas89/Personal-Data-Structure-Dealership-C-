#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "vehicle.h"

using namespace std;

class customer
{
private:
    //members
    string fName;   //Customer First Name
    string lName;   //Customer Last Name
    vector<vehicle> preferVehicle;  //linked list of preferd vehicles
    float maxCost;  //Customer declared maximum price they will spend
    int phone[10];    //array of int for customer phone number

public:
    customer();
    customer(string fName, string lName);
    customer(string fName, string lName, string phone);
    void setFirstName(string fName);
    string getFirstName();
    void setLastName(string lName);
    string getLastName();
    void addPreferedVehicle(vehicle, int priority);
    vector<vehicle> getPreferredVehicles();
    void setMaxCost(float maxCost);
    float getMaxCost();
    void setPhone(string phone);
    string getPhone();
    string toString();
    string printPreferList();
};

#endif // CUSTOMER_H

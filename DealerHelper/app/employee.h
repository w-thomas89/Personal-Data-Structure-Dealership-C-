#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "vehicle.h"
#include "customer.h"
#include <queue>

class employee
{
private:
    string name;
    queue<vehicle> sales;
    queue<customer> customers;
public:
    employee();
};

#endif // EMPLOYEE_H

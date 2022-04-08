#include "dealership.h"

Dealership::Dealership(){}

Dealership::Dealership(string name) {
    this->name = name;
}

Dealership::Dealership(string name, int lotSize) {
    this->name = name;
    this->lotSize = lotSize;
}

Dealership::~Dealership() {}

void Dealership::setName(string name) {
    this->name = name;
}

string Dealership::getName() {
    return name;
}

void Dealership::setLotSize(int lotSize) {
    this->lotSize = lotSize;
}

int Dealership::getLotSize() {
    return lotSize;
}

vehicle Dealership::getInventory() {
    return inventory.top();
}

void Dealership::addInventory(vehicle toAdd) {
    inventory.push(toAdd);
}

list<customer> Dealership::getCustomers() {
    return customers;
}

void Dealership::addCustomer(customer toAdd) {
    customers.push_back(toAdd);
}

float Dealership::getLotFull() {
    return (float)inventory.size() / (float)lotSize;
}

bool operator < (vehicle lhs, vehicle rhs) {
    return lhs.getReceiveDate() < rhs.getReceiveDate();
}

bool operator > (vehicle lhs, vehicle rhs) {
    return lhs.getReceiveDate() > rhs.getReceiveDate();
}

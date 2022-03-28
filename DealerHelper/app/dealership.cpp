#include "dealership.h"

Dealership::Dealership(){}

Dealership::Dealership(string name) {
    this->name = name;
}

Dealership::Dealership(string name, int lotSize) {
    this->name = name;
    this->lotSize = lotSize;
}

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

priority_queue<vehicle> Dealership::getInventory() {
    return inventory;
}

void Dealership::addInventory(vehicle toAdd) {
    inventory.push(toAdd);
}

vector<customer> Dealership::getCustomers() {
    return customers;
}

void Dealership::addCustomer(customer toAdd) {
    customers.push_back(toAdd);
}

float Dealership::getLotFull() {
    return (float)inventory.size() / (float)lotSize;
}

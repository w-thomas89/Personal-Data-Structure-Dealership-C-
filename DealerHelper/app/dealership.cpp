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

void Dealership::setName(string name) {this->name = name;}

string Dealership::getName() {return name;}

void Dealership::setLotSize(int lotSize) {this->lotSize = lotSize;}

int Dealership::getLotSize() {return lotSize;}


list<vehicle> Dealership::getInventory() {return inventory;}

void Dealership::addInventory(vehicle toAdd) {
    if (lotIsFull()) {
        nextInventory.push(toAdd);
    }
    else inventory.push_back(toAdd);
}

list<customer> Dealership::getCustomers() {return customers;}

void Dealership::addCustomer(customer toAdd) {customers.push_back(toAdd);}

bool Dealership::lotIsFull() {return ((int)inventory.size() / (int)lotSize) == 0;}

string Dealership::toString() {
    return ""; //TODO - finalize how to handle dealership toString reports
}

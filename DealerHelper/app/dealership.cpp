#include "dealership.h"
#include <algorithm>
#include <iostream>

Dealership::Dealership(){}

Dealership::Dealership(string name) {
    this->name = name;
}

Dealership::Dealership(string name, int lotSize) {
    this->name = name;
    this->lotSize = lotSize;
}

void Dealership::setName(string name) {this->name = name;}

string Dealership::getName() {return name;}

void Dealership::setLotSize(int lotSize) {this->lotSize = lotSize;}

int Dealership::getLotSize() {return lotSize;}

list<vehicle> Dealership::getInventory() {return inventory;}

//The add inventory function will move over to queue if the lot is full
void Dealership::addInventory(vehicle toAdd) {
    if (lotIsFull()) {
        nextInventory.push(toAdd);
    }
    else inventory.push_back(toAdd);
}

list<customer> Dealership::getCustomers() {return customers;}

void Dealership::addCustomer(customer toAdd) {
    for (list<customer>::iterator it = customers.begin(); it != customers.end(); it++) {
        if (it->getPhone() == toAdd.getPhone()) {
            *it = toAdd;
            return;
        }
    }
    customers.push_back(toAdd);
}

bool Dealership::lotIsFull() {return (int)inventory.size() >= lotSize;}

//addEmployee will either create a new employee, or replace one if names match
void Dealership::addEmployee(employee toAdd) {
    for (list<employee>::iterator it = employees.begin(); it != employees.end(); it++) {
        if (it->id == toAdd.id) {
            (*it) = toAdd;
            return;
        }
    }
    employees.push_back(toAdd);
}

list<employee> Dealership::getEmployees() {return employees;}

//here is where the overloaded operators are used in vehicle. The remove function needs to
//know how to compare the objects for removal.
void Dealership::makeSale(vehicle toRemove) {
    try {
        inventory.remove(toRemove);
        inventory.push_back(nextInventory.front());
        nextInventory.pop();
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}

vehicle Dealership::getNextBackorder() {return this->nextInventory.front();}

string Dealership::toString() {
    return ""; //TODO - finalize how to handle dealership toString reports
}

void Dealership::sortCustomers() {
    vector<customer> sort;
    list<customer> temp = getCustomers();
    sort.insert(sort.end(), temp.begin(), temp.end());
    int j;
    string key;
    for (size_t i = 0; i < sort.size(); i++) {
        key = sort[i].getLastName();
        j = i - 1;
        while (j >= 0 && sort[j].getLastName() > key) {
            sort[j + 1] = sort[j];
            j = j - 1;
        }
        sort[j + 1] = sort[i];
    }
    for (size_t i = 0; i < sort.size(); i++) {
        cout << sort[i].toString() << endl;
    }
}

/***************************************************************
* Name : DealerHelper
* Author: William Thomas
* Created : 03/28/2022
* Course: CIS 152 - Data Structure
* Version: 1.0
* OS: Windows 10
* IDE: QT 5.12.15
* Copyright : This is my own original work based on requirements by
*   instructor
* Description : This is a console based application that will utilize
*   multiple data structures to control the inventory and staff/customers
*   of a vehicle dealership. This program utilizes a list, queue, and vector.
*   A sorting algorithm was implemented using a vector from a list for the
*   customer list that sorts alphabetically by last name.
*   Also created a custom priority queue out of a vector that uses and INT
*   based priority input to place the item at preferred location. Works like
*   a priority queue, but can be easily iterated and copied.
*
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access
* to my program.
***************************************************************/
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

//adding a customer will first check for equality of last name in the current list, this prevents redundancies
void Dealership::addCustomer(customer toAdd) {
    for (list<customer>::iterator it = customers.begin(); it != customers.end(); it++) {
        if (it->getLastName().compare(toAdd.getLastName())) {
            *it = toAdd;
            return;
        }
    }
    customers.push_back(toAdd);
}

//basically works like an isFull() method, only it is confined by the designated lot size of the object
bool Dealership::lotIsFull() {return (int)inventory.size() >= lotSize;}

//addEmployee will either create a new employee, or replace one if id mathces
void Dealership::addEmployee(employee toAdd) {
    for (list<employee>::iterator it = employees.begin(); it != employees.end(); it++) {
        if (it->id == toAdd.id) {
            (*it) = toAdd;
            return; //return here to prevent below push from occurring if match is found
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

//this does a basic front() or "peek()" on the queue to get the first in line
vehicle Dealership::getNextBackorder() {return this->nextInventory.front();}

string Dealership::toString() {
    return ""; //TODO - finalize how to handle dealership toString reports
}

//here we use an insertion sort implemented to sort by object last name alphabetically
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

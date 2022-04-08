#include "customer.h"

customer::customer()
{
    fName = "";
    lName = "";
}

customer::customer(string fName, string lName) {
    this->fName = fName;
    this->lName = lName;
    this->maxCost = 0;
}

customer::customer(string fName, string lName, string phone) {
    this->fName = fName;
    this->lName = lName;
    this->phone = phone;
}

customer::~customer() {}

void customer::setFirstName(string fName) {
    this->fName = fName;
}

void customer::setLastName(string lName) {
    this->lName = lName;
}

string customer::getFirstName() {
    return fName;
}

string customer::getLastName() {
    return lName;
}

void customer::addPreferedVehicle(vehicle toAdd, int priority) {
    if (preferVehicle.empty() || (preferVehicle.size() < (unsigned long long)priority)) {
        preferVehicle.push_back(toAdd);
    }
    else {
        preferVehicle.insert(preferVehicle.begin() + priority, toAdd);
    }
}

vector<vehicle> customer::getPreferredVehicles() {
    return preferVehicle;
}

void customer::setMaxCost(float maxCost) {
    this->maxCost = maxCost;
}

float customer::getMaxCost() {
    return maxCost;
}

void customer::setPhone(string phone) {
    this->phone = phone;
}

string customer::getPhone() {
    return phone;
}


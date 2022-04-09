#include "customer.h"
#include <ctype.h>

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
    //this needs changed to run the functions converting string to int array
    setPhone(phone);
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

//priority queue linked list implemented with a vector using int priority as iterator insertion value
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

void customer::setPhone(string strphone) {
    for (size_t i = 0; i < strphone.length(); i++) {
        if (!isdigit(strphone[i]) || isspace(strphone[i])) {
           strphone.erase(i, 1);
        }
    }
    for (size_t j = 0; j < 10; j++) {
        this->phone[j] = strphone.at(j) - 48;
    }
}

string customer::getPhone() {
    return "(" + to_string(phone[0]) + to_string(phone[1]) + to_string(phone[2]) + ")" + to_string(phone[3]) + to_string(phone[4]) + to_string(phone[5]) +
            "-" + to_string(phone[6]) + to_string(phone[7])+ to_string(phone[8])+ to_string(phone[9]);
}

string customer::toString() {
    return lName + ", " + fName + "\nPhone: " + getPhone() + "\n";
}

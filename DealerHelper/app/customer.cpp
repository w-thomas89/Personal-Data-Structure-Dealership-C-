#include "customer.h"
#include <ctype.h>
#include <regex>

//default constructor
customer::customer()
{
    //assign first and last name to empty strings
    fName = "";
    lName = "";
}

//parametrized constructor using first and last name
customer::customer(string fName, string lName) {
    this->fName = fName;
    this->lName = lName;
    this->maxCost = 0;
}

//overloading parametrized constructor to include phone number input
customer::customer(string fName, string lName, string phone) {
    this->fName = fName;
    this->lName = lName;
    this->maxCost = 0;
    //utilize function to convert string to array of int for phone #
    setPhone(phone);
}
//destructor
customer::~customer() {}

void customer::setFirstName(string fName) {this->fName = fName;}

void customer::setLastName(string lName) {this->lName = lName;}

string customer::getFirstName() {return fName;}

string customer::getLastName() {return lName;}

//priority queue list implemented with a vector using int priority as iterator insertion value
void customer::addPreferedVehicle(vehicle toAdd, int priority) {
    if (preferVehicle.empty() || (preferVehicle.size() < (unsigned long long)priority)) {
        preferVehicle.push_back(toAdd);
    }
    else {
        preferVehicle.insert(preferVehicle.begin() + priority, toAdd);
    }
}
//will return priority queue ordered list of preferred vehicles index starting 0-zero
vector<vehicle> customer::getPreferredVehicles() {return preferVehicle;}

void customer::setMaxCost(float maxCost) {this->maxCost = maxCost;}

float customer::getMaxCost() {return maxCost;}

/* this function takes a string input of phone number in any format
 * i.e '555-555-5555', '(555)555-5555', (5555555555) and will convert to
 * an array of int sized 10 (for a phone number minus head +1 idea.
 * */
void customer::setPhone(string strphone) {
    string fix = regex_replace(strphone, regex(R"([\D])"), "");

    //here we will iterate through the ten digits, copying to object variable array
    try {
        for (size_t j = 0; j < 10; j++) {
            this->phone[j] = fix.at(j) - 48; //-48 had to be included due to ascii value reference when auto converting in c++
        }
    }
    catch(exception e) {
            return;
    }
}

//this function will return the phone number as a string formatted with "(xxx)xxx-xxxx"
string customer::getPhone() {
    return "(" + to_string(phone[0]) + to_string(phone[1]) + to_string(phone[2]) + ")" + to_string(phone[3]) + to_string(phone[4]) + to_string(phone[5]) +
            "-" + to_string(phone[6]) + to_string(phone[7])+ to_string(phone[8])+ to_string(phone[9]);
}

//this function will print out all the information about the customer
string customer::toString() {
    return lName + ", " + fName + "\nPhone: " + getPhone() + "\n";
}

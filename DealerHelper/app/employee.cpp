#include "employee.h"

employee::employee(){
    this->name = "";
    this->id = 0;
}

employee::employee(string name, int id) {
    this->name = name;
    this->id = id;
}

void employee::setName(string name) {
    this->name = name;
}

string employee::getName() {
    return name;
}

void employee::addToCustomer(customer toAdd) {
    customerList.push_back(toAdd);
}

void employee::addToSales(vehicle toAdd) {
    salesList.push(toAdd);
}

queue<vehicle> employee::getSalesList() {
    return salesList;
}

list<customer> employee::getCustomerList() {
    return customerList;
}

int employee::getNumberSales() {
    return (int)salesList.size();
}

int employee::getNumberCustomers() {
    return (int)customerList.size();
}

//creating a PrintList option for the queue since iteration is more difficult for output
string employee::printSalesList() {
    string output = "";
    queue<vehicle> sales = salesList;
    for (size_t i = 0; i < sales.size(); i++) {
        output += sales.front().toString() + "\n";
        sales.push(sales.front());
        sales.pop();
    }
    return output;
}

string employee::toString() {
    return "ID:" + to_string(id) + " -Name: " + name + "\n\tNumber of Sales: " + to_string(salesList.size()) +
            "\n\tNumber of Customers: " + to_string(customerList.size());
}

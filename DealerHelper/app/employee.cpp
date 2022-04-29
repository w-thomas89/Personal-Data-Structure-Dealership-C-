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
#include "employee.h"

employee::employee(){
    this->name = "";
    //creation of an empty employee is not suggested. id is set to -1 for any empty objects created
    this->id = -1;
}

//dealership objects controls the designation of the ID
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

//function that adds a customer to the contact list
void employee::addToCustomer(customer toAdd) {
    customerList.push_back(toAdd);
}

//function that adds sale to the queue of vehicles sold
void employee::addToSales(vehicle toAdd) {
    salesList.push(toAdd);
}

queue<vehicle> employee::getSalesList() {
    return salesList;
}

list<customer> employee::getCustomerList() {
    return customerList;
}

//a simple numeric value used in toString()
//this can be used by management or payroll to quickly analyze top performers
int employee::getNumberSales() {
    return (int)salesList.size();
}

//numeric value used in toString()
//this can be used by management to verify that employees are actively seeking contacts and making new ones
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

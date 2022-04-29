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
#include <time.h>

//this is almost like a driver except it just removes some tedious work in order to test the working model of program
void fillInventory(Dealership *deal) {  //we passed the object by reference, so changes made here will remain outside of scope
    const int lotSize = deal->getLotSize(); //lot size is designated by the object passed in
    const int numStaff = 5; //here you can designate the number of pre-filled staff you want to include

    srand (time(NULL));
    for (int i = 0; i < lotSize; i++) {
        vehicle v = vehicle("Model" + to_string(i), "Color" + to_string(i), true, i%4);
        deal->addInventory(v);
    }
    for (int i = 0; i < numStaff; i++) {
        employee e = employee("Name" + to_string(i), i);
        deal->addEmployee(e);
    }
    //here we had to create a bundle of independent customers. This was created to provide additional testing on the sorting algorithm
    customer a = customer("John", "Doe", "515-123-4567");
    customer b = customer("Jane", "Deer", "515-555-9999");
    customer c = customer("Max", "Martin", "888-123-4567");
    customer d = customer("Tyler", "Winkelvoss", "999-999-9999");
    customer e = customer("Sally", "Jones", "(414)555-9823");
    customer f = customer("Courtney", "Salting", "563 999 4455");
    customer g = customer("Test", "Test", "123-456-7890");
    deal->addCustomer(a);
    deal->addCustomer(b);
    deal->addCustomer(c);
    deal->addCustomer(d);
    deal->addCustomer(e);
    deal->addCustomer(f);
    deal->addCustomer(g);
}

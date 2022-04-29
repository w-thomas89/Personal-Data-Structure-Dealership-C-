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
#include "vehicle.h"

//default constructor
vehicle::vehicle(){
    this->receiveDate = time(0);
}

//first parametrized constructor - takes model only
vehicle::vehicle(string model) {
    this->receiveDate = time(0);
    this->model = model;
}

//overloaded constructor, takes model and color
vehicle::vehicle(string model, string color) {
    this->receiveDate = time(0);
    this->model = model;
    this->color = color;
}

//overloaded constructor, takes model, color, and new/used bool
vehicle::vehicle(string model, string color, bool isNew) {
    this->receiveDate = time(0);
    this->model = model;
    this->color = color;
    this->isNew = isNew;
}

//overloaded constructor, takes model, color, new/used, and tier (base, sr5, gt, etc)
vehicle::vehicle(string model, string color, bool isNew, int tier) {
    this->receiveDate = time(0);
    this->model = model;
    this->color = color;
    this->isNew = isNew;
    this->tier = tier;
}

void vehicle::setModel(string model) {this->model = model;}

void vehicle::setColor(string color) {this->color = color;}

void vehicle::setIsNew(bool isNew) {this->isNew = isNew;}

void vehicle::setTier(int tier) {this->tier = tier;}

//this value is initialized when the dealership receives the vehicle
void vehicle::setReceiveDate(time_t recvd) {this->receiveDate = recvd;}

string vehicle::getModel() {return model;}

string vehicle::getColor() {return color;}

bool vehicle::getIsNew() {return isNew;}

int vehicle::getTier() {return tier;}

time_t vehicle::getReceiveDate() {return receiveDate;}

//this did not get implemented fully - this was designed to include information in the salesList of employee showing the total time spent on lot
//this value should only get initialized when the vhiecle is removed from dealership inventory
void vehicle::setLotTime(time_t time) {this->onLotTime = time;}

string vehicle::toString() {
    return "Model: " + model + " Color: " + color + " Tier: " + to_string(tier);
}

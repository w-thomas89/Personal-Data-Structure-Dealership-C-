#include "vehicle.h"

vehicle::vehicle(){
    this->receiveDate = time(0);
}

vehicle::vehicle(string model) {
    this->receiveDate = time(0);
    this->model = model;
}

vehicle::vehicle(string model, string color) {
    this->receiveDate = time(0);
    this->model = model;
    this->color = color;
}

vehicle::vehicle(string model, string color, bool isNew) {
    this->receiveDate = time(0);
    this->model = model;
    this->color = color;
    this->isNew = isNew;
}

vehicle::vehicle(string model, string color, bool isNew, int tier) {
    this->receiveDate = time(0);
    this->model = model;
    this->color = color;
    this->isNew = isNew;
    this->tier = tier;
}

vehicle::~vehicle(){}

void vehicle::setModel(string model) {
    this->model = model;
}

void vehicle::setColor(string color) {
    this->color = color;
}

void vehicle::setIsNew(bool isNew) {
    this->isNew = isNew;
}

void vehicle::setTier(int tier) {
    this->tier = tier;
}

void vehicle::setReceiveDate(time_t recvd) {
    this->receiveDate = recvd;
}

string vehicle::getModel() {
    return model;
}

string vehicle::getColor() {
    return color;
}

bool vehicle::getIsNew() {
    return isNew;
}

int vehicle::getTier() {
    return tier;
}

time_t vehicle::getReceiveDate() {
    return receiveDate;
}

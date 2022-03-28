#include "vehicle.h"

vehicle::vehicle(){}

vehicle::vehicle(string model) {
    this->model = model;
}

vehicle::vehicle(string model, string color) {
    this->model = model;
    this->color = color;
}

vehicle::vehicle(string model, string color, bool isNew) {
    this->model = model;
    this->color = color;
    this->isNew = isNew;
}

vehicle::vehicle(string model, string color, bool isNew, int tier) {
    this->model = model;
    this->color = color;
    this->isNew = isNew;
    this->tier = tier;
}

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


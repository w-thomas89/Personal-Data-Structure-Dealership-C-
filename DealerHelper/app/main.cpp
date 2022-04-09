#include <iostream>
#include "customer.h"

using namespace std;

int main() {
    string fName, lName, phone;
    fName = "John";
    lName = "Doe";
    phone = "515-123-4567";
    customer test = customer(fName, lName, phone);
    cout << test.toString();
}

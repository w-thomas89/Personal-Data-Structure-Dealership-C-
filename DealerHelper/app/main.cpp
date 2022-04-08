#include <iostream>
#include "dealership.h"

using namespace std;

int main() {
    Dealership test = Dealership("test");
    vehicle car = vehicle("taurus", "blue");
    test.addInventory(car);
    cout << test.getInventory().getColor() << endl;
}

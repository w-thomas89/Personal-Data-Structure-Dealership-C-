#include <iostream>
#include <conio.h>
#include "dealership.h"

using namespace std;

int main() {
    const int numOfOptions = 3;
    const string mainMenu[numOfOptions + 1] = {"Manager", "Staff", "Customer", "Exit"};
    Dealership deal = Dealership("Wanderlust", 50);
    cout << "***Welcome to DealerHelper***" << endl;
    cout << "_____________________________" << endl;
    char choice = 0;
    string input = "";
    while (choice != '4') {
        cout << "Please select your role below:" << endl;
            for (int i = 0; i <= numOfOptions; i++) {
                cout << i + 1 << ") " << mainMenu[i] << endl;
            }
        cin >> input;
        choice = input[0];
        while (choice < '1' || choice > '4') {
            cout << "Invalid Entry. Try again." << endl;
            cin >> input;
            choice = input[0];
        }
        switch(choice) {
        case '1':
            //TODO - add method that performs Manager output of options (dealerhship)
            break;
        case '2':
            //TODO - add method that performs Staff output of options (employee)
            break;
        case '3':
            //TODO - add method that performs customer output of options(customer)
            break;
        case '4':
            return -1;
        }

        cout << "Press anything to return to the menu" << endl;
        getch();
        cout << endl;
    }
}

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


#include <iostream>
#include <conio.h>
#include "dealership.h"
#include "fill_dealer_tool.cpp"

using namespace std;
//function prototypes
void manager(Dealership*);
void staff(Dealership*);
void visitor(Dealership*);

int main() {
    const int numOfOptions = 3;
    const string mainMenu[numOfOptions + 1] = {"Manager", "Staff", "Customer", "Exit"};
    /*
     * HERE WE CREATE THE DEALERSHIP TO BE RAN. THIS CAN BE EASILY ADJUSTED TO WORK OFF
     * MULTIPLE DEALERSHIPS. HOWEVER CREATION OF ONE IS USED FOR PROJECT.
    */
    Dealership deal = Dealership("Wanderlust", 50);
    //below we are going to pre-fill the inventory with some standardize string for testing
    fillInventory(&deal);
    /************************************************/
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
            manager(&deal);
            break;
        case '2':
            staff(&deal);
            break;
        case '3':
            visitor(&deal);
            break;
        case '4':
            return -1;
        }

        cout << "Press anything to return to the menu" << endl;
        getch();
        cout << endl;
    }
}



//This function controls management overview type calls.
//Here you can print lists of salesman, customers, and inventory
//You can also add a salesman, and add a vehicle and perform "payroll"
void manager(Dealership *deal) {
    const string options[8] = {"Print Salesman.", "Add Salesman", "Print Customers", "Print Inventory", "Add Vehicle", "Payroll", "Sort Customer List", "Exit"};
    cout << endl << endl;
    cout << "Welcome to the Wanderlust Management Portal" << endl << endl;
    char choice = 0;
    string input = "";
    while (choice != '7') {
        cout << "Please select an option below:" << endl;
            for (size_t i = 0; i <= 7; i++) {
                cout << i + 1 << ") " << options[i] << endl;
            }
        cin >> input;
        choice = input[0];
        while (choice < '1' || choice > '8') {
            cout << "Invalid Entry. Try again." << endl;
            cin >> input;
            choice = input[0];
        }
        switch(choice) {
            //Print Salesman List
            case '1':
            {
                list<employee> temp = deal->getEmployees();
                for (list<employee>::iterator it = temp.begin(); it != temp.end(); it++) {
                    cout << it->toString() << endl;
                }
                cout << endl;
            }
                break;

            //Add Salesman
            case '2':
            {
                string name;
                cout << "Enter salesman name: " << endl;
                cin >> name;
                employee e = employee(name, deal->getEmployees().size() + 1);
                deal->addEmployee(e);
            }
                break;

            //Print Customer List
            case '3':
            {
                list<customer> temp = deal->getCustomers();
                for (list<customer>::iterator it = temp.begin(); it != temp.end(); it++) {
                    cout << it->toString() << endl;
                }
            }
                break;

            //Print Vehicle Inventory
            case '4':
            {
                list<vehicle> temp = deal->getInventory();
                for (list<vehicle>::iterator it = temp.begin(); it != temp.end(); it++) {
                    cout << it->toString() << endl;
                }
                cout << "\nBackorder in Line: " + deal->getNextBackorder().toString() << endl << endl;
            }
                break;

            //Add vehicle
            case '5':
            {
                string model, color;
                cout << "Model: ";
                cin >> model;
                cout << "\nColor: ";
                cin >> color;
                vehicle v = vehicle(model, color);
                deal->addInventory(v);
            }
                break;

            //Payroll
            case '6':
            {
                cout << "Here we work through the employees and pop from queue of SalesList" << endl;
            }
                break;

            //Sort Customers
            case '7':
                deal->sortCustomers();

            //Exit
            case '8':
                return;
        }
    }
}

void staff(Dealership *deal) {
    const string options[6] = {"Add Customer", "Print Customers", "Print Inventory", "Make Sale", "Print Sales", "Exit"};
    employee emp;
    int ID;
    cout << "Enter your ID: ";
    cin >> ID;
    list<employee> empList = deal->getEmployees();
    for (list<employee>::iterator it = empList.begin(); it != empList.end(); it++) {
        if (it->id == ID) {
            emp = *it;
        }
    }
    cout << endl << endl;
    cout << "Welcome to the Wanderlust Staff Portal" << endl << endl;
    char choice = 0;
    string input = "";
    while (choice != '6') {
        cout << "Please select an option below:" << endl;
            for (size_t i = 0; i <= 5; i++) {
                cout << i + 1 << ") " << options[i] << endl;
            }
        cin >> input;
        choice = input[0];
        while (choice < '1' || choice > '6') {
            cout << "Invalid Entry. Try again." << endl;
            cin >> input;
            choice = input[0];
        }
        switch(choice) {
            //Add customer
            case '1':
            {
                string fName, lName, phone;
                cout << "\nEnter First Name:";
                cin >> fName;
                cout << "\nEnter Last Name:";
                cin >> lName;
                cout << "\nEnter Phone Number:";
                cin >> phone;
                customer c = customer(fName, lName, phone);
                deal->addCustomer(c);
                emp.addToCustomer(c);
            } break;

            //Print Customers
            case '2':
            {
                for (auto e: emp.getCustomerList()) {
                    cout << e.toString();
                }
                cout << endl;
            } break;

            //Print Inventory
            case '3':
            {
                list<vehicle> temp = deal->getInventory();
                for (list<vehicle>::iterator it = temp.begin(); it != temp.end(); it++) {
                    cout << it->toString() << endl;
                }
                cout << "\nBackorder in Line: " + deal->getNextBackorder().toString() << endl << endl;
            } break;

            //Make Sale
            case '4':
            {
                list<vehicle> vehicles = deal->getInventory();
                int i = 0;
                for (list<vehicle>::iterator it = vehicles.begin(); it != vehicles.end(); it++) {
                    cout << "ID:" << i + 1 << " " << it->toString() << endl;
                    i++;
                }
                int choice;
                cout << "Enter the ID of vehicle sold:";
                cin >> choice;
                choice--;
                list<vehicle>::iterator s = vehicles.begin();
                advance(s, choice);
                vehicle sold = *s;
                emp.addToSales(sold);
                deal->makeSale(sold);
            } break;

            //Print Sales
            case '5':
            {
                cout << emp.printSalesList() << endl;
            } break;

            //Exit
            case '6':
                return;
            }

    }

}
void visitor(Dealership *deal) {
    const string options[7] = {"View Inventory", "Set Preferred Cost", "Add Preferred Vehicle", "Change Phone", "Change Name", "Print Prefer list", "Exit"};
    customer cust;  //object used during this instance
    string phone, fName, lName;
    cout << "Please enter your phone number: ";
    cin >> phone;
    cout << "\nPlease enter your First Name: ";
    cin >> fName;
    cout << "\nPlease enter your Last Name: ";
    cin >> lName;
    cin.ignore();
    cust = customer(fName, lName, phone);
    //at this add, the object will search for matching phone numbers and will replace if one is found
    deal->addCustomer(cust);
    cout << "Welcome to Wanderlust Customer Portal" << endl;
    cout << cust.getFirstName() + " " + cust.getLastName() << endl << endl;
    char choice = 0;
    string input = "";
    while (choice != '7') {
        cout << "Please select an option below:" << endl;
            for (size_t i = 0; i <= 6; i++) {
                cout << i + 1 << ") " << options[i] << endl;
            }
        cin >> input;
        choice = input[0];
        while (choice < '1' || choice > '7') {
            cout << "Invalid Entry. Try again." << endl;
            cin >> input;
            choice = input[0];
        }
        switch(choice) {
            //View Inventory
            case '1':
            {
                list<vehicle> temp = deal->getInventory();
                for (list<vehicle>::iterator it = temp.begin(); it != temp.end(); it++) {
                    cout << it->toString() << endl;
                }
                cout << "\nBackorder in Line: " + deal->getNextBackorder().toString() << endl << endl;
            } break;

            //Set Preferred Max Cost
            case '2':
            {
                cout << "Current Maximum Cost is set to: " << cust.getMaxCost() << endl;
                cout << "\nEnter the new desired maximum:";
                int val;
                cin >> val;
                cust.setMaxCost(val);
                cout << "Maximum cost changed to: " << cust.getMaxCost() << endl;
            } break;

            //Add to prefer list vehicle
            case '3':
            {
                list<vehicle> vehicles = deal->getInventory();
                int i = 0;
                for (list<vehicle>::iterator it = vehicles.begin(); it != vehicles.end(); it++) {
                    cout << "ID:" << i + 1 << " " << it->toString() << endl;
                    i++;
                }
                int choice;
                cout << "Enter the ID of vehicle to add:";
                cin >> choice;
                choice--;
                list<vehicle>::iterator s = vehicles.begin();
                advance(s, choice);
                vehicle chosen = *s;
                cout << "Enter the priority in which you want this vehicle:";
                int priority;
                cin >> priority;
                cust.addPreferedVehicle(chosen, priority);
            } break;

            //change phone
            case '4':
            {
                cout << "Phone Number:" << cust.getPhone() << endl;
                cout << "Change to:";
                string phone;
                cin >> phone;
                cust.setPhone(phone);
            } break;

            //change name
            case '5':
            {
                cout << "Current name:" << cust.getFirstName() << " " << cust.getLastName() << endl;
                string fName, lName;
                cout << "New First Name:";
                cin >> fName;
                cout << "New Last Name:";
                cin >> lName;
                cust.setFirstName(fName);
                cust.setLastName(lName);
            } break;

            //print list
            case '6':
            {
                cout << cust.printPreferList() << endl;
            } break;

            //exit
            case '7':
                return;
        }
    }
}

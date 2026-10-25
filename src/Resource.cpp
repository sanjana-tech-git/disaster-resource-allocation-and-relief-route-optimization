
#include <iostream>
#include "../include/Resource.h"

using namespace std;

Resource resources[100];
int totalResources = 0;

void addResource() {
    if (totalResources == 100) {
        cout << "Resource limit reached!\n";
        return;
    }

    int id;
    cout << "\nEnter Resource ID: ";
    cin >> id;

    // Check whether this resource already exists.
    for (int i = 0; i < totalResources; i++) {
        if (resources[i].id == id) {
            cout << "Resource ID already exists.\n";
            return;
        }
    }

    resources[totalResources].id = id;

    cout << "Enter Resource Name: ";
    cin >> resources[totalResources].name;

    cout << "Enter Available Quantity: ";
    cin >> resources[totalResources].quantity;

    if (resources[totalResources].quantity < 0) {
        cout << "Quantity cannot be negative.\n";
        return;
    }

    totalResources++;

    cout << "Resource added successfully!\n";
}

void displayResources() {
    if (totalResources == 0) {
        cout << "\nNo resources available.\n";
        return;
    }

    cout << "\n===== AVAILABLE RESOURCES =====\n";

    for (int i = 0; i < totalResources; i++) {
        cout << "\nResource ID: " << resources[i].id;
        cout << "\nResource Name: " << resources[i].name;
        cout << "\nAvailable Quantity: "
             << resources[i].quantity;
        cout << "\n--------------------------\n";
    }
}


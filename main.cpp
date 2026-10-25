
#include "include/Resource.h"
#include <iostream>
#include "include/Area.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n===== DISASTER MANAGEMENT SYSTEM =====\n";
        cout << "1. Register affected area\n";
        cout << "2. Display affected areas\n";
        cout << "3. Add resource\n";
        cout << "4. Display resources\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addArea();
                break;

            case 2:
                displayAreas();
                break;
            case 3:
                addResource();
                break;

            case 4:
                displayResources();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

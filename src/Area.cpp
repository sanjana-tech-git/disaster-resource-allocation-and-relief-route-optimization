
#include <iostream>
#include "../include/Area.h"

using namespace std;

// Store a maximum of 100 affected areas.
Area areas[100];
int totalAreas = 0;

void addArea() {
    if (totalAreas == 100) {
        cout << "Area limit reached!\n";
        return;
    }

    cout << "\nEnter Area ID: ";
    cin >> areas[totalAreas].id;

    cout << "Enter Area Name: ";
    cin >> areas[totalAreas].name;

    cout << "Enter Affected Population: ";
    cin >> areas[totalAreas].population;

    cout << "Select Severity:\n";
    cout << "1. HIGH\n";
    cout << "2. MEDIUM\n";
    cout << "3. LOW\n";
    cout << "Enter choice: ";
    cin >> areas[totalAreas].severity;

    if (areas[totalAreas].population < 0 ||
        areas[totalAreas].severity < 1 ||
        areas[totalAreas].severity > 3) {
        cout << "Invalid details. Area not added.\n";
        return;
    }

    totalAreas++;

    cout << "Area registered successfully!\n";
}

void displayAreas() {
    if (totalAreas == 0) {
        cout << "\nNo areas registered yet.\n";
        return;
    }

    cout << "\n===== REGISTERED AREAS =====\n";

    for (int i = 0; i < totalAreas; i++) {
        cout << "\nArea ID: " << areas[i].id;
        cout << "\nArea Name: " << areas[i].name;
        cout << "\nPopulation: " << areas[i].population;

        cout << "\nSeverity: ";

        if (areas[i].severity == 1) {
            cout << "HIGH";
        } else if (areas[i].severity == 2) {
            cout << "MEDIUM";
        } else {
            cout << "LOW";
        }

        cout << "\n--------------------------\n";
    }
}

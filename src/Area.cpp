
#include <iostream>
#include <fstream>
#include "../include/Area.h"
#include "../include/BST.h"

using namespace std;

// Store a maximum of 100 affected areas.
Area areas[100];
int totalAreas = 0;

// Save areas in file
void saveAreas() {
    ofstream file("data/areas.txt");

    if (!file) {
        cout << "Error saving area data!\n";
        return;
    }

    for (int i = 0; i < totalAreas; i++) {
        file << areas[i].id << " "
             << areas[i].name << " "
             << areas[i].population << " "
             << areas[i].severity << endl;
    }

    file.close();
}

// Load areas from file
void loadAreas() {
    ifstream file("data/areas.txt");

    if (!file) {
        return;
    }

    totalAreas = 0;

    while (totalAreas < 100 &&
       file >> areas[totalAreas].id
            >> areas[totalAreas].name
            >> areas[totalAreas].population
            >> areas[totalAreas].severity) {

    insertArea(areas[totalAreas].id);

    totalAreas++;
}

    file.close();
}

// Add new area
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

    if (areas[totalAreas].population <= 0 ||
        areas[totalAreas].severity < 1 ||
        areas[totalAreas].severity > 3) {

        cout << "Invalid details. Area not added.\n";
        return;
    }
    insertArea(areas[totalAreas].id);
    totalAreas++;

    saveAreas();

    cout << "Area registered successfully!\n";
}

// Display areas
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

int getAreaCount()
{
    return totalAreas;
}

Area getArea(int index)
{
    return areas[index];
}

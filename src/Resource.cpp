
#include <iostream>
#include <fstream>
#include "../include/Resource.h"
#include "../include/HashTable.h"

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

    if (id <= 0) {
        cout << "Resource ID must be positive.\n";
        return;
    }

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
    insertResource(resources[totalResources].id, totalResources);

    totalResources++;

    saveResources();
    

    cout << "Resource added and saved successfully!\n";
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

int getResourceCount() {
    return totalResources;
}

int getResourceId(int index) {
    return resources[index].id;
}

int getResourceQuantity(int index) {
    return resources[index].quantity;
}

void updateResourceQuantity(int index, int quantity) {
    if (index >= 0 && index < totalResources && quantity >= 0) {
        resources[index].quantity = quantity;
        saveResources();
    }
}

void saveResources() {
    ofstream file("data/resources.txt");

    if (!file) {
        cout << "Error: Could not save resources.\n";
        return;
    }

    for (int i = 0; i < totalResources; i++) {
        file << resources[i].id << " "
             << resources[i].name << " "
             << resources[i].quantity << "\n";
    }

    file.close();
}

void loadResources() {

    ifstream file("data/resources.txt");

    if (!file) {
        return;
    }

    totalResources = 0;

    while (totalResources < 100 &&
           file >> resources[totalResources].id
                >> resources[totalResources].name
                >> resources[totalResources].quantity) {

        if (resources[totalResources].id <= 0 ||
            resources[totalResources].quantity < 0) {

            cout << "Invalid resource data found in file.\n";

            totalResources = 0;
            file.close();
            return;
        }

        // Insert loaded resource into Hash Table
        insertResource(
            resources[totalResources].id,
            totalResources
        );

        totalResources++;
    }

    file.close();

    cout << "Resources loaded successfully.\n";
}
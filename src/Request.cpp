
#include <iostream>
#include "../include/Request.h"

using namespace std;

Request* head = nullptr;
int nextRequestId = 1;

void addRequest() {
    Request* newRequest = new Request;

    newRequest->requestId = nextRequestId++;

    cout << "\nEnter Area ID: ";
    cin >> newRequest->areaId;

    cout << "Enter Resource ID: ";
    cin >> newRequest->resourceId;

    cout << "Enter Required Quantity: ";
    cin >> newRequest->quantity;

    cout << "Select Priority:\n";
    cout << "1. HIGH\n";
    cout << "2. MEDIUM\n";
    cout << "3. LOW\n";
    cout << "Enter choice: ";
    cin >> newRequest->priority;

    if (newRequest->areaId <= 0 ||
        newRequest->resourceId <= 0 ||
        newRequest->quantity <= 0 ||
        newRequest->priority < 1 ||
        newRequest->priority > 3) {

        cout << "Invalid request details.\n";
        delete newRequest;
        return;
    }

    newRequest->next = nullptr;

    if (head == nullptr) {
        head = newRequest;
    } else {
        Request* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newRequest;
    }

    cout << "Request added successfully!\n";
}

void displayRequests() {
    if (head == nullptr) {
        cout << "\nNo requests available.\n";
        return;
    }

    Request* current = head;

    cout << "\n===== RESOURCE REQUESTS =====\n";

    while (current != nullptr) {
        cout << "\nRequest ID: " << current->requestId;
        cout << "\nArea ID: " << current->areaId;
        cout << "\nResource ID: " << current->resourceId;
        cout << "\nQuantity: " << current->quantity;

        cout << "\nPriority: ";

        if (current->priority == 1) {
            cout << "HIGH";
        } else if (current->priority == 2) {
            cout << "MEDIUM";
        } else {
            cout << "LOW";
        }

        cout << "\n--------------------------\n";

        current = current->next;
    }
}

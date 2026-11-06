
#include <iostream>
#include <fstream>
#include "../include/Request.h"

using namespace std;

Request* head = nullptr;
int nextRequestId = 1;

// Save all linked-list requests into a file.
void saveRequests() {
    ofstream file("data/requests.txt");

    if (!file) {
        cout << "Error saving request data!\n";
        return;
    }

    Request* current = head;

    while (current != nullptr) {
        file << current->requestId << " "
             << current->areaId << " "
             << current->resourceId << " "
             << current->quantity << " "
             << current->priority << endl;

        current = current->next;
    }

    file.close();
}

// Load requests from the file into the linked list.
void loadRequests() {
    ifstream file("data/requests.txt");

    if (!file) {
        return;
    }

    int requestId, areaId, resourceId, quantity, priority;
    int maxId = 0;

    while (file >> requestId >> areaId >> resourceId
                >> quantity >> priority) {

        if (requestId <= 0 || areaId <= 0 ||
            resourceId <= 0 || quantity < 0 ||
            priority < 1 || priority > 3) {
            continue;
        }

        Request* newRequest = new Request;

        newRequest->requestId = requestId;
        newRequest->areaId = areaId;
        newRequest->resourceId = resourceId;
        newRequest->quantity = quantity;
        newRequest->priority = priority;
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

        if (requestId > maxId) {
            maxId = requestId;
        }
    }

    nextRequestId = maxId + 1;

    file.close();
}

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
        nextRequestId--;
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

    saveRequests();

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

int getRequestCount() {
    int count = 0;
    Request* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int getRequestId(int index) {
    Request* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    return current->requestId;
}

int getRequestAreaId(int index) {
    Request* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    return current->areaId;
}

int getRequestResourceId(int index) {
    Request* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    return current->resourceId;
}

int getRequestQuantity(int index) {
    Request* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    return current->quantity;
}

int getRequestPriority(int index) {
    Request* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    return current->priority;
}

void updateRequestQuantity(int index, int quantity) {
    Request* current = head;

    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        current->quantity = quantity;
        saveRequests();
    }
}

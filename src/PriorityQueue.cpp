
#include <iostream>
#include "../include/PriorityQueue.h"

using namespace std;

PriorityRequest requests[100];
int requestCount = 0;

// Add request
void addPriorityRequest() {

    if (requestCount == 100) {
        cout << "Priority queue is full.\n";
        return;
    }

    PriorityRequest request;

    cout << "\nEnter Request ID: ";
    cin >> request.requestId;

    cout << "Enter Area ID: ";
    cin >> request.areaId;

    cout << "Enter Resource ID: ";
    cin >> request.resourceId;

    cout << "Enter Quantity: ";
    cin >> request.quantity;

    cout << "Priority (1=HIGH, 2=MEDIUM, 3=LOW): ";
    cin >> request.priority;

    if (request.requestId <= 0 ||
        request.areaId <= 0 ||
        request.resourceId <= 0 ||
        request.quantity <= 0 ||
        request.priority < 1 ||
        request.priority > 3) {

        cout << "Invalid request details.\n";
        return;
    }

    requests[requestCount] = request;
    requestCount++;

    cout << "Request added to priority queue.\n";
}

// Display requests according to priority
void displayPriorityQueue() {

    if (requestCount == 0) {
        cout << "\nPriority queue is empty.\n";
        return;
    }

    PriorityRequest temp[100];

    // Copy original queue
    for (int i = 0; i < requestCount; i++) {
        temp[i] = requests[i];
    }

    // Bubble sort according to priority
    for (int i = 0; i < requestCount - 1; i++) {

        for (int j = 0; j < requestCount - i - 1; j++) {

            if (temp[j].priority > temp[j + 1].priority) {

                PriorityRequest t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    cout << "\n===== PRIORITY QUEUE =====\n";

    for (int i = 0; i < requestCount; i++) {

        cout << "\nRequest ID: " << temp[i].requestId;
        cout << "\nArea ID: " << temp[i].areaId;
        cout << "\nResource ID: " << temp[i].resourceId;
        cout << "\nQuantity: " << temp[i].quantity;
        cout << "\nPriority: " << temp[i].priority;
        cout << "\n----------------------\n";
    }
}

// Process highest priority request
void processNextRequest() {

    if (requestCount == 0) {
        cout << "\nNo requests to process.\n";
        return;
    }

    int highestIndex = 0;

    for (int i = 1; i < requestCount; i++) {

        if (requests[i].priority < requests[highestIndex].priority) {
            highestIndex = i;
        }
    }

    cout << "\nProcessing Request ID: "
         << requests[highestIndex].requestId;

    cout << "\nPriority: "
         << requests[highestIndex].priority << "\n";

    // Remove processed request
    for (int i = highestIndex; i < requestCount - 1; i++) {
        requests[i] = requests[i + 1];
    }

    requestCount--;

    cout << "Request removed from priority queue.\n";
}

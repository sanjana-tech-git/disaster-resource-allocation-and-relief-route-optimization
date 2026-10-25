
#include <iostream>
#include "../include/Allocation.h"
#include "../include/Resource.h"
#include "../include/Request.h"

using namespace std;

void allocateResources() {
    int totalRequests = getRequestCount();

    if (totalRequests == 0) {
        cout << "\nNo requests available for allocation.\n";
        return;
    }

    cout << "\n===== RESOURCE ALLOCATION REPORT =====\n";

    // Priority 1 = HIGH, 2 = MEDIUM, 3 = LOW
    for (int priority = 1; priority <= 3; priority++) {

        for (int i = 0; i < totalRequests; i++) {

            if (getRequestPriority(i) != priority) {
                continue;
            }

            int requestId = getRequestId(i);
            int resourceId = getRequestResourceId(i);
            int required = getRequestQuantity(i);

            if (required <= 0) {
                continue;
            }

            int resourceIndex = -1;

            // Find the resource requested by this area.
            for (int j = 0; j < getResourceCount(); j++) {
                if (getResourceId(j) == resourceId) {
                    resourceIndex = j;
                    break;
                }
            }

            cout << "\nRequest ID: " << requestId;
            cout << "\nPriority: ";

            if (priority == 1) {
                cout << "HIGH";
            } else if (priority == 2) {
                cout << "MEDIUM";
            } else {
                cout << "LOW";
            }

            if (resourceIndex == -1) {
                cout << "\nResource not found.";
                cout << "\nAllocated: 0\n";
                continue;
            }

            int available = getResourceQuantity(resourceIndex);
            int allocated;

            // Allocate only the available quantity.
            if (available >= required) {
                allocated = required;
            } else {
                allocated = available;
            }

            // Reduce the warehouse stock.
            updateResourceQuantity(
                resourceIndex,
                available - allocated
            );

            // Keep the unfulfilled quantity in the request.
            updateRequestQuantity(
                i,
                required - allocated
            );

            cout << "\nRequired: " << required;
            cout << "\nAllocated: " << allocated;
            cout << "\nRemaining need: " << required - allocated;
            cout << "\nStock left: "
                 << getResourceQuantity(resourceIndex) << "\n";
        }
    }

    cout << "\n===== ALLOCATION COMPLETE =====\n";
}

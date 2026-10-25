#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct PriorityRequest {
    int requestId;
    int areaId;
    int resourceId;
    int quantity;
    int priority;
};

void addPriorityRequest();
void processNextRequest();
void displayPriorityQueue();

#endif

#ifndef REQUEST_H
#define REQUEST_H

struct Request {
    int requestId;
    int areaId;
    int resourceId;
    int quantity;
    int priority;
    Request* next;
};

void addRequest();
void displayRequests();

#endif

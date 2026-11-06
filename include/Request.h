
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

int getRequestCount();
int getRequestId(int index);
int getRequestAreaId(int index);
int getRequestResourceId(int index);
int getRequestQuantity(int index);
int getRequestPriority(int index);

void updateRequestQuantity(int index, int quantity);
void saveRequests();
void loadRequests();

#endif

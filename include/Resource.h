
#ifndef RESOURCE_H
#define RESOURCE_H

struct Resource {
    int id;
    char name[50];
    int quantity;
};

void addResource();
void displayResources();

#endif

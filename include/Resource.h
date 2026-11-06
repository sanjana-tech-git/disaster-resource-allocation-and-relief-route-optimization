
#ifndef RESOURCE_H
#define RESOURCE_H

struct Resource {
    int id;
    char name[50];
    int quantity;
};

void addResource();
void displayResources();
int getResourceCount();
int getResourceId(int index);
int getResourceQuantity(int index);
void updateResourceQuantity(int index, int quantity);

void saveResources();
void loadResources();
#endif

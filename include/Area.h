
#ifndef AREA_H
#define AREA_H

struct Area {
    int id;
    char name[50];
    int population;
    int severity;
};

// These functions manage affected areas.
void addArea();
void displayAreas();

#endif

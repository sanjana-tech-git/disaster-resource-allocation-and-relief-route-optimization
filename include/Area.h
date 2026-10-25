
#ifndef AREA_H
#define AREA_H

struct Area {
    int id;
    char name[50];
    int population;
    int severity;
};

void addArea();
void displayAreas();

#endif

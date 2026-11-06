
#include <iostream>
#include "../include/Area.h"
#include "../include/Sorting.h"

using namespace std;

// Display sorted areas
void displaySortedAreas(Area temp[], int n)
{
    cout << "\nID\tName\t\tPopulation\tSeverity\n";

    for (int i = 0; i < n; i++)
    {
        cout << temp[i].id << "\t"
             << temp[i].name << "\t\t"
             << temp[i].population << "\t\t"
             << temp[i].severity << endl;
    }
}

// Bubble Sort: Severity (High to Low)
void sortAreasBySeverity()
{
    int n = getAreaCount();
    Area temp[100];

    for (int i = 0; i < n; i++)
        temp[i] = getArea(i);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (temp[j].severity < temp[j + 1].severity)
            {
                Area t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    cout << "\nAreas Sorted by Severity:\n";
    displaySortedAreas(temp, n);
}

// Selection Sort: Population (High to Low)
void sortAreasByPopulation()
{
    int n = getAreaCount();
    Area temp[100];

    for (int i = 0; i < n; i++)
        temp[i] = getArea(i);

    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (temp[j].population > temp[maxIndex].population)
                maxIndex = j;
        }

        Area t = temp[i];
        temp[i] = temp[maxIndex];
        temp[maxIndex] = t;
    }

    cout << "\nAreas Sorted by Population:\n";
    displaySortedAreas(temp, n);
}

// Insertion Sort: Area ID (Low to High)
void sortAreasByID()
{
    int n = getAreaCount();
    Area temp[100];

    for (int i = 0; i < n; i++)
        temp[i] = getArea(i);

    for (int i = 1; i < n; i++)
    {
        Area key = temp[i];
        int j = i - 1;

        while (j >= 0 && temp[j].id > key.id)
        {
            temp[j + 1] = temp[j];
            j--;
        }

        temp[j + 1] = key;
    }

    cout << "\nAreas Sorted by ID:\n";
    displaySortedAreas(temp, n);
}


#include <iostream>
#include "../include/UnionFind.h"

using namespace std;

const int MAX_DSU = 100;

int parent[MAX_DSU + 1];
int rankArr[MAX_DSU + 1];

// Initially, every element belongs to its own set
void initializeDSU()
{
    for (int i = 1; i <= MAX_DSU; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

// Find the representative of a set
// Path Compression is used here
int findSet(int x)
{
    if (x < 1 || x > MAX_DSU)
        return -1;

    if (parent[x] != x)
    {
        parent[x] = findSet(parent[x]);
    }

    return parent[x];
}

// Merge two sets
// Union by Rank is used here
void unionSets(int a, int b)
{
    int rootA = findSet(a);
    int rootB = findSet(b);

    if (rootA == -1 || rootB == -1)
    {
        cout << "Invalid Area ID!" << endl;
        return;
    }

    if (rootA == rootB)
    {
        cout << "Both areas are already in the same group." << endl;
        return;
    }

    if (rankArr[rootA] < rankArr[rootB])
    {
        parent[rootA] = rootB;
    }
    else if (rankArr[rootA] > rankArr[rootB])
    {
        parent[rootB] = rootA;
    }
    else
    {
        parent[rootB] = rootA;
        rankArr[rootA]++;
    }

    cout << "Groups merged successfully!" << endl;
}

// Display all elements and their representatives
void displayDSU()
{
    cout << "\nArea ID\tGroup Representative\n";

    for (int i = 1; i <= MAX_DSU; i++)
    {
        cout << i << "\t" << findSet(i) << endl;
    }
}

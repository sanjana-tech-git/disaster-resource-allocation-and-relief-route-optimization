
#include <iostream>
#include "../include/Graph.h"
#include "../include/UnionFind.h"
#include "../include/Kruskal.h"

using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

void kruskalMST()
{
    int n = getRoadCount();

    if (n == 0)
    {
        cout << "No roads available!" << endl;
        return;
    }

    Edge edges[1000];

    // Copy roads from graph
    for (int i = 0; i < n; i++)
    {
        getRoad(i, edges[i].u, edges[i].v, edges[i].weight);
    }

    // Sort edges by ascending weight (Bubble Sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize Union-Find
    initializeDSU();

    int totalDistance = 0;
    int selectedEdges = 0;

    cout << "\n===== KRUSKAL'S MST =====\n";

    for (int i = 0; i < n; i++)
    {
        int rootU = findSet(edges[i].u);
        int rootV = findSet(edges[i].v);

        if (rootU != rootV)
        {
            cout << edges[i].u << " -- "
                 << edges[i].v << " : "
                 << edges[i].weight << " km" << endl;

            unionSets(edges[i].u, edges[i].v);

            totalDistance += edges[i].weight;
            selectedEdges++;
        }
    }

    cout << "\nTotal Minimum Distance: "
         << totalDistance << " km" << endl;

    if (selectedEdges < 1)
        cout << "No MST could be formed." << endl;
    else
        cout << "Selected Roads: " << selectedEdges << endl;
}


#include <iostream>
#include <fstream>
#include "../include/Graph.h"

using namespace std;

#define MAX 100
#define INF 1000000000

// Adjacency Matrix
int graph[MAX + 1][MAX + 1] = {0};
// Save road connections into a file
void saveGraph() {
    ofstream file("data/roads.txt");

    if (!file) {
        cout << "Error saving road data!\n";
        return;
    }

    for (int i = 1; i <= MAX; i++) {
        for (int j = i + 1; j <= MAX; j++) {

            if (graph[i][j] != 0) {
                file << i << " "
                     << j << " "
                     << graph[i][j] << endl;
            }
        }
    }

    file.close();
}

// Load road connections from a file
void loadGraph() {
    ifstream file("data/roads.txt");

    if (!file) {
        return;
    }

    int area1, area2, distance;

    while (file >> area1 >> area2 >> distance) {

        if (area1 >= 1 && area1 <= MAX &&
            area2 >= 1 && area2 <= MAX &&
            area1 != area2 && distance > 0) {

            graph[area1][area2] = distance;
            graph[area2][area1] = distance;
        }
    }

    file.close();
}

// Add a road between two areas
void addRoad() {
    int area1, area2, distance;

    cout << "\nEnter First Area ID: ";
    cin >> area1;

    cout << "Enter Second Area ID: ";
    cin >> area2;

    cout << "Enter Road Distance (in km): ";
    cin >> distance;

    if (area1 < 1 || area1 > MAX ||
        area2 < 1 || area2 > MAX ||
        area1 == area2 || distance <= 0) {

        cout << "Invalid road details!\n";
        return;
    }

    // Undirected graph
    graph[area1][area2] = distance;
    graph[area2][area1] = distance;
    saveGraph();

    cout << "Road added successfully!\n";
}

// Display all roads
void displayGraph() {
    cout << "\n===== ROAD NETWORK =====\n";

    bool found = false;

    for (int i = 1; i <= MAX; i++) {
        for (int j = i + 1; j <= MAX; j++) {

            if (graph[i][j] != 0) {
                cout << "Area " << i
                     << " <--> Area " << j
                     << " : " << graph[i][j] << " km\n";

                found = true;
            }
        }
    }

    if (!found) {
        cout << "No roads available.\n";
    }
}

// BFS Traversal
void bfs() {
    int start;

    cout << "\nEnter Starting Area ID: ";
    cin >> start;

    if (start < 1 || start > MAX) {
        cout << "Invalid Area ID!\n";
        return;
    }

    int queue[MAX + 1];
    int front = 0, rear = 0;
    bool visited[MAX + 1] = {false};

    queue[rear++] = start;
    visited[start] = true;

    cout << "\nBFS Traversal: ";

    while (front < rear) {
        int current = queue[front++];

        cout << current << " ";

        for (int i = 1; i <= MAX; i++) {

            if (graph[current][i] != 0 &&
                !visited[i]) {

                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

// DFS Helper Function
void dfsVisit(int vertex, bool visited[]) {
    visited[vertex] = true;

    cout << vertex << " ";

    for (int i = 1; i <= MAX; i++) {

        if (graph[vertex][i] != 0 &&
            !visited[i]) {

            dfsVisit(i, visited);
        }
    }
}

// DFS Traversal
void dfs() {
    int start;

    cout << "\nEnter Starting Area ID: ";
    cin >> start;

    if (start < 1 || start > MAX) {
        cout << "Invalid Area ID!\n";
        return;
    }

    bool visited[MAX + 1] = {false};

    cout << "\nDFS Traversal: ";

    dfsVisit(start, visited);

    cout << endl;
}

// Dijkstra's Shortest Path Algorithm
void dijkstra() {
    int source, destination;

    cout << "\nEnter Starting Area ID: ";
    cin >> source;

    cout << "Enter Destination Area ID: ";
    cin >> destination;

    if (source < 1 || source > MAX ||
        destination < 1 || destination > MAX) {

        cout << "Invalid Area ID!\n";
        return;
    }

    int dist[MAX + 1];
    int parent[MAX + 1];
    bool visited[MAX + 1] = {false};

    for (int i = 1; i <= MAX; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 1; count <= MAX; count++) {

        int u = -1;
        int minimum = INF;

        // Find minimum distance vertex
        for (int i = 1; i <= MAX; i++) {

            if (!visited[i] && dist[i] < minimum) {
                minimum = dist[i];
                u = i;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = true;

        // Update neighboring vertices
        for (int v = 1; v <= MAX; v++) {

            if (graph[u][v] != 0 &&
                !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[destination] == INF) {
        cout << "No route available!\n";
        return;
    }

    cout << "\nShortest Distance: "
         << dist[destination] << " km\n";

    // Reconstruct shortest path
    int path[MAX + 1];
    int pathCount = 0;

    int current = destination;

    while (current != -1) {
        path[pathCount++] = current;
        current = parent[current];
    }

    cout << "Shortest Route: ";

    for (int i = pathCount - 1; i >= 0; i--) {
        cout << path[i];

        if (i != 0) {
            cout << " -> ";
        }
    }

    cout << endl;
}
int getRoadCount()
{
    int count = 0;

    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i + 1; j <= MAX; j++)
        {
            if (graph[i][j] > 0)
            {
                count++;
            }
        }
    }

    return count;
}

void getRoad(int index, int &u, int &v, int &weight)
{
    int count = 0;

    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i + 1; j <= MAX; j++)
        {
            if (graph[i][j] > 0)
            {
                if (count == index)
                {
                    u = i;
                    v = j;
                    weight = graph[i][j];
                    return;
                }

                count++;
            }
        }
    }

    u = -1;
    v = -1;
    weight = -1;
}
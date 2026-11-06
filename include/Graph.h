#ifndef GRAPH_H
#define GRAPH_H

void addRoad();
void displayGraph();
void bfs();
void dfs();
void dijkstra();

void saveGraph();
void loadGraph();

// Functions for Kruskal's Algorithm
int getRoadCount();
void getRoad(int index, int &u, int &v, int &weight);

#endif
# Disaster Resource Allocation & Relief Route Optimization System

A C++17-based Disaster Management System designed to manage affected areas, available resources, emergency requests, and relief transportation routes.

## About the Project

During natural disasters, proper resource allocation and efficient transportation routes are important for providing timely assistance.

This project helps simulate disaster relief operations by managing affected areas, tracking available resources, processing emergency requests based on priority, and finding optimized routes between areas.

## Features

- **Area Management:** Register and display disaster-affected areas.
- **Resource Management:** Add, view, and update available resources.
- **Request Management:** Maintain resource requests using a linked list.
- **Priority Queue:** Process high-priority requests before medium- and low-priority requests.
- **Resource Allocation:** Allocate available resources to emergency requests.
- **Graph Representation:** Represent the road network using an adjacency matrix.
- **BFS:** Traverse connected areas using Breadth First Search.
- **DFS:** Traverse connected areas using Depth First Search.
- **Dijkstra's Algorithm:** Find the shortest relief route.
- **Hash Table:** Search resources efficiently using hashing and separate chaining.
- **Binary Search Tree:** Search areas and perform tree traversals.
- **Sorting Algorithms:** Sort areas by severity, population, and ID.
- **Union-Find:** Manage connected groups of areas.
- **Kruskal's Algorithm:** Find the Minimum Spanning Tree for the relief road network.
- **File Handling:** Store and retrieve project data using text files.

## Technologies Used

- Language: C++
- Standard: C++17
- IDE: Visual Studio Code
- Compiler: GCC / MinGW
- Data Storage: Text files

## Data Structures and Algorithms

| Data Structure / Algorithm | Application |
|---|---|
| Array | Area and resource storage |
| Linked List | Resource requests |
| Priority Queue | Emergency request processing |
| Graph | Road network |
| BFS | Breadth-first traversal |
| DFS | Depth-first traversal |
| Dijkstra | Shortest path |
| Hash Table | Resource searching |
| Binary Search Tree | Area searching |
| Bubble Sort | Severity sorting |
| Selection Sort | Population sorting |
| Insertion Sort | Area ID sorting |
| Union-Find | Connected components |
| Kruskal | Minimum Spanning Tree |

## Project Structure

```text
DisasterReliefSystem/
│
├── data/
│   ├── areas.txt
│   ├── resources.txt
│   ├── requests.txt
│   └── roads.txt
│
├── include/
│   ├── Area.h
│   ├── Resource.h
│   ├── Request.h
│   ├── PriorityQueue.h
│   ├── Allocation.h
│   ├── Graph.h
│   ├── HashTable.h
│   ├── BST.h
│   ├── Sorting.h
│   ├── UnionFind.h
│   ├── Kruskal.h
│   └── FileManager.h
│
├── src/
│   ├── Area.cpp
│   ├── Resource.cpp
│   ├── Request.cpp
│   ├── PriorityQueue.cpp
│   ├── Allocation.cpp
│   ├── Graph.cpp
│   ├── HashTable.cpp
│   ├── BST.cpp
│   ├── Sorting.cpp
│   ├── UnionFind.cpp
│   ├── Kruskal.cpp
│   └── FileManager.cpp
│
├── main.cpp
├── .gitignore
└── README.md
```

## How to Run the Project

### Requirements

- Windows, Linux, or macOS
- GCC compiler with C++17 support
- Git (for cloning the repository)

### 1. Clone the repository

```bash
git clone https://github.com/sanjana-tech-git/disaster-resource-allocation-and-relief-route-optimization.git
```

### 2. Open the project folder

```bash
cd disaster-resource-allocation-and-relief-route-optimization
```

### 3. Compile the project

On Windows using PowerShell:

```powershell
g++ -std=c++17 main.cpp src/Area.cpp src/Resource.cpp src/Request.cpp src/PriorityQueue.cpp src/Allocation.cpp src/Graph.cpp src/HashTable.cpp src/BST.cpp src/Sorting.cpp src/UnionFind.cpp src/Kruskal.cpp -o disaster.exe
```

### 4. Run the project

```powershell
.\disaster.exe
```

On Linux/macOS, run the compiled executable using:

```bash
./disaster
```

## Data Storage

The project uses text files inside the `data/` directory to store areas, resources, requests, and road connections.

Keep the `data` folder in the project directory when running the program so that file operations can work correctly.

## Learning Outcomes

- Understanding and implementing data structures in C++.
- Applying graph algorithms to disaster relief route optimization.
- Managing emergency requests using priority-based processing.
- Understanding file handling and modular programming.
- Combining multiple data structures and algorithms in a real-world problem.

## Author

**Sanjana Sharma**

B.Tech – Computer Science and Engineering (AI & ML)

Graphic Era Hill University

## Project Purpose

This project is developed as an academic project to demonstrate the practical application of Data Structures and Algorithms in disaster management and emergency relief operations.

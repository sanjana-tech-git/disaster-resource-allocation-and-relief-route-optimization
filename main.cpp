
#include <iostream>
#include "include/Area.h"
#include "include/Resource.h"
#include "include/Request.h"
#include "include/PriorityQueue.h"
#include "include/Allocation.h"
#include "include/Graph.h"
#include "include/HashTable.h"
#include "include/BST.h"
#include "include/Sorting.h"
#include "include/UnionFind.h"
#include "include/Kruskal.h"

using namespace std;


// ==========================================
// 1. AREA MANAGEMENT MENU
// ==========================================

void areaMenu()
{
    int choice;

    do
    {
        cout << "\n========== AREA MANAGEMENT ==========\n";
        cout << "1. Register Affected Area\n";
        cout << "2. Display Affected Areas\n";
        cout << "3. Search Area using BST\n";
        cout << "4. BST Traversals\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addArea();
                break;

            case 2:
                displayAreas();
                break;

            case 3:
            {
                int id;

                cout << "Enter Area ID to search: ";
                cin >> id;

                if (searchArea(id))
                    cout << "\nArea Found in BST!\n";
                else
                    cout << "\nArea Not Found!\n";

                break;
            }

            case 4:
                cout << "\n========== BST TRAVERSALS ==========\n";
                inorder();
                preorder();
                postorder();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 2. RESOURCE MANAGEMENT MENU
// ==========================================

void resourceMenu()
{
    int choice;

    do
    {
        cout << "\n========== RESOURCE MANAGEMENT ==========\n";
        cout << "1. Add Resource\n";
        cout << "2. Display Resources\n";
        cout << "3. Search Resource by ID\n";
        cout << "4. Display Hash Table\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addResource();
                break;

            case 2:
                displayResources();
                break;

            case 3:
            {
                int id;

                cout << "Enter Resource ID to search: ";
                cin >> id;

                int index = searchResource(id);

                if (index != -1)
                {
                    cout << "\nResource Found!\n";
                    cout << "Resource ID: " << getResourceId(index);
                    cout << "\nAvailable Quantity: "
                         << getResourceQuantity(index) << "\n";
                }
                else
                {
                    cout << "\nResource Not Found!\n";
                }

                break;
            }

            case 4:
                displayHashTable();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 3. REQUEST MANAGEMENT MENU
// ==========================================

void requestMenu()
{
    int choice;

    do
    {
        cout << "\n========== REQUEST MANAGEMENT ==========\n";
        cout << "1. Add Resource Request\n";
        cout << "2. Display Resource Requests\n";
        cout << "3. Add Priority Request\n";
        cout << "4. Display Priority Queue\n";
        cout << "5. Process Next Request\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addRequest();
                break;

            case 2:
                displayRequests();
                break;

            case 3:
                addPriorityRequest();
                break;

            case 4:
                displayPriorityQueue();
                break;

            case 5:
                processNextRequest();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 4. RESOURCE ALLOCATION MENU
// ==========================================

void allocationMenu()
{
    int choice;

    do
    {
        cout << "\n========== RESOURCE ALLOCATION ==========\n";
        cout << "1. Allocate Resources\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                allocateResources();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 5. RELIEF ROUTE OPTIMIZATION MENU
// ==========================================

void routeMenu()
{
    int choice;

    do
    {
        cout << "\n========== RELIEF ROUTE OPTIMIZATION ==========\n";
        cout << "1. Add Road Between Areas\n";
        cout << "2. Display Road Network\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Find Shortest Relief Route (Dijkstra)\n";
        cout << "6. Find Minimum Relief Network (Kruskal MST)\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addRoad();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                bfs();
                break;

            case 4:
                dfs();
                break;

            case 5:
                dijkstra();
                break;

            case 6:
                kruskalMST();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 6. SORTING MENU
// ==========================================

void sortingMenu()
{
    int choice;

    do
    {
        cout << "\n========== SORTING OPERATIONS ==========\n";
        cout << "1. Sort Areas by Severity (Bubble Sort)\n";
        cout << "2. Sort Areas by Population (Selection Sort)\n";
        cout << "3. Sort Areas by ID (Insertion Sort)\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                sortAreasBySeverity();
                break;

            case 2:
                sortAreasByPopulation();
                break;

            case 3:
                sortAreasByID();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 7. UNION-FIND MENU
// ==========================================

void unionFindMenu()
{
    int choice;

    do
    {
        cout << "\n========== UNION-FIND OPERATIONS ==========\n";
        cout << "1. Union Two Areas\n";
        cout << "2. Find Area Group\n";
        cout << "3. Display Union-Find\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int a, b;

                cout << "Enter first Area ID: ";
                cin >> a;

                cout << "Enter second Area ID: ";
                cin >> b;

                unionSets(a, b);
                break;
            }

            case 2:
            {
                int id;

                cout << "Enter Area ID: ";
                cin >> id;

                int root = findSet(id);

                if (root == -1)
                    cout << "Invalid Area ID!\n";
                else
                    cout << "Area " << id
                         << " belongs to group " << root << endl;

                break;
            }

            case 3:
                displayDSU();
                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// MAIN FUNCTION
// ==========================================

int main()
{
    // Load saved data
    loadAreas();
    loadResources();
    loadRequests();
    loadGraph();

    initializeDSU();

    int choice;

    do
    {
        cout << "\n";
        cout << "===============================================\n";
        cout << "          DISASTER MANAGEMENT SYSTEM           \n";
        cout << "   Resource Allocation & Relief Optimization   \n";
        cout << "===============================================\n";

        cout << "\n1. Area Management\n";
        cout << "2. Resource Management\n";
        cout << "3. Request Management\n";
        cout << "4. Resource Allocation\n";
        cout << "5. Relief Route Optimization\n";
        cout << "6. Sorting Operations\n";
        cout << "7. Union-Find Operations\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                areaMenu();
                break;

            case 2:
                resourceMenu();
                break;

            case 3:
                requestMenu();
                break;

            case 4:
                allocationMenu();
                break;

            case 5:
                routeMenu();
                break;

            case 6:
                sortingMenu();
                break;

            case 7:
                unionFindMenu();
                break;

            case 0:
                cout << "\nThank you for using Disaster Management System!\n";
                cout << "Exiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

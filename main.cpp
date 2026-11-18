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
// 1. AFFECTED AREA MANAGEMENT MENU
// ==========================================

void areaMenu()
{
    int choice;

    do
    {
        cout << "\n========== AFFECTED AREA MANAGEMENT ==========\n";
        cout << "1. Register a New Affected Area\n";
        cout << "2. View All Affected Areas\n";
        cout << "3. Find an Area by ID\n";
        cout << "4. View Area Records in Different Orders\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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

                cout << "\nEnter Area ID to search: ";
                cin >> id;

                if (searchArea(id))
                    cout << "\nArea Found!\n";
                else
                    cout << "\nArea Not Found!\n";

                break;
            }

            case 4:
                cout << "\n========== AREA RECORDS ==========\n";

                cout << "\n--- Areas in Ascending Order ---\n";
                inorder();

                cout << "\n--- Areas in Root-First Order ---\n";
                preorder();

                cout << "\n--- Areas in Child-First Order ---\n";
                postorder();

                break;

            case 0:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
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
        cout << "1. Add New Resource\n";
        cout << "2. View Available Resources\n";
        cout << "3. Find Resource by ID\n";
        cout << "4. View Resource Storage Records\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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

                cout << "\nEnter Resource ID: ";
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
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 3. RESOURCE REQUEST MANAGEMENT MENU
// ==========================================

void requestMenu()
{
    int choice;

    do
    {
        cout << "\n========== RESOURCE REQUEST MANAGEMENT ==========\n";
        cout << "1. Submit a Resource Request\n";
        cout << "2. View All Resource Requests\n";
        cout << "3. Submit an Urgent Request\n";
        cout << "4. View Requests by Priority\n";
        cout << "5. Process the Next Request\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 4. RESOURCE DISTRIBUTION MENU
// ==========================================

void allocationMenu()
{
    int choice;

    do
    {
        cout << "\n========== RESOURCE DISTRIBUTION ==========\n";
        cout << "1. Distribute Resources to Affected Areas\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 5. RELIEF ROUTE MANAGEMENT MENU
// ==========================================

void routeMenu()
{
    int choice;

    do
    {
        cout << "\n========== RELIEF ROUTE MANAGEMENT ==========\n";
        cout << "1. Add a Road Between Areas\n";
        cout << "2. View Road Network\n";
        cout << "3. Explore Connected Areas (BFS)\n";
        cout << "4. Explore Areas Using Depth Search (DFS)\n";
        cout << "5. Find the Shortest Relief Route (Dijkstra)\n";
        cout << "6. Find the Minimum Road Network (Kruskal MST)\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 6. AREA ORGANIZATION AND SORTING MENU
// ==========================================

void sortingMenu()
{
    int choice;

    do
    {
        cout << "\n========== ORGANIZE AREA INFORMATION ==========\n";
        cout << "1. Arrange Areas by Disaster Severity\n";
        cout << "2. Arrange Areas by Population\n";
        cout << "3. Arrange Areas by Area ID\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);
}


// ==========================================
// 7. AREA CONNECTION MANAGEMENT MENU
// ==========================================

void unionFindMenu()
{
    int choice;

    do
    {
        cout << "\n========== AREA CONNECTION MANAGEMENT ==========\n";
        cout << "1. Connect Two Affected Areas\n";
        cout << "2. Find the Connected Group of an Area\n";
        cout << "3. View Area Connection Groups\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int a, b;

                cout << "\nEnter First Area ID: ";
                cin >> a;

                cout << "Enter Second Area ID: ";
                cin >> b;

                unionSets(a, b);
                break;
            }

            case 2:
            {
                int id;

                cout << "\nEnter Area ID: ";
                cin >> id;

                int root = findSet(id);

                if (root == -1)
                    cout << "\nInvalid Area ID!\n";
                else
                    cout << "\nArea " << id
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
                cout << "\nInvalid choice! Please try again.\n";
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

        cout << "\n";
        cout << "1. Manage Disaster-Affected Areas\n";
        cout << "2. Manage Available Resources\n";
        cout << "3. Manage Resource Requests\n";
        cout << "4. Distribute Resources to Areas\n";
        cout << "5. Manage Relief Routes\n";
        cout << "6. Organize and Sort Area Information\n";
        cout << "7. Connect and Group Affected Areas\n";
        cout << "0. Exit System\n";

        cout << "\n===============================================\n";
        cout << "Enter your choice: ";
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
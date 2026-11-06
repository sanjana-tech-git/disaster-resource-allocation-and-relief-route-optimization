
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

int main() {

    loadAreas();
    loadResources();
    loadRequests();
    loadGraph();
    initializeDSU();
    int choice;

    do {
        cout << "\n===== DISASTER MANAGEMENT SYSTEM =====\n";
        cout << "1. Register affected area\n";
        cout << "2. Display affected areas\n";
        cout << "3. Add resource\n";
        cout << "4. Display resources\n";
        cout << "5. Add resource request\n";
        cout << "6. Display resource requests\n";
        cout << "7. Add priority request\n";
        cout << "8. Display priority queue\n";
        cout << "9. Process next request\n";
        cout << "10. Allocate resources\n";
        cout << "11. Add road between areas\n";
        cout << "12. Display road network\n";
        cout << "13. BFS traversal\n";
        cout << "14. DFS traversal\n";
        cout << "15. Find shortest relief route\n";
        cout << "16. Search resource by ID\n";
        cout << "17. Display Hash Table\n";
        cout << "18. Search Area using BST\n";
        cout << "19. BST Traversals\n";
        cout << "20. Sort Areas by Severity (Bubble Sort)" << endl;
        cout << "21. Sort Areas by Population (Selection Sort)" << endl;
        cout << "22. Sort Areas by ID (Insertion Sort)" << endl;
        cout << "23. Union Two Areas" << endl;
        cout << "24. Find Area Group" << endl;
        cout << "25. Display Union-Find" << endl;
        cout << "26. Find Minimum Relief Network (Kruskal MST)" << endl;
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addArea();
                break;

            case 2:
                displayAreas();
                break;

            case 3:
                addResource();
                break;

            case 4:
                displayResources();
                break;

            case 5:
                addRequest();
                break;

            case 6:
                displayRequests();
                break;

            case 7:
                addPriorityRequest();
                break;

            case 8:
                displayPriorityQueue();
                break;

            case 9:
                processNextRequest();
                break;

            case 10:
                allocateResources();
                break;
            case 11:
                addRoad();
                break;

            case 12:
                displayGraph();
                break;

            case 13:
                bfs();
                break;

            case 14:
                dfs();
                break;

            case 15:
                dijkstra();
                break;
            case 16: {
                int id;

                cout << "Enter Resource ID to search: ";
                cin >> id;

                int index = searchResource(id);

                if (index != -1) {
                    cout << "\nResource Found!\n";
                    cout << "Resource ID: " << getResourceId(index);
                    cout << "\nAvailable Quantity: "
                        << getResourceQuantity(index) << "\n";
                }
                else {
                    cout << "\nResource not found!\n";
                }

                break;
            }

            case 17:
                displayHashTable();
                break;
            case 18: {
                int id;

                cout << "Enter Area ID to search: ";
                cin >> id;

                if (searchArea(id)) {
                    cout << "\nArea Found in BST!\n";
                }
                else {
                    cout << "\nArea Not Found!\n";
                }

                break;
            }

            case 19: {
                cout << "\n===== BST TRAVERSALS =====\n";

                inorder();
                preorder();
                postorder();

                break;
            }
            case 20:
                sortAreasBySeverity();
                break;

            case 21:
                sortAreasByPopulation();
                break;

            case 22:
                sortAreasByID();
                break;
            case 23:
            {
                int a, b;

                cout << "Enter first Area ID: ";
                cin >> a;

                cout << "Enter second Area ID: ";
                cin >> b;

                unionSets(a, b);
                break;
            }

            case 24:
            {
                int id;

                cout << "Enter Area ID: ";
                cin >> id;

                int root = findSet(id);

                if (root == -1)
                    cout << "Invalid Area ID!" << endl;
                else
                    cout << "Area " << id
                        << " belongs to group " << root << endl;

                break;
            }

            case 25:
                displayDSU();
                break;
            case 26:
                kruskalMST();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

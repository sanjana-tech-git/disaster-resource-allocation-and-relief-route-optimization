#include <iostream>
#include "../include/HashTable.h"

using namespace std;

#define SIZE 10

struct HashNode {
    int resourceId;
    int index;
    HashNode* next;
};

HashNode* hashTable[SIZE] = {NULL};

// Hash function
int hashFunction(int id) {
    return id % SIZE;
}

// Insert resource into hash table
void insertResource(int resourceId, int index) {

    int position = hashFunction(resourceId);

    HashNode* newNode = new HashNode;

    newNode->resourceId = resourceId;
    newNode->index = index;
    newNode->next = hashTable[position];

    hashTable[position] = newNode;
}

// Search resource by ID
int searchResource(int resourceId) {

    int position = hashFunction(resourceId);

    HashNode* temp = hashTable[position];

    while (temp != NULL) {

        if (temp->resourceId == resourceId) {
            return temp->index;
        }

        temp = temp->next;
    }

    return -1;
}

// Display hash table
void displayHashTable() {

    cout << "\n===== HASH TABLE =====\n";

    for (int i = 0; i < SIZE; i++) {

        cout << i << " -> ";

        HashNode* temp = hashTable[i];

        while (temp != NULL) {

            cout << "[ID: " << temp->resourceId
                 << ", Index: " << temp->index << "] -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }
}
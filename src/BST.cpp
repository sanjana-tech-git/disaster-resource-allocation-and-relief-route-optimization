#include <iostream>
#include "../include/BST.h"

using namespace std;

struct Node {
    int areaId;
    Node* left;
    Node* right;
};

Node* root = NULL;

// Insert a new area ID
void insertArea(int areaId) {

    Node* newNode = new Node;

    newNode->areaId = areaId;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {

        parent = current;

        if (areaId < current->areaId) {
            current = current->left;
        }
        else if (areaId > current->areaId) {
            current = current->right;
        }
        else {
            cout << "Area ID already exists in BST.\n";
            delete newNode;
            return;
        }
    }

    if (areaId < parent->areaId) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

// Search an area ID
bool searchArea(int areaId) {

    Node* current = root;

    while (current != NULL) {

        if (current->areaId == areaId) {
            return true;
        }

        if (areaId < current->areaId) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return false;
}
// Inorder traversal: Left -> Root -> Right
void inorderTraversal(Node* temp) {

    if (temp == NULL) {
        return;
    }

    inorderTraversal(temp->left);

    cout << temp->areaId << " ";

    inorderTraversal(temp->right);
}


// Preorder traversal: Root -> Left -> Right
void preorderTraversal(Node* temp) {

    if (temp == NULL) {
        return;
    }

    cout << temp->areaId << " ";

    preorderTraversal(temp->left);

    preorderTraversal(temp->right);
}


// Postorder traversal: Left -> Right -> Root
void postorderTraversal(Node* temp) {

    if (temp == NULL) {
        return;
    }

    postorderTraversal(temp->left);

    postorderTraversal(temp->right);

    cout << temp->areaId << " ";
}
void inorder() {

    cout << "\nInorder: ";
    inorderTraversal(root);
    cout << endl;
}


void preorder() {

    cout << "\nPreorder: ";
    preorderTraversal(root);
    cout << endl;
}


void postorder() {

    cout << "\nPostorder: ";
    postorderTraversal(root);
    cout << endl;
}
#pragma once
#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left_child, * right_sibling;
};

// Create a node
struct node* newNode(int item);
void inorder(struct node* root);
void print2DUtil(node* root, int space);
void print2D(node* root);
node* insert(struct node* node, int key);
struct node* minValueNode(struct node* node);
struct node* deleteNode(struct node* root, int key);
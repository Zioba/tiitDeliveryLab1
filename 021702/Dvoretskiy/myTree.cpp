#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include "myTree.h"

node* tree::build(const std::vector<int>& a, int leftBorder, int rightBorder)
{
    node* newNode = new node;

    if (leftBorder == rightBorder)
    {
        newNode->left = newNode->right = NULL;
        newNode->max = a[rightBorder];
        newNode->leftPos = newNode->rightPos = rightBorder;
        return newNode;
    }

    int middle = (leftBorder + rightBorder) / 2;
    node* left = build(a, leftBorder, middle);
    node* right = build(a, middle + 1, rightBorder);

    newNode->left = left;
    newNode->right = right;

    newNode->max = std::max(left->max, right->max);
    newNode->leftPos = left->leftPos;
    newNode->rightPos = right->rightPos;

    return newNode;
}

int tree::find_max(node* curNode, int leftBorder, int rightBorder, int summadd)
{
    if(curNode->leftPos > rightBorder)
    {
        return -1e9;
    }
    if(curNode->rightPos < leftBorder)
    {
        return -1e9;
    }
    if(curNode->leftPos >= leftBorder && curNode->rightPos <= rightBorder)
    {
        return curNode->max + curNode->add + summadd;
    }

    int leftMax = -1e9, rightMax = -1e9;
    if(curNode->left != NULL)
    {
        leftMax = find_max(curNode->left, leftBorder, rightBorder, summadd + curNode->add);
    }
    if(curNode->right != NULL)
    {
        rightMax = find_max(curNode->right, leftBorder, rightBorder, summadd + curNode->add);
    }
    return std::max(leftMax, rightMax);
}

void tree::add_value(node* curNode, int leftBorder, int rightBorder, int value)
{
    if(curNode->leftPos > rightBorder)
    {
        return;
    }
    if(curNode->rightPos < leftBorder)
    {
        return;
    }
    if ((curNode->leftPos >= leftBorder) && (curNode->rightPos <= rightBorder))
    {
        curNode->add += value;
        return;
    }
    if(curNode->left != NULL)
    {
        curNode->left->add += curNode->add;
        add_value(curNode->left, leftBorder, rightBorder, value);
    }
    if(curNode->right != NULL)
    {
        curNode->right->add += curNode->add;
        add_value(curNode->right, leftBorder, rightBorder, value);
    }
    curNode->add = 0;
    curNode->max = std::max(curNode->left->max + curNode->left->add, curNode->right->max + curNode->right->add);
}
void tree::show_elements(node* root, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << tree::find_max(root, i, i, 0) << ' ';
    }
}

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fstream>

struct node
{
    int max = -1e9, leftPos, rightPos, add = 0;
    node *left, *right;
};

class tree
{
private:
    int elementsNumber;
public:
    static node* build(const std::vector<int>& a, int leftBorder, int rightBorder);
    static int find_max(node* curNode, int leftBorder, int rightBorder, int summadd);
    static void add_value(node* curNode, int leftBorder, int rightBorder, int value);
    static void show_elements(node* root, int n);
};

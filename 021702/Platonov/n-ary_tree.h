#ifndef TIIT_N_ARY_TREE_H
#define TIIT_N_ARY_TREE_H
#include <iostream>
#include <vector>
struct Node{

    bool operator==(const Node &rhs) const {
        return n == rhs.n &&
               svyaz == rhs.svyaz;
    }

    bool operator!=(const Node &rhs) const {
        return !(rhs == *this);
    }

    int n;
    std::vector<int> svyaz;
};
std::vector<Node> insert(std::vector <Node> vecn);
void print(std::vector<Node> v);
std::vector<Node> eject(std::vector<Node> v,int n);
#endif //TIIT_N_ARY_TREE_H

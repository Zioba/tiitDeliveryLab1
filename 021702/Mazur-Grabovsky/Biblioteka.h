#include <iostream>
struct dis_set
{
    int parent[1000];
    int size[10000];

    void make_set(int v);

    int find_set(int v);

    void merge_set(int x, int y);
};
void foo(); 

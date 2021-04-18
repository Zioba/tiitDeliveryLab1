#pragma once
class Tree
{
public:
    Tree(int* curr, int N);
    ~Tree();
    void update_tree(int v, int tl, int tr, int l, int r, int color);
    int query_tree(int v, int tl, int tr, int l, int r);
    void build_tree(int v, int tl, int tr);
private:
    int* a, * tree, * upd, Size;
};


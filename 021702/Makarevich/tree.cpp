#include <iostream>
#include "tree.h"
    Tree::Tree(int* curr, int N) {
        a = curr;
        tree = new int[4 * N];
        upd = new int[4 * N];
        for (int i = 0; i < 4 * N; i++) upd[i] = -1;
        this->Size = N;
    }
    Tree::~Tree() {
        delete[]tree;
        delete[]upd;
    }
    void Tree::update_tree(int v, int tl, int tr, int l, int r, int color)
    {
        if (l > r) return;
        if (l == tl && tr == r)
        {
            upd[v] = color;
            tree[v] = color * (r - l + 1);
        }
        else
        {
            upd[v] = -1;
            int tm = (tl + tr) >> 1;
            update_tree(v + v, tl, tm, l, std::min(r, tm), color);
            update_tree(v + v + 1, tm + 1, tr, std::max(l, tm + 1), r, color);
            tree[v] = tree[v + v] + tree[v + v + 1];
        }
    }
    int Tree::query_tree(int v, int tl, int tr, int l, int r)
    {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) >> 1;
        return query_tree(v + v, tl, tm, l, std::min(r, tm)) + query_tree(v + v + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }
    void Tree::build_tree(int v, int tl, int tr)
    {
        if (tl == tr) tree[v] = a[tl];
        else
        {
            int tm = (tl + tr) >> 1;
            build_tree(v + v, tl, tm);
            build_tree(v + v + 1, tm + 1, tr);
            tree[v] = tree[v + v] + tree[v + v + 1];
        }
    }


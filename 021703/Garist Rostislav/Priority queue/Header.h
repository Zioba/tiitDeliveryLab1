#pragma once
struct que
{
    int info;
    int priority;
    que* next, * prev;
};
void add_all(que**, que**, int, int, int);
void take_el(que**, que**, int);
void view_all(que*);

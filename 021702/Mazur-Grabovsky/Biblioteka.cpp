#include "Biblioteka.h"
void dis_set::make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int dis_set::find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void dis_set::merge_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if (x != y)
    {
        if (size[x] < size[y])
        {
            int a=0, b=0;
            a = x;
            b = y;
            x = b;
            y = a;
        }
        parent[y] = x;
        size[x] += size[y];
    }
}
void foo()
{
    std::cout << "------------------" << std::endl;
}
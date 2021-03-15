#include <iostream>
#include "set.h"

int main() {
    int n,m,value,number;
    std::cin >> n;
    std::vector<int> c;
    std::vector<int> t;
    std::vector<int> a(n);
    makeSet(a);
    outSet(a);
    std::cin >> number;
    insertv(a,number);
    std::cin >>m;
   std::vector<int> b(m);
    makeSet(b);
    outSet(b);
    std::cin>>value;
    linear_search(a,b,value,c);
    outSet(c);
    unionSet(a,b,t);
    outSet(t);
}

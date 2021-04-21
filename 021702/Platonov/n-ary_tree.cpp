
#include "n-ary_tree.h"
using namespace std;
std::vector<Node> insert(std::vector <Node> vecn){
    Node a,b;
    int u,v;
    cout<<"введите элемент который хотите добавить и к какому элементу ";
    cin>>u>>v;
    if (u!=v)
        if (u<v) {
            a.n = u;
            b.n = v;
            a.svyaz.push_back(b.n);
        }
        else
        {
            b.n = u;
            a.n = v;
            b.svyaz.push_back(a.n);
        }
    if (!vecn.empty()){
        for (int i = 0; i < vecn.size(); ++i) {
            if (a.n == vecn[i].n)
                vecn[i].svyaz.push_back(b.n);
        }
        vecn.push_back(b);
    }
    else {
        vecn.push_back(a);
        vecn.push_back(b);
    }
    return vecn;
}

void print(std::vector<Node> v){
    cout<<"наше дерево:";
    for (int i = 0; i < v.size(); ++i) {
        if (!v[i].svyaz.empty()) {
            cout << v[i].n << "\n";
            for (int j = 0; j < v[i].svyaz.size(); ++j) {
                cout << v[i].svyaz[j] << " ";
            }
            cout << "\n";
        }
    }
}

std::vector<Node> eject(std::vector<Node> v,int n){
    cout<<"введите элемент который хотите удалить ";
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].n==n)
            v.erase(v.begin()+i);
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].svyaz.size(); ++j) {
            if (v[i].svyaz[j]==n)
                v[i].svyaz.erase(v[i].svyaz.begin()+j);
        }
    }
    return v;
}

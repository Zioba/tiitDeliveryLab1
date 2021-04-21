#include "n-ary_tree.h"
using namespace std;
int main() {//n ary tree
    bool have1=true,have=true;
    vector<Node> vecn;          // n-ary tree
    int v,N,edges;            // u & v buffer variables , N - number of nodes , edges -number of edges)
    Node a, b,root;             // a & b buffer variables
    cout<<"введите N узлов и связей ";
    cin>>N>>edges;
    cout<<"введите корневой элемент ";
    cin>>root.n;
    vecn.push_back(root);
    N--;
    while (edges--) {
        a.svyaz.clear();//filling of n-ary tree
        cin>>a.n>>b.n;
        if (a.n != b.n){
            have=true;
            a.svyaz.push_back(b.n);
            for (int i = 0; i < vecn.size(); ++i) {
                if(a.n==vecn[i].n) {
                    for (int j = 0; j < a.svyaz.size(); j++) {
                        have1=true;
                        for (int k = 0; k < vecn[i].svyaz.size(); ++k) {
                            if (a.svyaz[j]==vecn[i].svyaz[k])
                                have1=false;
                        }
                        if (have1)
                            vecn[i].svyaz.push_back(a.svyaz[j]);
                    }
                    have = false;
                }
            }
            if (have)
                vecn.push_back(a);
            have= true;
            for (int i = 0; i < vecn.size(); ++i) {
                if(b==vecn[i])
                    have=false;
            }
            if (have)
                vecn.push_back(b);
        }
        else
        {
            edges++;
            cout<<"ошибка ввода ";
        }
    }
    print(vecn);
    vecn=insert(vecn);
    print(vecn);
    cin>>v;
    vecn=eject(vecn,v);
    print(vecn);
    return 0;
}

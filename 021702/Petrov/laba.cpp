#include "laba.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdlib.h>



void pushtest1(set<int> mySet, int add){
    mySet.insert(add);
    
    copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
}



void del1test(set<int> mySet, int del)
{
    mySet.erase(del);
   
    copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
}


void unificationtest(set<int> s, vector<int> v1, vector<int> v2, vector<int> v_intersection)
{
    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() % 100);
    }
    sort(v1.begin(), v1.end());
   
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for (int n = 0; n < 10; n++) {
        v2.push_back(rand() % 100);
    }
    sort(v2.begin(), v2.end());
    
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    set_union(v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        back_inserter(v_intersection));

    s.insert(v_intersection.begin(), v_intersection.end());
    
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
}


void intersection(set<int> ans)
{
    for (set <int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << " ";
    }
}


void elfindtest(set<int> mySet, int x)
{
   
    for (int i = x; i <= x; ++i)
    {
        cout << i;
        if (mySet.count(i) != 0)
            cout << " находится во множестве\n";
        else
            cout << " не находиться во множестве\n";
    }
}

#include <iostream>
#include <set>  // заголовочный файл множест и мультимножеств
#include <iterator>
#include <cstdlib>
#include "laba.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    
    
    setlocale(LC_ALL, "RUSSIAN");
    srand(time(NULL));
    int n;
    cout << "Введите 1,2,3,4,5" << endl;
    cout << "1 - Добавление элемента во множество" << endl;
    cout << "2 - Удаление элемента из множества" << endl;
    cout << "3 - Объединение 2-х множеств" << endl;
    cout << "4 - Пересечение 2-х множеств" << endl;
    cout << "5 - Поиск элемента во множестве" << endl;
    cin >> n;
    

    switch (n)
    {
    case 1: {
        
            set<int> mySet;
            int add;
            for (int i = 0; i < 10; i++) {
                mySet.insert(rand() % 100);
            }

            copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
            cin >> add;
            pushtest1(mySet, add);

               
               break;
     
    }
    case 2:
    {
        
            set<int> mySet; // объявили пустое множество
            int del;
            for (int i = 0; i < 10; i++) {
            mySet.insert(rand() % 100);
        }

        copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
            cin >> del;
            del1test(mySet, del);
         
        
        break;
    }
    case 3:
    {
       
            set <int> s;
            vector <int> v1;
            vector <int> v2;
            vector <int> v_intersection;
            unificationtest(s, v1, v2, v_intersection);
        
        break;
    }
    case 4:
    {
        set <int> a, ans;
        int n, m, temp;
        cout << "Кол-во элементов 1 множества:";
        cin >> n;
        cout << "Кол-во элементов 2 множества:";
        cin >> m;
        cout << "Элементы множества 1:";
        
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.insert(temp);
        }
        cout << "Элементы множества 2:";
        for (int i = 0; i < m; i++) {
            cin >> temp;
            if (a.count(temp) != 0) ans.insert(temp);
        }
        cout << "Пересекаются:";
        intersection(ans);
       break;
    }
    case 5:
    {
       
            set<int> mySet; 
            int x;
            for (int i = 0; i < 10; i++) {
                mySet.insert(rand() % 100);
            }

            copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
            cin >> x;
            elfindtest(mySet, x);
            
           
      
              break;
        }
    
    }
    return 0;
}
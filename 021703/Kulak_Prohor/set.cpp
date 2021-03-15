#include "set.h"
#include <iostream>


using namespace std;

void insertv(std::vector<int>& arr, int elem)
{
    for (auto i = arr.begin(); i != arr.end(); i++)
        if (elem == *i)
            return;
        else {
            if (elem >= *i)
                continue;
            arr.insert(i, elem);
            return;
        }
    arr.push_back(elem);
}
void sort(std::vector<int>& arr)
{
    int size = arr.size();
    for (int j = 1; j < size; j++)
    {
        bool isSorted = true;
        for (int i = 0; i < size - j; i++)
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        if (isSorted)
            return;
    }
}

void removeDuplicates(std::vector<int>& arr)
{
    for (int i = 0; i < (int)arr.size() - 1;)
        if (arr[i] == arr[i + 1])
            arr.erase(arr.begin() + i);
        else
            i++;
}

void makeSet(std::vector<int>& arr)
{
    for (auto& x: arr)
        std::cin >> x;
    sort(arr);
    removeDuplicates(arr);
}
void outSet(std::vector<int>& arr){
    sort(arr);
    removeDuplicates(arr);
    for (auto x: arr)
        std::cout << x << ' ';
    std::cout<<'\n';
}
void unionSet(std::vector<int> &a,std::vector<int> &b,std::vector<int> &c){
    c.reserve( a.size() + b.size() );
    c.insert( c.end(), a.begin(), a.end() );
    c.insert( c.end(), b.begin(), b.end() );
    removeDuplicates(c);
}



int linear_search(std::vector<int> &a,std::vector<int> &b, int n,std::vector<int> &c )
{
    for (int i = 0; i < a.size(); i++){
        if (a[i] == n) {
            c.insert( c.end(), a.begin(), a.end() );
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == n) {
            c.insert( c.end(), b.begin(), b.end() );
        }
    }
    return -1;
}

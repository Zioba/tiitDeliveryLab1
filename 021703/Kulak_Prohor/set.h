
#ifndef LABA1C___TEST_H
#define LABA1C___TEST_H
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unordered_map>

void insertv(std::vector<int>& arr, int elem);
void sort(std::vector<int>& arr);
void removeDuplicates(std::vector<int>& arr);
void makeSet(std::vector<int>& arr);
void outSet(std::vector<int>& arr);
void unionSet(std::vector<int> &a,std::vector<int> &b,std::vector<int> &c);
int linear_search(std::vector<int> &a,std::vector<int> &b, int n,std::vector<int> &c );

#endif //LABA1C___TEST_H

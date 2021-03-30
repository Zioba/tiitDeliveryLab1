#include <vector>
#include <algorithm>
#include <queue>
#include <string>


#ifndef _Header_H_
#define _Header_H_

extern int kol_A, kol_N, vsize;
extern std::vector<int> vecbfs;
extern std::string print;


void NewGraph(std::vector<int> graph[1000]);

void AddNode(std::vector<int> graph[1000], int x);

void PrintGraph(std::vector<int> graph[1000]);

void DelNode(std::vector<int> graph[1000], int x);

void AddArc(std::vector<int> graph[1000], int u, int v);

void DelArc(std::vector<int> graph[1000], int u, int v);

void BFS(std::vector<int> graph[1000], int x);


#endif
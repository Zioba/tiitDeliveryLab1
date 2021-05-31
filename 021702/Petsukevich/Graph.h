#pragma once
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Graph
{
private:
	vector<vector<int> > graph;
	vector<bool> visit;
	vector<int> ignore;
	void dfs(int,ofstream&);
public:
	Graph();
	void add_vertex();
	void del_vertex(int);
	void add_edge(int,int);
	void del_edge(int,int);
	void print_graph(ofstream&);
	void print_dfs_tree(ofstream&, int);
};


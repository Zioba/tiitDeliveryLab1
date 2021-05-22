#pragma once
#include<vector>

using namespace std;

class Graph
{
public:
	int answer;
	int Node;
	int Arc;
	int x, y;
	int x1, y1;
	string s;
	vector<vector<int>> vec;
	void AddGraph();
	void Answer();
	void AddNode();
	void DelNode();
	void AddArc();
	void DelArc();
	void dfs(int node_index, vector <bool>& visited);
};


#include "Graph.h"

Graph::Graph()
{
	vector<vector<int> > graph(0);
	vector<int> visit(0);
	vector<int> ignore(0);
}
void Graph::add_vertex()
{
	vector<int> k(0);
	graph.push_back(k);
	visit.push_back(false);
}
void Graph::add_edge(int k1, int k2)
{
	k1--;
	k2--;
	bool find1 = find(ignore.begin(), ignore.end(), k1) == ignore.end();
	bool find2 = find(ignore.begin(), ignore.end(), k2) == ignore.end();
	if (find1 && find2 && k1 < graph.size()&&k2<graph.size())
	{
		graph[k1].push_back(k2);
		graph[k2].push_back(k1);
	}
	else return;
}
void Graph::del_edge(int k1, int k2)
{
	k1--;
	k2--;
	if (k1 < graph.size() && k2 < graph.size())
	{
		for (int j = 0; j < graph[k1].size(); j++)
		{
			if (graph[k1][j] == k2)
			{
				graph[k1].erase(graph[k1].begin() + j);
				break;
			}
		}
		for (int j = 0; j < graph[k2].size(); j++)
		{
			if (graph[k2][j] == k1)
			{
				graph[k2].erase(graph[k2].begin() + j);
				break;
			}
		}
	}
}
void Graph::del_vertex(int n)
{
	if (n - 1 < graph.size() && (find(ignore.begin(), ignore.end(), n - 1) == ignore.end()))
	{
		ignore.push_back(n - 1);
		for (int i = 0; i < graph[n - 1].size(); i++)
		{
			int v = graph[n - 1][i];
			for (int j = 0; j < graph[v].size(); j++)
			{
				if (graph[v][j] == n - 1)
				{
					graph[v].erase(graph[v].begin() + j);
					break;
				}
			}
		}
	}
	else return;
}
void Graph::print_graph(ofstream& cout)
{
	for (int i = 0; i < graph.size();i++)
	{
		bool find1 = find(ignore.begin(), ignore.end(), i) == ignore.end();
		if (find1)
		{
			cout << i + 1 << " : ";
			for (int j = 0; j < graph[i].size(); j++)
			{
				cout << graph[i][j] + 1 << " ";
			}
			cout << '\n';
		}
	}
}

void Graph::print_dfs_tree(ofstream& cout, int start)
{
	visit[start - 1] = true;
	dfs(start-1,cout);
	for (int i = 0; i < graph.size(); i++)
	{
		if (!visit[i] && find(ignore.begin(), ignore.end(), i) == ignore.end())
		{
			visit[i] = true;
			dfs(i,cout);
		}
	}
	visit.resize(visit.size(), false);
}
void Graph::dfs(int k, ofstream& cout)
{
	for (int i = 0; i < graph[k].size(); i++)
	{
		int v = graph[k][i];
		if (!visit[v])
		{
			visit[v] = true;
			cout << k + 1 << "->" << v + 1 << '\n';
			dfs(v,cout);
		}
	}
	if (graph[k].size() == 0)
	{
		cout << k + 1 << '\n';
	}

}
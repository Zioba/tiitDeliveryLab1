#include"Graph.h"

using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	Graph graph;
	
	int k;
	in >> k;
	for (int i = 0; i < k; i++)
	{
		graph.add_vertex();
	}
	graph.print_graph(out);
	out << '\n';

	int n; in >> n;
	for (int i = 0; i < n; i++)
	{
		int n1, n2;
		in >> n1 >> n2;
		graph.add_edge(n1, n2);
	}

	graph.print_graph(out);
	out << '\n';
	
	int del; in >> del;
	graph.del_vertex(del);
	graph.print_graph(out);
	out << '\n';

	int del1, del2; 
	in >> del1 >> del2;
	graph.del_edge(del1,del2);
	graph.print_graph(out);
	out << '\n';

	int start;
	in >> start;
	graph.print_dfs_tree(out,start);
	char output[10000];
	ifstream outputf("output.txt");
	outputf.getline(output, 10000);
	char result[10000];
	ifstream resultf("test.txt");
	resultf.getline(result, 10000);
	if (strcmp(output, result)==0)
		out << "\ntest passed.";
	else out << "\ntest failed.";
		
	return 0;
}
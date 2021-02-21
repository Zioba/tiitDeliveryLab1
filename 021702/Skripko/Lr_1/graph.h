#ifndef GRAPH
#define GRAPH
#include <iostream>
using namespace std;

class Graph {
private:

	struct Elem {
		int data;
		int id;
		bool for_search = false;
		int quantity_arcs = 0;
		Elem** arcs = NULL;
	};

	int counter_id = 0;
	int quantity_elem = 0;
	Elem* elem;

	bool next_search(Elem** neighbors, int data_to, int quantity_neighbors);
	
public:

	Graph() {
		elem = new Elem[1];
	}

	void add_elem(int add);

	void del_elem(int num_id);

	void print_graph_elem();

	void print_graph_elem_id_according_data(int data);

	void add_arcs(int num_id_from, int num_id_to);

	void del_arcs(int num_id_from, int num_id_to);

	void print_graph_elem_arcs(int id_from);

	void search_data_to_data(int data_from, int data_to);

	void search_id_to_data(int num_id_from, int data_to);

	~Graph() {
		for (int num_arcs = 0; num_arcs < quantity_elem; num_arcs++) {
			if (elem[num_arcs].arcs != NULL) {
				delete[] elem[num_arcs].arcs;
			}
		}
		delete[] elem;
	}
};

#endif

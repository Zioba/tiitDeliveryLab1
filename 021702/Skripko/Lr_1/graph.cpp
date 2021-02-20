#include "graph.h"


	bool Graph::next_search(Elem** neighbors, int data_to, int quantity_neighbors)
	{
		Elem** new_neighbors = nullptr;
		int quantity_new_neighbors = 0;
		for (int num_neighbors = 0; num_neighbors < quantity_neighbors; num_neighbors++) {
			if ((neighbors[num_neighbors])->for_search == false) {
				cout << (neighbors[num_neighbors])->data << " ";
				(neighbors[num_neighbors])->for_search = true;
				if (data_to == (neighbors[num_neighbors])->data) {
					delete[] neighbors;
					delete[] new_neighbors;
					return true;
				}
				else {
					int quantity_duplicate_neighbors = 0;
					if (quantity_new_neighbors == 0) {
						if ((neighbors[num_neighbors])->quantity_arcs == 0) {

						}
						else {
							quantity_new_neighbors = (neighbors[num_neighbors])->quantity_arcs;
							new_neighbors = new Elem * [quantity_new_neighbors];
							for (int num_new_neighbors = 0; num_new_neighbors < quantity_new_neighbors; num_new_neighbors++) {
								if ((neighbors[num_neighbors])->arcs[num_new_neighbors]->for_search == false) {
									new_neighbors[(num_new_neighbors - quantity_duplicate_neighbors)] = (neighbors[num_neighbors])->arcs[num_new_neighbors];
								}
								else {
									quantity_duplicate_neighbors++;
								}
							}
							quantity_new_neighbors = quantity_new_neighbors - quantity_duplicate_neighbors;
						}
					}
					else {
						int past_quantity_new_neighbors = quantity_new_neighbors;
						quantity_new_neighbors = quantity_new_neighbors + (neighbors[num_neighbors])->quantity_arcs;
						Elem** temp = new_neighbors;
						new_neighbors = new Elem * [quantity_new_neighbors];
						for (int num_new_neighbors = 0; num_new_neighbors < past_quantity_new_neighbors; num_new_neighbors++) {
							new_neighbors[num_new_neighbors] = temp[num_new_neighbors];
						}
						for (int num_new_neighbors = past_quantity_new_neighbors; num_new_neighbors < quantity_new_neighbors; num_new_neighbors++) {
							if ((neighbors[num_neighbors])->arcs[num_new_neighbors - past_quantity_new_neighbors]->for_search == false) {
								new_neighbors[(num_new_neighbors - quantity_duplicate_neighbors)] = (neighbors[num_neighbors])->arcs[num_new_neighbors - past_quantity_new_neighbors];
							}
							else {
								quantity_duplicate_neighbors++;
							}
						}
						quantity_new_neighbors = quantity_new_neighbors - quantity_duplicate_neighbors;
					}
				}
			}
		}
		delete[] neighbors;
		if (quantity_new_neighbors == 0) {
			delete[] new_neighbors;
			return false;
		}
		else {
			return next_search(new_neighbors, data_to, quantity_new_neighbors);
		}
	}

	void Graph::add_elem(int add)
	{
		quantity_elem++;
		counter_id++;
		if (quantity_elem == 1) {
			Elem add_elem;
			add_elem.data = add;
			add_elem.id = counter_id;
			elem[quantity_elem - 1] = add_elem;
			}
		else {
			Elem* past_elem = elem;;
			elem = new Elem[quantity_elem];
			for (int num_elem = 0; num_elem < quantity_elem - 1; num_elem++) {
				elem[num_elem] = past_elem[num_elem];
			}
			Elem add_elem;
			add_elem.data = add;
			add_elem.id = counter_id;
			elem[quantity_elem - 1] = add_elem;
			delete[] past_elem;
		}
	}

	void Graph::del_elem(int num_id)
	{
		if (num_id > counter_id) {
			cout << "There is no element with this id" << endl;
		}
		else {
			int del_num;
			bool already_deleted = false;
			for (int num_elem = 0; num_elem <= quantity_elem; num_elem++) {
				if (num_elem == quantity_elem) {
					cout << "You have already deleted this elem" << endl;;
					already_deleted = true;
					break;
				}
				else if (elem[num_elem].id == num_id) {
					del_num = num_elem;
					break;
				}
			}
			if (already_deleted) {

			}
			else {


				for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {

					this->del_arcs(elem[num_elem].id, num_id);
				}

				quantity_elem--;
				delete[] elem[del_num].arcs;
				Elem* past_elem = elem;
				elem = new Elem[quantity_elem];
				bool after_delete = false;

				for (int num_elem = 0; num_elem < quantity_elem + 1; num_elem++) {
					if (num_elem == del_num) {
						after_delete = true;
					}
					else if (after_delete == false) {
						elem[num_elem] = past_elem[num_elem];
					}
					else if (after_delete == true) {
						elem[num_elem - 1] = past_elem[num_elem];
					}
				}
				delete[] past_elem;
			}
		}
	}

	void Graph::print_graph_elem()
	{
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++)
		{

			if (num_elem == quantity_elem - 1) {
				cout << this->elem[num_elem].data;
			}
			else {
				cout << this->elem[num_elem].data << " ";
			}
		}
		cout << endl;
	}

	void Graph::print_graph_elem_id_according_data(int data)
	{
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			if (elem[num_elem].data == data) {
				cout << elem[num_elem].id << " ";
			}
		}
		cout << endl;
	}

	void Graph::add_arcs(int num_id_from, int num_id_to)
	{
		int from;
		int to;
		int for_check = 2;
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			if (elem[num_elem].id == num_id_from && elem[num_elem].id == num_id_to) {
				from = num_elem;
				to = num_elem;
				for_check = for_check - 2;

			}
			else if (elem[num_elem].id == num_id_from) {
				from = num_elem;
				for_check--;
			}
			else if (elem[num_elem].id == num_id_to) {
				to = num_elem;
				for_check--;
			}
			else if (for_check == 0) {
				break;
			}

		}
		if (for_check != 0) {
			cout << "Check what id's you specified" << endl;
		}
		else {
			elem[from].quantity_arcs++;

			if (elem[from].quantity_arcs == 1) {
				elem[from].arcs = new Elem * [elem[from].quantity_arcs];
				elem[from].arcs[0] = &elem[to];
			}
			else {
				Elem** past_arcs = elem[from].arcs;
				elem[from].arcs = new Elem * [elem[from].quantity_arcs];
				for (int num_arcs = 0; num_arcs < elem[from].quantity_arcs - 1; num_arcs++) {
					elem[from].arcs[num_arcs] = past_arcs[num_arcs];
				}
				elem[from].arcs[elem[from].quantity_arcs - 1] = &elem[to];
				delete[] past_arcs;

			}
		}
	}

	void Graph::del_arcs(int num_id_from, int num_id_to)
	{
		int from;
		int for_check = 2;
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			if (elem[num_elem].id == num_id_from && elem[num_elem].id == num_id_to) {
				from = num_elem;
				for_check = for_check - 2;
			}
			else if (elem[num_elem].id == num_id_from) {
				from = num_elem;
				for_check--;
			}
			else if (elem[num_elem].id == num_id_to) {
				for_check--;
			}
			else if (for_check == 0) {
				break;
			}
		}
		if (for_check != 0) {
			cout << "Check what id's you specified" << endl;
		}
		else if (elem[from].quantity_arcs == 0) {
			cout << "Elem with id " << num_id_from << " don't have any arcs" << endl;
		}
		else {
			bool elem_from_have_arc_to_elem_to = false;
			for (int num_arcs = 0; num_arcs < elem[from].quantity_arcs; num_arcs++) {
				if (num_id_to == elem[from].arcs[num_arcs]->id) {
					elem_from_have_arc_to_elem_to = true;
					break;
				}
			}
			if (!elem_from_have_arc_to_elem_to) {

			}
			else {
				elem[from].quantity_arcs--;

				Elem** past_arcs = elem[from].arcs;
				elem[from].arcs = new Elem * [elem[from].quantity_arcs];
				bool after = false;


				for (int num_arcs = 0; num_arcs < elem[from].quantity_arcs + 1; num_arcs++) {
					if (past_arcs[num_arcs]->id == num_id_to) {
						after = true;
					}
					else if (after == false) {
						elem[from].arcs[num_arcs] = past_arcs[num_arcs];
					}
					else if (after == true) {
						elem[from].arcs[num_arcs - 1] = past_arcs[num_arcs];
					}
				}
				delete[] past_arcs;
			}
		}
	}

	void Graph::print_graph_elem_arcs(int id_from)
	{
		for (int from = 0; ; from++) {
			if (from == quantity_elem) {
				cout << "There is no element with this id" << endl;
				break;
			}
			else if (elem[from].id == id_from) {
				for (int num_arcs = 0; num_arcs < elem[from].quantity_arcs; num_arcs++)
				{
					if (num_arcs == elem[from].quantity_arcs - 1) {
						cout << elem[from].arcs[num_arcs]->data;
					}
					else {
						cout << elem[from].arcs[num_arcs]->data << " ";
					}

				}
				cout << endl;
				break;
			}

		}
	}

	void Graph::search_data_to_data(int data_from, int data_to)
	{
		Elem** neighbors;
		int from = -1;
		bool for_check = false;
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			if (elem[num_elem].data == data_from) {
				from = num_elem;
				for_check = true;
			}
			else if (for_check == true) {
				break;
			}
		}
		if (from == -1) {
			cout << "This " << data_from << " doesn't exist" << endl;
		}
		else {
			cout << elem[from].data << " ";
			elem[from].for_search = true;
			if (elem[from].data == data_to) {
				cout << endl << "Found " << data_to << " from this " << data_from << endl;
			}
			else if (elem[from].quantity_arcs == 0) {
				cout << endl << "Can't found " << data_to << " from this " << data_from << " because this " << data_from << " don't have arcs" << endl;
			}
			else {
				neighbors = new Elem * [elem[from].quantity_arcs];
				for (int num_arcs = 0; num_arcs < elem[from].quantity_arcs; num_arcs++) {
					neighbors[num_arcs] = elem[from].arcs[num_arcs];
				}

				if (this->next_search(neighbors, data_to, elem[from].quantity_arcs) == true) {
					cout << endl << "Found " << data_to << " from this " << data_from << endl;
				}
				else {
					cout << endl << "Can't found " << data_to << " from this " << data_from;
					bool for_check_second = false;
					for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
						if (elem[num_elem].data == data_to) {
							for_check_second = true;
						}
						else if (for_check_second == true) {
							break;
						}
					}
					if (for_check_second == true) {
						cout << endl;
					}
					else {
						cout << " because this " << data_to << " doesn't exist" << endl;
					}
				}
			}
		}
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			elem[num_elem].for_search = false;
		}

	}

	void Graph::search_id_to_data(int num_id_from, int data_to)
	{
		Elem** neighbors;
		int data_from;
		int from = -1;
		bool for_check = false;
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			if (elem[num_elem].id == num_id_from) {
				from = num_elem;
				data_from = elem[num_elem].data;
				for_check = true;
			}
			else if (for_check == true) {
				break;
			}
		}
		if (from == -1) {
			cout << "Elem with id " << num_id_from << " doesn't exist" << endl;
		}
		else {
			cout << elem[from].data << " ";
			elem[from].for_search = true;
			if (elem[from].data == data_to) {
				cout << endl << "Found " << data_to << " from this " << data_from << endl;
			}
			else if (elem[from].quantity_arcs == 0) {
				cout << endl << "Can't found " << data_to << " from this " << data_from << " because this " << data_from << " don't have arcs" << endl;
			}
			else {
				neighbors = new Elem * [elem[from].quantity_arcs];
				for (int num_arcs = 0; num_arcs < elem[from].quantity_arcs; num_arcs++) {
					neighbors[num_arcs] = elem[from].arcs[num_arcs];
				}

				if (this->next_search(neighbors, data_to, elem[from].quantity_arcs) == true) {
					cout << endl << "Found " << data_to << " from this " << data_from << endl;
				}
				else {
					cout << endl << "Can't found " << data_to << " from this " << data_from;
					bool for_check_second = false;
					for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
						if (elem[num_elem].data == data_to) {
							for_check_second = true;
						}
						else if (for_check_second == true) {
							break;
						}
					}
					if (for_check_second == true) {
						cout << endl;
					}
					else {
						cout << " because this " << data_to << " doesn't exist" << endl;
					}
				}
			}
		}
		for (int num_elem = 0; num_elem < quantity_elem; num_elem++) {
			elem[num_elem].for_search = false;
		}

	}

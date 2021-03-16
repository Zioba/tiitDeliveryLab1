#pragma once
#define Max 10

struct node {
	int* dequeue; //маленький дек
	node* next;
	node* previous;
	node(node* Pr, node* Ne);
	void print();
};
struct Dequeue {
	node* first;
	node* last;
	int first_small_deque, last_small_deque, Size;
	Dequeue();
	void add_first();

	void add_last();

	void delete_first();

	void delete_last();

	void push_front(int n);

	void push_back(int n);

	void pop_front();

	void pop_back();

	bool empty();

	void clear();

	void print();
};
#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_

#include <iostream>
#include <exception>

using namespace std;

class ForwardList
{
public:
	void push_back(int value);
	void pop_back();

	int get(int index);
	void sort();
	void join(ForwardList& other);
	ForwardList* findIntersections(ForwardList& other);

	void print();

private:
	class Node
	{
	public:
		int data;
		Node* next = nullptr;
	};

	Node* head = nullptr;
	int size = 0;

private:
	Node* getNode(int index);
};

#endif
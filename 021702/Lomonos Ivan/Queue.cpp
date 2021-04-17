#include "Queue.h"
#include<iostream>
using namespace std;
struct Node
{
	int key;
	Node* prev;
	Node* next;
};
Queue::Queue()
{
	begin = NULL;
	end = NULL;
}
void Queue::push(int key)
{
	if (end == NULL)
	{
		Node* tmp = new Node;
		tmp->key = key;
		tmp->prev = NULL;
		tmp->next = NULL;
		begin = tmp;
		end = tmp;
	}
	else
	{
		Node* tmp = new Node;
		tmp->key = key;
		tmp->prev = end;
		tmp->prev->next = tmp;
		tmp->next = NULL;
		end = tmp;
	}
}
int Queue::pop()
{
	if (begin == NULL)return -1;
	int key = begin->key;
	if (begin->next != NULL)
		begin->next->prev = NULL;
	begin = begin->next;
	if (begin == NULL)end = NULL;
	return key;
}
#include "functions.h"
#include <cstddef>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void push(int a, Stack*& myStack)
{
	Stack* stack = new Stack;
	stack->info = a;
	stack->Next = myStack->Head;
	myStack->Head = stack;
}

void pop(Stack* myStack)
{
	Stack* stack = myStack->Head;
	if (getSize(myStack) == 1)
		myStack->Head = NULL;
	while (stack->Next->Next != NULL)
		stack = stack->Next;
	stack->Next = NULL;
	//myStack->Head = stack->Next;
}

void sort2(Stack* myStack) {
	Stack* t = NULL, * t1;
	Stack* stack = myStack->Head;
	int r;
	while (stack->Next != t)
	{
		for (t1 = stack; t1->Next != t; t1 = t1->Next)
			if (t1->info > t1->Next->info)
			{
				r = t1->info;
				t1->info = t1->Next->info;
				t1->Next->info = r;
			}
		t = t1;
	}
}

void integration(Stack*& myStack, Stack*& myStack1, Stack*& finalStack)
{
	Stack* stack = myStack->Head;
	Stack* stack1 = myStack1->Head;
	while (stack != NULL)
	{
		if (!findEl(finalStack, stack->info))
		 push(stack->info, finalStack);
		stack = stack->Next;
	}
	while (stack1 != NULL)
	{
		if (!findEl(finalStack, stack1->info))
		 push(stack1->info, finalStack);
		stack1 = stack1->Next;
	}
}

void intersection(Stack*& myStack, Stack*& myStack1, Stack*& finalStack1)
{
	Stack* stack = myStack->Head;
	Stack* stack1 = myStack1->Head;
	while (stack != NULL && stack1 != NULL)
	{
		//cout << "AAAAAA" << endl;
		if (stack->info == stack1->info)
		{
			push(stack->info, finalStack1);
			stack = stack->Next;
			stack1 = stack1->Next;
		//	cout << "OPA";
		}
		else
			if (stack->info < stack1->info)
				stack = stack->Next;
			else
				stack1 = stack1->Next;
	}
}

bool findEl(Stack*& myStack, int el)
{
	bool flag = false;
	Stack* stack = myStack->Head;
	while (stack != NULL)
	{
		if (stack->info == el)
		{
			flag = true;
			break;
		}
		stack = stack->Next;
	}
	return flag;
}

int getSize(Stack* myStack)
{
	int amount = 0;
	Stack* stack = myStack->Head;
	while (stack != NULL)
	{
		amount++;
		stack = stack->Next;
	}
	return amount;
}

void sort1(Stack* myStack)
{
	Stack* stack = myStack->Head;
	vector <int> vec;
	if (getSize(myStack) > 1)
	{
		while (stack != NULL)
		{
			vec.push_back(stack->info);
			stack = stack->Next;
		}
	}
	sort(vec.begin(), vec.end());
	myStack->Head = NULL;
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		push(vec[i], myStack);
	    //cout << vec[i] << " ";
	}
	vec.clear();
}
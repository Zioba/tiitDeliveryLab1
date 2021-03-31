#pragma once

struct Stack
{
	int info;
	Stack* Next, * Head;
};

void  push(int a, Stack*& myStack);
void pop(Stack* myStack);

void sort2(Stack* myStack);
	
void integration(Stack*& myStack, Stack*& myStack1, Stack*& finalStack);

void intersection(Stack*& myStack, Stack*& myStack1, Stack*& finalStack1);

bool findEl(Stack*& myStack, int el);

int getSize(Stack* myStack);

void sort1(Stack* myStack);

//void show(Stack* myStack);


#include "steck.h"
#include <iostream>
using namespace std;
const int n = 6;
struct Stack
{
	int A[n];
	int count;
};

void Creation(Stack* p)
{
	p->count = 0;
}

void Add(Stack* p)
{
	int value;
	cout << "Введите элемент > "; cin >> value;
	p->A[p->count] = value;
	p->count++;
}

void Delete(Stack* p)
{
	p->count--;
}

int Top(Stack* p)
{
	return p->A[p->count - 1];
}

int Size(Stack* p)
{
	return p->count;
}

int Full(Stack* p)
{
	if (p->count == 0) return 1;
	else if (p->count == n) return -1;
	else return 0;
}
#include <iostream>
#include <ctime>
#include "functions.h"
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int el = 0;
	Stack* myStack = new Stack;
	Stack* myStack1 = new Stack;
	Stack* finalStack = new Stack;
	Stack* finalStack1 = new Stack;
	myStack->Head = NULL;
	myStack1->Head = NULL;
	finalStack->Head = NULL;
	finalStack1->Head = NULL;
	int buf = 0, n = 0, m = 0;
	string nn, mm, bbuf, ell;
	fin >> nn;
	try
	{
		n = stoi(nn);
	}
	catch (invalid_argument)
	{
		fout << -3 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		fin >> bbuf;
		try
		{
			buf = stoi(bbuf);
		}
		catch (invalid_argument)
		{
			fout << -3 << endl;
			return 0;
		}
		push(buf, myStack);
	}
	fin >> mm;
	try
	{
		m = stoi(mm);
	}
	catch (invalid_argument)
	{
		fout << -3 << endl;
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		fin >> buf;
		push(buf, myStack1);
	}
	fin >> ell;
	try
	{
		el = stoi(ell);
	}
	catch (invalid_argument)
	{
		fout << -3 << endl;
		return 0;
	}
	if (m == 0 & n == 0) {
		fout << -2 << endl;
		return 0;
	}
	if (getSize(myStack) > 1) sort1(myStack);
	if (getSize(myStack1) > 1) sort1(myStack1);
	integration(myStack, myStack1, finalStack);
	//sort1(finalStack);
	Stack* st = myStack->Head;
	if (getSize(myStack) > 0)
	{
		while (st != NULL)
		{
			fout << st->info << " ";
			st = st->Next;
		}
		//fout << endl;
	}
	else fout << -1 << endl;

	if (getSize(myStack) > 0)
	{
		fout << findEl(myStack, el);
		//fout << endl;
	}
	else fout << -1 << endl;

	if (getSize(finalStack) > 0) {
		if (getSize(finalStack) > 1)
			sort1(finalStack);
		st = finalStack->Head;
		while (st != NULL)
		{
			fout << st->info << " ";
			st = st->Next;
		}
	//	fout << endl;
	}
	else fout << -1 << endl;

	intersection(myStack, myStack1, finalStack1);
	if (getSize(finalStack1) > 0) {
		if (getSize(finalStack1) > 1)
			sort1(finalStack1);
		st = finalStack1->Head;
		while (st != NULL)
		{
			fout << st->info << " ";
			st = st->Next;
		}
		//fout << endl;
	}
	else fout << -1 << endl;

	if (getSize(myStack) == 0)
		fout << -1 << endl;
	else
		if (getSize(myStack) == 1)
			fout << 0 << endl;
		else
		{
		
	       pop(myStack);
	       st = myStack->Head;
	       while (st != NULL)
	       {
	        	fout << st->info << " ";
	         	st = st->Next;
	       }
        }
	//fout << endl;
	fin.close();
	fout.close();
	return 0;
}


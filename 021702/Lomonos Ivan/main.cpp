#include<iostream>
#include<fstream>
#include"Queue.h"
using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	Queue queue;
	for (int i = 0; i < 6; i++)
	{
		int n; in >> n;
		queue.push(n);
	}
	for (int i = 0; i < 7; i++)
	{
		out << queue.pop() << " ";
	}
	out << '\n';
	int n; in >> n;
	queue.push(n);
	out << queue.pop();
	return 0;
}
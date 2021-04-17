#include "List.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	List L, M;
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			M.addHead(rand() % 10);
			L.addHead(rand() % 10);
		}
		else
		{
			M.addTail(rand() % 10);
			L.addTail(rand() % 10);
		}


	}
	cout << "Listr M:";
	M.print();
	cout << "List L:";
	L.print();
	cout << "Adding 8 to head of L" << endl;
	L.addHead(8);
	L.print();
	cout << "Adding 5 to tail of M" << endl;
	M.addTail(5);
	M.print();
	cout << "isnert on 5th position of L" << endl;
	L.insert(5);
	L.print();
	cout << "delete 5th position of M" << endl;
	M.del(5);
	M.print();
	cout << "Sorted Lists" << endl;
	M.sort_info();
	L.sort_info();
	M.print();
	L.print();
	cout << "Intersection" << endl;
	M.intersection(L, M);
	cout << "Merge" << endl;
	L.merge(L, M);
	system("PAUSE");
}
#include <iostream>
#include <stdio.h>
#include "arr.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	//TEST_A
	cout << "Test A: sorting" << endl;
	int size1; // Кол-во элементов
	int cnt = 0;
	vector <int> temp;
	int templ;
	
	ifstream filea("TEST_A.txt");
	if (filea)
	{
		filea >> size1;
		int *mass1 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			filea >> mass1[i];
		}
		for (int j = 0; j < size1; j++)
		{
			filea >> templ;
			temp.push_back(templ);
		}

		for (int i = 0;i < size1;i++)
		{
			cout << mass1[i] << ' ';
		}

		cout << endl << "Sorted array: " << endl;
		quickSort(mass1, 0, size1 - 1);
		for (int i = 0; i < size1; i++)
		{
			cout << mass1[i] << ' ';
		}

		for (int j = 0; j < size1;j++)
		{
			if (mass1[j] == temp[j])
			{
				cnt++;
			}
		}
		if (cnt == size1)
		{
			cout << endl << "DONE" << endl;
		}
		else
		{
			cout << endl << "ERROR" << endl;
		}

		cout << "==================================================" << endl;
	}

	temp.clear();
	cnt = 0;
	//TEST B
	cout << "Test B: sorting" << endl;
	ifstream fileb("TEST_B.txt");
	if (fileb)
	{
		fileb >> size1;
		int *mass1 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			fileb >> mass1[i];
		}
		for (int j = 0; j < size1; j++)
		{
			fileb >> templ;
			temp.push_back(templ);
		}

		for (int i = 0;i < size1;i++)
		{
			cout << mass1[i] << ' ';
		}

		cout << endl << "Sorted array: " << endl;
		quickSort(mass1, 0, size1 - 1);
		for (int i = 0; i < size1; i++)
		{
			cout << mass1[i] << ' ';
		}

		for (int j = 0; j < size1;j++)
		{
			if (mass1[j] == temp[j])
			{
				cnt++;
			}
		}
		if (cnt == size1)
		{
			cout << endl << "DONE" << endl;
		}
		else
		{
			cout << endl << "ERROR" << endl;
		}

		cout << "==================================================" << endl;
	}

	temp.clear();
	cnt = 0;
	int new_el;
	//TEST C
	cout << "Test C: element insertion" << endl;
	ifstream filec("TEST_C.txt");
	if (filec)
	{
		filec >> size1;
		int *mass1 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			filec >> mass1[i];
		}

		for (int i = 0;i < size1;i++)
		{
			cout << mass1[i] << ' ';
		}
		// sorted array
		cout << endl << "Sorted array: " << endl;
		quickSort(mass1, 0, size1 - 1);
		for (int i = 0; i < size1; i++)
		{
			cout << mass1[i] << ' ';
		}

		cout << endl;
		// new element 
		cout << "Array with new element: " << endl;

		filec >> new_el;

		element_insertion(mass1, new_el, size1);

		for (int i = 0; i < size1; i++)
		{
			cout << mass1[i] << ' ';
		}

		for (int j = 0; j < size1; j++)
		{
			filec >> templ;
			temp.push_back(templ);
		}

		for (int j = 0; j < size1;j++)
		{
			if (mass1[j] == temp[j])
			{
				cnt++;
			}
		}

		if (cnt == size1)
		{
			cout << endl << "DONE" << endl;
		}
		else
		{
			cout << endl << "ERROR" << endl;
		}

		cout << "==================================================" << endl;
	}
	
	// test d
	cout << "Test D: element search" << endl;
	temp.clear();
	cnt = 0;
	int srch_el;
	int indx;
	ifstream filed("TEST_D.txt");
	if (filed)
	{
		filed >> size1;
		int *mass1 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			filed >> mass1[i];
		}

		for (int i = 0;i < size1;i++)
		{
			cout << mass1[i] << ' ';
		}
		// sorted array
		cout << endl << "Sorted array: " << endl;
		quickSort(mass1, 0, size1 - 1);
		for (int i = 0; i < size1; i++)
		{
			cout << mass1[i] << ' ';
		}

		cout << endl << "What element are your looking for? " << endl;

		filed >> srch_el;

		cout << srch_el << endl;

		int srch = search(mass1, size1, srch_el);

		cout << "Index: " << srch << endl;
 
		filed >> indx;

		if (srch == indx)
		{
			cout << "DONE" << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}

		cout << "==================================================" << endl;

	}
		


	int size0; // Кол-во элементов
	cout << "Input size of the array: ";
	cin >> size0;
	int *mass1 = new int[size0];

	filling_the_array(mass1, size1);

	cout << "Sorted array: " << endl;

	for (int i = 0; i < size0; i++)
	{
		quickSort(mass1, 0, size0 - 1);
		cout << mass1[i] << ' ' << endl;
	}
	int size2;
	cout << "Input size of the array2: ";
	cin >> size2;
	int *mass2 = new int[size2];

	filling_the_array(mass2, size2);

	cout << "Sorted array2: " << endl;

	for (int j = 0; j < size2; j++)
	{
		quickSort(mass2, 0, size2 - 1);
		cout << mass2[j] << ' ' << endl;
	}

	cout << "intersection: " << endl;
	intersection(mass1, mass2, size0, size2);
	cout << endl;

	cout << "union" << endl;
	union1(mass1, mass2, size0, size2);
	cout << endl;

	delete[] mass1;
	delete[] mass2;
	

	return 0;
}
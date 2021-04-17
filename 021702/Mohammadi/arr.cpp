#include "arr.h"
#include <iostream>
#include <stdio.h>
#include <ctime>
#include<math.h>
#include <vector>

using namespace std;

void filling_the_array(int *arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 - 5;
		cout << arr[i] << ' ';
	}
}

bool sort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

void quickSort(int *arr, int left, int right)
{
	int mid, count;
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница

	mid = arr[(l_hold + r_hold) / 2]; //вычисление опорного элемента

	do
	{
			while (arr[l_hold] < mid)
				l_hold++;

			while (arr[r_hold] > mid)
				r_hold--;
		
		if(l_hold <= r_hold) //перестановка элементов
		{
			count = arr[l_hold];
			arr[l_hold] = arr[r_hold];
			arr[r_hold] = count;
			l_hold++;
			r_hold--;
		}
	}
	while (l_hold < r_hold);

	if (left < r_hold) quickSort(arr, left, r_hold);
	if (l_hold < right) quickSort(arr, l_hold, right);
}

void element_insertion(int *&arr, int newel, int &size )
{
	int *newarr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}

	newarr[size] = newel;

	size++;

	quickSort(newarr, 0, size - 1);

	delete[] arr;

	arr = newarr;
}

int search(int *arr, int size, int numb)
{
	int left = 0;
	int right = size;
	int middle = 0;
	while (1)
	{
		middle = (left + right) / 2;
		if (numb < arr[middle])
			right = middle - 1;
		else
			if (numb > arr[middle])
				left = middle + 1;
		else
			return middle;

		if (left > right)
			return -1;
	}
}

void identical_el(int *arr, int size)
{
	int i;
	int sz_count = 0;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		
		if (arr[i] == arr[i + 1] && i != i + 1)
		{
			++count;
		}
		sz_count = size - count;
	}
	
	int *arr2 = new int[sz_count];

	int j = 0;

		for (i = 0; i < size; i++)
		{
			if (arr[i] < arr[i + 1] || i + 1 == size)
			{
				arr2[j++] = arr[i];
			}
		}

		for (i = 0; i < sz_count; i++)
		{
			cout << arr2[i] << ' ';
		}


	
}

void intersection(int *arr1, int *arr2, int size1, int size2)
{
	
	int  i = 0, j = 0;
	if (sort(arr1, size1) && sort(arr2, size2))
	{
		while (i < size1 && j < size2)
		{
			if (arr1[i] == arr2[j])
			{
				cout << arr1[i] << ' ';
				i++;
				j++;
			}
			if (arr1[i] < arr2[j])
			{
				i++;
			}
			else
			{
				j++;
			}
		}
	}

	else

	{
		cout << "One of them is not sorted. Pls try again!" << endl;
	}
}

void union1(int *&arr1, int *&arr2, int &size1, int &size2)
{
	int k = 0, i = 0, j = 0;
	
	int size3 = size1 + size2;
	int *arr3 = new int[size3];

	if (sort(arr1, size1) && sort(arr2, size2))
	{
		while (i < size1 && j < size2)
		{
			if (arr1[i] < arr2[j])
			{
				arr3[k++] = arr1[i++];
			}
			else
			{
				arr3[k++] = arr2[j++];
			}
		}

		while (i < size1)
		{
			arr3[k++] = arr1[i++];
		}

		while (j < size2)
		{
			arr3[k++] = arr2[j++];
		}
	}

	else

	{
		cout << "One of them is not sorted. Pls try again!" << endl;
	}

	identical_el(arr3, size3);
}
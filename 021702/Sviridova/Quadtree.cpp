// Quadtree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include "Quadtree1.h"

using namespace std;

int main()
{

	Quadtree  Quadtree;

	cout << "1. Matrix from tree\n" <<
		"2. Tree from matrix\n";

	string a;
	cin >> a;

	if (a == "1")
		Quadtree.BuildMatrix();
	else if (a == "2")
		Quadtree.BuildTree();
	else
		cout << "Enter another number" << endl;

	return 0;
}

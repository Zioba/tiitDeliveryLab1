#pragma once
#include <vector>
#include <string>

using namespace std;


struct Data
{
public:
	Data* node;
	unsigned numb;
	Data* child[4];

	bool node__child;
};


class Quadtree
{
public:
	struct Data* rootnode;
	vector <vector <unsigned>> matr;
	unsigned position;
	unsigned maxposition;

	void CleanSpace(Data* construct);

	struct Data* BuildQuadTree(Data* node, vector <vector <unsigned>> inf);
	vector <vector <unsigned>> BuildMatrix(Data* node, vector <vector <unsigned> > matr, unsigned index, unsigned ri, unsigned rj);
	struct Data* Quadtreeform(Data* node, string d);
	vector <vector <unsigned>> Matrixform(unsigned k);
	void ShowT(Data* construct);
	void ShowM(vector <vector <unsigned>> matr);

	void BuildTree();
	void BuildMatrix();
};

unsigned translate(string str);
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "Quadtree1.h"

using namespace std;


void Quadtree::CleanSpace(Data* construct)
{
	if (construct != NULL)
	{
		for (unsigned i = 0; i < 4; i++)
			if (construct->child[i] != NULL)
				CleanSpace(construct->child[i]);
		delete construct;

		rootnode = NULL;
		position = 0;
		maxposition = 0;

		rootnode = new Data;
		for (int i = 0; i < matr.size(); i++)
			matr[i].clear();
		matr.clear();
	}
}

void Quadtree::BuildTree()
{
	cout <<
	"Matrix must be k*k elements,when k must be two in power.Enter k:\n";

	unsigned k;
	cin >> k;

	if (k > 0 && (k & (k - 1)) == 0)
	{
		cout << " Enter numbers by quantity k*k :\n";
		matr = Matrixform(k);
		cout << "Matrix :\n";
		ShowM(matr); //matr-matrix

		rootnode = NULL;
		rootnode = BuildQuadTree(rootnode, matr);
		cout << "\nRealization:\n\n ROOTnode   \n";
		ShowT(rootnode);
	}
	else if (((k & (k - 1)) != 0))
		cout << "Entered number is not two in power\n";
}
void Quadtree::BuildMatrix()
{

	cout << "First to build tree use * to create node with 4 children.\n" <<
	"Then enter value  of children, using space.\n";
	string d;
	cin >> d;
	rootnode = Quadtreeform(rootnode, d);

	cout << "\nRealization:\n\n ROOTnode  \n";
	ShowT(rootnode);
	unsigned size = pow(2, maxposition - 1);
	if (size < 1) size = 1;
	for (unsigned i = 0; i < size; i++)
	{
		vector <unsigned> row;
		for (unsigned i = 0; i < size; i++)
		row.push_back(0);
		matr.push_back(row);
	}

	matr = BuildMatrix(rootnode, matr, 0, 0, 0);
	ShowM(matr);
}

struct Data* Quadtree::BuildQuadTree(Data* node, vector <vector <unsigned>> matr)
{
	unsigned row = matr.size();
	unsigned col = matr.size();

	if (node == NULL)
	{
		node = new Data;
		for (unsigned i = 0; i < 4; i++)
		node->child[i] = NULL;

		if (col > 1 && row > 1)
		{
			unsigned n = 0, m = 0, matr_index_r = 0, matr_index_c = 0;//r-row,c-columb
			unsigned amt = col / 2;// amt-new amount

			for (unsigned i = 0; i < 4; i++)
			{
				node->child[i] = NULL;
				vector <vector <unsigned>> n_inf;
				n = matr_index_r * amt;
				m = matr_index_c * amt;

				for (unsigned j = m; j < m + amt; j++)
				{
					vector<unsigned> one_row;
					for (unsigned k = n; k < n + amt; k++)
					one_row.push_back(matr[j][k]);
					n_inf.push_back(one_row);
				}
				if (matr_index_r == 1)
				{
					matr_index_r = 0;
					matr_index_c++;
				}
				else
					matr_index_r++;
				node->child[i] = BuildQuadTree(node->child[i], n_inf);
				node->node__child = true;
				node->numb = 0;
			}
			if (node != NULL)
			{
				bool assosiation = true;
				unsigned sense = node->child[0]->numb;

				for (unsigned i = 0; i < 4; i++)
				if (node->child[i]->numb != sense || node->child[i]->node__child == true)
				assosiation = false;

				if (assosiation)
				{
					for (unsigned i = 0; i < 4; i++)
					{
						CleanSpace(node->child[i]);
						node->child[i] = NULL;
					}
					node = NULL;
					node = new Data;

					node->numb = sense;
					node->node__child = false;
					for (unsigned i = 0; i < 4; i++)
					node->child[i] = NULL;
				}
			}
		}
		else
		{
			node->numb = matr[0][0];
			node->node__child = false;
			for (unsigned i = 0; i < 4; i++)
				node->child[i] = NULL;
		}
	}
	return node;
}

vector <vector <unsigned>> Quadtree::BuildMatrix(Data* node, vector <vector <unsigned> > matr, unsigned num, unsigned endi, unsigned endj)
{
	int pos = (maxposition - position - 1);
	if (pos < 0) pos = 0;
	unsigned amt = pos * (4 / 2);
	if (amt <= 0) amt = 1;

	unsigned li = unsigned(num / (4 / 2) * amt);
	unsigned lj = (num% (4 / 2)) * amt;

	int bi = li + endi;
	int bj = lj + endj;

	if (node->node__child == false)
	{
		for (unsigned i = bi; i < bi + amt; i++)
		{
			for (unsigned j = bj; j < bj + amt; j++)
			{
				matr[i][j] = node->numb;
			}
		}
	}
	else
	{
		position++;
		for (unsigned i = 0; i < 4; i++)
		matr = BuildMatrix(node->child[i], matr, i, bi, bj);
		position--;
	}
	return matr;
}

struct Data* Quadtree::Quadtreeform(Data* node, string d)
{
	if (node == NULL)
	{
		node = new Data;
		for (unsigned i = 0; i < 4; i++)
		node->child[i] = NULL;
		node->numb = 0;
		node->node__child = false;
	}
	if (d == "*")
	{
		string form;
		for (unsigned i = 0; i < 4; i++)
		{
			if (node->child[i] == NULL)
			{
				cin >> form;
				node->child[i] = Quadtreeform(node->child[i], form);
			}
		}
		node->node__child = true;
	}
	else
	{
		unsigned a = translate(d);
		node->numb = a;
	}
	return node;
}
vector <vector <unsigned>> Quadtree::Matrixform(unsigned k)
{
	unsigned element;
	vector <vector <unsigned>> matrix;
	for (unsigned i = 0; i < k; i++)
	{
		vector <unsigned> matr;
		for (unsigned j = 0; j < k; j++)
		{
			cin >> element;
			matr.push_back(element);
		}
		matrix.push_back(matr);
	}
	return matrix;
}

void Quadtree::ShowT(Data* data)

{
	if (data != NULL)
	{
		position++;
		if (position >= maxposition)
			maxposition = position;
		cout << "    ";
		if (!data->node__child)
		{
			for (unsigned i = 0; i < position - 1; i++)
				cout << "   ";
			cout << "   " << data->numb << "\n";
		}
		else
		{
			for (unsigned i = 0; i < position - 1; i++)
				cout << "  ";
			cout << "    node " << "\n";

			for (unsigned i = 0; i < 4; i++)
			{
				ShowT((data->child[i]));
			}
		}
		position--;
	}
}
void Quadtree::ShowM(vector <vector <unsigned>> matr)
{
	unsigned k = matr.size();
	for (unsigned i = 0; i < k; i++)
	{
		for (unsigned j = 0; j < k; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << "\n";
	}
}

unsigned translate(string str)
{
	unsigned m = 0;
	for (unsigned i = 0; i < str.size(); i++)
	{
		m *= 10;
		if (str[i] - '0' >= 0 && str[i] - '0' < 10)
		m += str[i] - '0';

		if (i == 0 && str[i] == '*')
		m = 0;
	}
	return m;
}


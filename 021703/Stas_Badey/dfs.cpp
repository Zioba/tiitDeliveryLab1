#include <iostream>
#include "dfs.h"
#include <vector>
#include <iomanip>
#include <string>
#include <exception>

using namespace std;

int Atoi(string s)
{
	int i, ans = 0;
	for (i = 0; i < s.length(); i++)
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return -1;
		ans = ans * 10 + (s[i] - 48);
	}
	if (s.length() == 0)
		return -1;
	return ans;
}

void Graph::AddGraph()
{
	setlocale(0, "");

	cout << "Количество вершин:" << endl;
	getline(cin, s);
	if (s.length() > 8)
	{
		cout << "Слишком большое число\n";
		exit(0);
	}
	Node = Atoi(s);
	if (Node == -1)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
	if (Node == 0)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}

	cout << "Количество ребер между вершинами:" << endl;
	getline(cin, s);
	if (s.length() > 8)
	{
		cout << "Слишком большое число\n";
		exit(0);
	}
	Arc = Atoi(s);
	if (Arc == -1)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
	cout << endl;

	if (Arc == 0)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
	vec.resize(Node);

	for (int i = 0; i < Node; i++) {
		vec[i].resize(Node);
	}

	for (int i = 0; i < Node; i++)
	{
		for (int j = 0; j < Node; j++)
		{
			vec[i][j] = 0;
		}
	}

	cout << "Введите ребра:" << endl;

	for (int i = 0; i < Arc; i++)
	{
		getline(cin, s);
		x = Atoi(s.substr(0, s.find(' ')));
		y = Atoi(s.substr(s.find(' ') + 1, s.length() - s.find(' ') - 1));
		if (x == -1 || y == -1)
		{
			cout << "Ошибка, некорректный ввод!!" << endl;
			exit(0);
		}
		if (x > Node)
		{
			cout << "Ошибка, некорректный ввод!!" << endl;
			exit(0);
		}

		if (y > Node)
		{
			cout << "Ошибка, некорректный ввод!!" << endl;
			exit(0);
		}

		vec[x - 1][y - 1] = 1;
		vec[y - 1][x - 1] = 1;
	}
	cout << endl;

	for (int i = 0; i < Node; i++)
	{
		for (int j = 0; j < Node; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::Answer()
{
	AddGraph();
	cout << "Выберите команду:" << endl << endl;

	cout << "1. Вставка вершины" << endl;
	cout << "2. Удаление вершины" << endl;
	cout << "3. Вставка дуги" << endl;
	cout << "4. Удаление дуги" << endl;
	cout << "5. DFS" << endl << endl;

	getline(cin, s);
	answer = Atoi(s);
	if (answer == -1)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
	if (answer > 5 || answer < 1)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}

	cout << endl;

	if (answer == 1)
	{
		AddNode();
	}
	if (answer == 2)
	{
		DelNode();
	}
	if (answer == 3)
	{
		AddArc();
	}
	if (answer == 4)
	{
		DelArc();
	}
	if (answer == 5)
	{
		vector <bool> visited(Node, 0);
		dfs(0, visited);
	}
	if (answer < 1 && answer > 5)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
}

void Graph::AddNode()
{
	Node++;
	vec.resize(Node);
	for (int i = 0; i < (Node); i++)
	{
		vec[i].resize(Node);
	}

	for (int i = 0; i < (Node); i++)
	{
		for (int j = 0; j < (Node); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::DelNode()
{
	Node--;
	vec.resize(Node);
	for (int i = 0; i < (Node); i++)
	{
		vec[i].resize(Node);
	}

	for (int i = 0; i < (Node); i++)
	{
		for (int j = 0; j < (Node); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::AddArc()
{
	cout << "Введите ребра:" << endl;

	getline(cin, s);
	x1 = Atoi(s.substr(0, s.find(' ')));
	y1 = Atoi(s.substr(s.find(' ') + 1, s.length() - s.find(' ') - 1));

	if (x1 == -1 || y1 == -1)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
	if (x1 > Node)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}

	if (y1 > Node)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}

	vec[x1 - 1][y1 - 1] = 1;
	vec[y1 - 1][x1 - 1] = 1;

	cout << endl;

	for (int i = 0; i < Node; i++)
	{
		for (int j = 0; j < Node; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

}

void Graph::DelArc()
{
	cout << "Введите ребра:" << endl;

	getline(cin, s);
	x1 = Atoi(s.substr(0, s.find(' ')));
	y1 = Atoi(s.substr(s.find(' ') + 1, s.length() - s.find(' ') - 1));

	if (x1 == -1 || y1 == -1)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}
	if (x1 > Node)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}

	if (y1 > Node)
	{
		cout << "Ошибка, некорректный ввод!!" << endl;
		exit(0);
	}

	vec[x1 - 1][y1 - 1] = 0;
	vec[y1 - 1][x1 - 1] = 0;

	cout << endl;

	for (int i = 0; i < Node; i++)
	{
		for (int j = 0; j < Node; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

}

void Graph::dfs(int node_index, vector <bool>& visited)
{
	visited[node_index] = true;
	cout << "DFS " << node_index + 1 << endl;

	vector<int> tmp = vec[node_index];
	for (int j = 0; j < Node; ++j) {
		if ((visited[j] == 0) && tmp[j] != 0)  dfs(j, visited);
	}
}
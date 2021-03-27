#pragma once
struct node //вершина дерева отрезков
{
	int summa, LeftPos, RightPos, add_value; //summa - отвечает за сумму, LeftPos - левая граница, RightPos - правая граница
	node* Left, * Right; //Left - левое поддерево, Right - правое
};

node* build(std::vector<int>&, int, int);

int sum(node*, int, int);

void update(node*, int, int);

void add(node*, int, int, int);

void print(node*, int);
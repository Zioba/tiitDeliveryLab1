#include <vector>
#include <iostream>
#include "tree_of_sum.h"

node* build(std::vector<int>& a, int L, int R) //построение дерева
{
	/*если левая сторона
	  равняется правой -
	  строим дерево из одной вершины*/
	if (L == R)
	{
		node* obj = new node; //выделение динамической памяти для obj

		obj->summa = a[L]; //присваиваем summa значение левой границы
		obj->add_value = 0;
		obj->Left = obj->Right = NULL; //присваиваем левой и правой ветви 0
		obj->LeftPos = obj->RightPos = L; //присваиваем левой и правой границе левый индекс
		return obj; //возвращаем obj
	}

	int middle = (L + R) / 2; //находим середину дерева

	node* Left = build(a, L, middle); //построение левой ветви
	node* Right = build(a, middle + 1, R); //построение правой ветви

	node* tree = new node; //создание результирующего дерева Tree
	tree->Left = Left;     //с левым
	tree->Right = Right;   //и правым поддеревом

	tree->summa = Left->summa + Right->summa;
	tree->add_value = 0;
	tree->LeftPos = Left->LeftPos;
	tree->RightPos = Right->RightPos;

	return tree; //возвращаем tree
}

int sum(node* tree, int L, int R) //сумма дерева
{
	if (L < tree->LeftPos) //в двух if'ах обрезаем
		L = tree->LeftPos; //отрезок [L;R] таким образом,

	if (R > tree->RightPos) //чтобы он входил в отрезок
		R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
							//которому соответствует вершина дерева tree
	if (L > R) //если полученный отрезок окажется пустым, то выходим
		return 0; //возвращаем сумму 0

	if ((tree->LeftPos == L) && (tree->RightPos == R)) // если корень дерева tree соответствует отрезку [L..R],
		return tree->summa; // то возвращаем значение суммы, хранящейся в этом корне

	int LeftSum = sum(tree->Left, L, R); //считаем сумму левого поддерева
	int RightSum = sum(tree->Right, L, R); //считаем сумму правого поддерева

	return LeftSum + RightSum; //возвращаем левое поддерево + правое
}

void update(node* tree, int L, int R)
{
	if (L < tree->LeftPos) //в двух if'ах обрезаем
		L = tree->LeftPos; //отрезок [L;R] таким образом,

	if (R > tree->RightPos) //чтобы он входил в отрезок
		R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
							//которому соответствует вершина дерева tree
	if (L > R) //если полученный отрезок окажется пустым, то выходим
		return;//из процедуры
	if ((tree->LeftPos == L) && (tree->RightPos == R) && (L == R)) //если корень дерева tree соответствует отрезку [L,R], то изменяем данные в нем
		return;
	update(tree->Left, L, R); //рекурсивно модифицируем
	update(tree->Right, L, R);//левое и правое поддерево
	tree->add_value = tree->Left->add_value + tree->Right->add_value;
}

void add(node* tree, int L, int R, int value) //прибавление значения value к существующим элементам значение
{
	if (L < tree->LeftPos) //в двух if'ах обрезаем
		L = tree->LeftPos; //отрезок [L;R] таким образом,

	if (R > tree->RightPos) //чтобы он входил в отрезок
		R = tree->RightPos; //[tree->LeftPos; tree->RightPos],
							//которому соответствует вершина дерева tree
	if (L > R) //если полученный отрезок окажется пустым, то выходим
		return;//из процедуры
	if ((tree->LeftPos == L) && (tree->RightPos == R) && (L == R)) //если корень дерева tree соответствует отрезку [L,R], то изменяем данные в нем
	{
		tree->add_value += value;
		return;
	}
	add(tree->Left, L, R, value); //рекурсивно модифицируем
	add(tree->Right, L, R, value);//левое и правое поддерево
}

void print(node* curNode, int depth) { //на вход подаётся текущая вершина и глубина, на которой эта вершина

	if (curNode)
	{
		print(curNode->Left, depth + 1);

		for (int i = 0; i < depth * 4; i++)
		{
			std::cout << ' ';
		}

		std::cout << curNode->summa + curNode->add_value << std::endl;
		print(curNode->Right, depth + 1);
	}
}

// tiit 1 lib.cpp : Определяет функции для статической библиотеки.
//

#include <iostream>
#include "tiit 1 lib.h"
#include <string>

using namespace std;

// TODO: Это пример библиотечной функции.

int tabs = 0; //Для создания отступов

int kol_vo = 0;

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна


}




node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (k > 0) {
		if (!p) return new node(k);
		if (!Search(k, p)) {
			if (k < p->key)
				p->left = insert(p->left, k);
			else
				p->right = insert(p->right, k);
		}
		return balance(p);
	}
	else {
		if (!p) return NULL;
		else {

			return p;
		}
	}
}

node* findmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findmin(p->left) : p;
}

node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* remove(node* p, int k) // удаление ключа k из дерева p
{
	if (Search(k, p)) {
		if (!p) return 0;
		if (k < p->key)
			p->left = remove(p->left, k);
		else if (k > p->key)
			p->right = remove(p->right, k);
		else //  k == p->key 
		{
			node* q = p->left;
			node* r = p->right;
			delete p;
			if (!r) return q;
			node* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}
	else {
		return p; }
}





//Функция внесения данных

int SearchMin(node* aBranch) {
	/*if (aBranch == NULL)
		return -1;*/
	if(aBranch->left != NULL) {
	return  SearchMin(aBranch->left);
	}
	else {
		return aBranch->key;
		exit;
	}
}

int SearchMax(node* aBranch) {
	/*if (aBranch == NULL)
		return -1;*/

	if (aBranch->right != NULL) {
		return SearchMax(aBranch->right);
	}
	else {
		return aBranch->key;
		exit;
	}
}


bool Search(int aData,node* aBranch){
	if (aBranch == NULL)
		return false;
	if (aData == aBranch->key) {
		return true;
		exit;
	}
	else {
		if (aData > aBranch->key) {
			if (aBranch->right== NULL)
			{
				return false;
				exit;
			}
			else
				return Search(aData, aBranch->right);

		}
		else
		{
			if (aBranch->left == NULL)
			{
				return false;
				exit;
			}
			else
				return Search(aData, aBranch->left);
		}
	}
	
}













//Функция вывода дерева

void print(node* aBranch)

{

	if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего

	tabs += 5; //Иначе увеличим счетчик рекурсивно вызванных процедур

	//Который будет считать нам отступы для красивого вывода

	print(aBranch->right); //Выведем ветку и ее подветки слева

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы

	cout << aBranch->key << endl; //Данные этой ветки

	print(aBranch->left);//И ветки, что справа

	tabs -= 5; //После уменьшим кол-во отступов

	return;
}

void blig_bol(node* aBranch, int n, int* k, bool flag) {
	pr_obh_bol(aBranch, n, k, flag);
	if (*k < 0) {
		*k=-1;
	}
	else {
		cout << *k << endl;
	}

}

void blig_men(node* aBranch, int n, int* k, bool flag) {
	pr_obh_men(aBranch, n, k, flag);
	if (*k < 0) {
		*k = -1;
	}
	else {
		cout << *k << endl;
	}

}

void pr_obh_bol(node* aBranch,int n, int *k,bool flag)

	{

		if (NULL == aBranch) return; //Если дерева нет, выходим
		if (!flag) {
			if ((aBranch->key >= n) and (aBranch->key < *k)) {
				*k = aBranch->key;
			}
		}
		else {
			if (aBranch->key >= n) {
				*k = aBranch->key;
				flag = false;
			}
		}

		


		//cout << aBranch->key << endl; //Посетили узел

		pr_obh_bol(aBranch->left,n,k,flag); //Обошли левое поддерево

		pr_obh_bol(aBranch->right,n,k,flag); //Обошли правое поддерево

	}

void pr_obh_men(node* aBranch, int n, int* k, bool flag)

{

	if (NULL == aBranch) return; //Если дерева нет, выходим
	if (!flag) {
		if ((aBranch->key <= n) and (aBranch->key > *k)) {
			*k = aBranch->key;
		}
	}
	else {
		if (aBranch->key <= n) {
			*k = aBranch->key;
			flag = false;
		}
	}




	//cout << aBranch->key << endl; //Посетили узел

	pr_obh_men(aBranch->left, n, k, flag); //Обошли левое поддерево

	pr_obh_men(aBranch->right, n, k, flag); //Обошли правое поддерево

}













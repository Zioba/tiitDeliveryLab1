#include <vector>
#include <iostream>
using namespace std;
struct Node
{
    int info;                           //Информационное поле
    Node *l, *r;                        //Левая и Правая часть дерева
};
void push(int a, Node **t);  //ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО
Node* search(Node *tree,int a);               //Функция поиска узла в дерева
void infix_traverse(Node *t, int u);                 //ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
void postfix_traverse(Node *t, int u);                 //ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
void prefix_traverse(Node *t, int u);                 //ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
void create_tree_from_massiv(Node **t, std::vector<int> a);      //из массива в дерево
Node* insert(Node *pNode, int i, int i1);
bool findbool(Node *tree,int a);
void remove(Node* tree,int a);


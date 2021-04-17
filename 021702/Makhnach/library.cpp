#include "library.h"

void push(int a, Node **t)  //ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО
{
    if ((*t) == NULL)                   //Если дерева не существует
    {
        (*t) = new Node;                //Выделяем память
        (*t)->info = a;                 //Кладем в выделенное место аргумент a
        (*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
        return;                         //Заложили семечко, выходим
    }
    //Дерево есть
    if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
    else push(a, &(*t)->l);         //Иначе кладем его влево
}



Node* search(Node *tree,int a) {              //Функция поиска узла в дерева
    if (tree != NULL)
    {
        if (tree->info == a)
        {
            return tree;
        }
        if (tree->info > a)
            search(&(*tree->l), a);
        if (tree->info < a)
            search(&(*tree->r), a);
    }
}

bool findbool(Node *tree,int a) {              //Функция поиска узла в дерева
    if (tree != NULL)
    {
        if (tree->info == a)
        {
            return true;
        }
        if (tree->info > a)
            findbool(&(*tree->l), a);
        if (tree->info < a)
            findbool(&(*tree->r), a);
    }
}


void infix_traverse (Node *t, int u)                 //ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
{
    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        infix_traverse(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        for (int i=0; i<u; ++i) cout << "   ";
        cout << t->info << endl;            //И показываем элемент
        u--;
    }
    infix_traverse(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
}



void postfix_traverse (Node *t, int u)                 //ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
{
    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        postfix_traverse(t->r, ++u);                  //С помощью рекурсии посещаем правое поддерево
        for (int i=0; i<u; ++i) cout << "   ";
        cout << t->info << endl;            //И показываем элемент
        u--;
    }
    postfix_traverse(t->l, ++u);              //С помощью рекурсивного посещаем левое поддерево
}



void prefix_traverse (Node *t, int u)                 //ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
{
    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        for (int i=0; i<u; ++i) cout << "   ";
        cout << t->info << endl;            //И показываем элемент
        prefix_traverse(t->l, ++u);         //С помощью рекурсивного посещаем левое поддерево
        u--;
    }
    prefix_traverse(t->r, ++u);                  //С помощью рекурсии посещаем правое поддерево
}



void create_tree_from_massiv(Node **t, vector<int> a){      //из массива в дерево
    for (int i = 0; i < a.size(); ++i) {
        push(a[i],t);
    }
}



Node* insert(Node *t, int key, int newpoint){
    if (findbool(t, key)) {
        Node *m = search(t, key);
        push(newpoint, &m);
    }
    return t;
}


void remove(Node* tree,int key) {
    if (findbool(tree, key)) {
        if (tree->l->info==key)
            tree->l=NULL;
        if (tree->r->info==key)
            tree->r=NULL;
        if (tree->info>key)
            remove(tree->l,key);
        if (tree->info<key)
            remove(tree->r,key);
    }
    return;
}




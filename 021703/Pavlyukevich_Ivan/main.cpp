#include <iostream>
#include <Windows.h>
#include "Tree.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BTree* tree1 = new BTree();
    
    for (int i = 120; i > 0; i--)
    {
        tree1->insert(i);
    }
    
    cout << "======================";

    int choice, key;
    while (true)
    {
        cout << "\n\n1 - добавить\n2 - удалить\n3 - существует ли элемент\n4 - вывести всё\n";
        cin >> choice;
        system("cls");
        switch(choice)
        {
        case 1: cin >> key; tree1->insert(key); break;
        case 2: cin >> key; tree1->remove(key); break;
        case 3: cin >> key; cout << tree1->search(key); break;
        case 4: tree1->show(); break;

        default: return 0;
        }
    }

}

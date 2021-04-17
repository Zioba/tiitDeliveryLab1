#include "library.h"
int main ()
{
    system("chcp 65001");
    vector <int> v;
    int a,b,n,nmassiv,temp;
    Node *tree = NULL, *derevo=NULL;
    cout << "введите количество элементов дерева ";
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cout << "введите число  ";
        cin >> temp;
        push(temp, &tree);
    }
    cout<<"\nвведите количество элементов массива ";
    cin>>nmassiv;
    for (int i=0; i<nmassiv; ++i)
    {
        cout << "введите элемент массива ";
        cin >> temp;
        v.push_back(temp);//Считываем элемент за элементом
    }
    create_tree_from_massiv(&derevo, v);
    cout << "\nваше дерево из массива\n";
    infix_traverse(derevo, 0);
    cout << "\nваше дерево\n";
    infix_traverse(tree, 0);
    cout<<"\nвведите искомый элемент\n";
    cin>>a;
    if(findbool(tree, a)) {
        cout << "\nсуществует в дереве\n";
    }
    if(findbool(derevo,a))
        cout<<"\nсуществует в дереве созданного из массива\n";
    cout<<"введите элемент который хотите вставить и куда вставить";
    cin>>b>>a;
    derevo=insert(derevo, a, b);
    tree=insert(tree, a, b);
    infix_traverse(tree,0);
    infix_traverse(derevo,0);
    cin>>a;
    remove(derevo,a);
    remove(tree,a);
    cout<<"обходы в дереве созданного из массива: ";
    cout<<"\nобход infix \n";infix_traverse(derevo, 0);
    cout<<"\nобходы postfix \n";postfix_traverse(derevo, 0);
    cout<<"\nобходы prefix \n";prefix_traverse(derevo,0);
    cout<<"обходы для дерева: ";
    cout<<"\nобход infix \n";infix_traverse(tree, 0);
    cout<<"\nобходы postfix \n";postfix_traverse(tree, 0);
    cout<<"\nобходы prefix \n";prefix_traverse(tree,0);
    return 0;
}
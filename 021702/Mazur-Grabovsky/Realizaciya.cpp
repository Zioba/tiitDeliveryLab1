// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Biblioteka.h"
using namespace std;
int main()
{
    dis_set st;
    bool flag = true;
    do
    {
        foo();
        cout << "Choose what to do:" << endl
            << "1) make new union" << endl
            << "2) join union" << endl
            << "3) find root" << endl
            << "4) End" << endl;
        foo();
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
        {
            cout << "Union size: " << endl;
            int x;
            cin >> x;
            for (int i = 1; i < x; i++)
                st.make_set(i);
            cout << "Union 1 - " << x - 1 << " set" << endl;
            break;
        }
        case 2:
        {
            cout << "What unions to merge: " << endl;
            int x, y;
            cin >> x >> y;
            if (st.find_set(x) == st.find_set(y))
            {
                cout << "Already merged " << x << ' ' << y << endl;
            }
            st.merge_set(x, y);
            break;
        }
        case 3:
        {
            int x;
            cout << "for which element? ";
            cin >> x;
            cout << st.find_set(x) << endl;
            break;
        }
        case 4:
            flag = false;
            break;
        }
    } while (flag == true);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

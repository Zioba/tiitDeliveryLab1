// 1 лаба по тиит(2 сем).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	que* b = nullptr, * e = nullptr;
	int k, sw, elem, num, priority, col = 0, del, j = 1;
	while (j < argc)
	{
		if (strcmp(argv[j], "add") != 0 && strcmp(argv[j], "view") != 0 && strcmp(argv[j], "remove") != 0)
		{
			cout << "Некорректный ввод!\n";
			break;
		}

		if (strcmp(argv[j], "add") == 0)
		{
			j++;

			if (j >= argc)
			{
				cout << "Некорректный ввод!\n";
				break;
			}
			elem = atoi(argv[j++]);
			
			if ((elem == 0 && argv[j - 1][0] != '0') || j >= argc)
			{
				cout << "Некорректный ввод!\n";
				break;
			}
			priority = atoi(argv[j++]);
			if (priority == 0 && argv[j - 1][0] != '0')
			{
				cout << "Некорректный ввод!\n";
				break;
			}
			col++;
			add_all(&b, &e, elem, priority, col);
		}

		else if (strcmp(argv[j], "view") == 0)
		{
			j++;
			if (b == 0)
			{
				cout << "Элементов в очереди нет" << endl;
				continue;
			}
			view_all(b);
		}

		else if (strcmp(argv[j], "remove") == 0)
		{
			j++;
			if (j >= argc)
			{
				cout << "Некорректный ввод!\n";
				break;
			}
			if (b == 0)
			{
				cout << "Элементов в очереди нет" << endl;
				j++;
				continue;
			}
			del = atoi(argv[j++]);
			if (del == 0 && argv[j - 1][0] != '0')
			{
				cout << "Некорректный ввод!\n";
				break;
			}
			take_el(&b, &e, del);
			continue;
		}
	}
}
#include <iostream>
#include "steck.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	Stack s;
	Creation(&s);
	char number;
	do
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести верхний элемент" << endl;
		cout << "4. Узнать размер стека" << endl;
		cout << "0. Выйти" << endl;
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{
		case '1':
			if (Full(&s) == -1) cout << endl << "Стек заполнен\n\n";
			else
			{
				Add(&s);
				cout << endl << "Элемент добавлен в стек\n\n";
			} break;
	
		case '2':
			if (Full(&s) == 1) cout << endl << "Стек пуст\n\n";
			else
			{
				Delete(&s);
				cout << endl << "Элемент удален из стека\n\n";
			} break;
	
		case '3':
			if (Full(&s) == 1) cout << endl << "Стек пуст\n\n";
			else cout << "\nВерхний элемент: " << Top(&s) << "\n\n";
			break;

		case '4':
			if (Full(&s) == 1) cout << endl << "Стек пуст\n\n";
			else cout << "\nРазмер стека: " << Size(&s) << "\n\n";
			break;

		case '0': break;
		default: cout << endl << "Команда не определена\n\n";
			break;
		}
	} while (number != '0');

	system("pause");
}
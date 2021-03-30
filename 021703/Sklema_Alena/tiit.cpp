#include <iostream>
#include "biblio.h"
#include <fstream>
#include <string>



int main() {
	setlocale(LC_ALL, "RUS");
	SET* A = NULL;
	SET* B = NULL;
	string test[5];
	//Добавление элементов в множество А
	A = insert(A, 12);
	A = insert(A, 12);
	A = insert(A, 9);
	A = insert(A, 24);
	cout << "Вывод множества A" << endl;
	cout << print(A) << endl;
	test[0] = print(A);
	//Удаление эл 24
	A = remove(A, 24);
	cout << "Вывод множества A без элемента со значением 24" << endl;
	cout << print(A) << endl;
	test[1] = print(A);
	//Добавление элементов в множество B
	B = insert(B, 1);
	B = insert(B, 2);
	B = insert(B, 9);
	B = insert(B, 3);
	cout << "Вывод множества B" << endl;
	cout << print(B) << endl;
	test[2] = print(B);
	cout << "Объединение A и B" << endl;
	cout << print(uni(A, B)) << endl;
	test[3] = print(uni(A, B));
	cout << "Пересечение A и B" << endl;
	cout << print(cros(A, B)) << endl;
	test[4] = print(cros(A, B));

	string path = "D:\\tiit(1).txt";

	ifstream F;
	//открываем папку с тестовыми значениями
	F.open(path);
	if (!F.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		string str;
		int n = 2;
		while (!F.eof())
		{
			str = "";
			getline(F, str);
			//прописываем функцию для поиска и сравнения
			if (n % 2 == 1) {
				cout << "Тестовые значения: " << str << endl;
				cout << "Полученные значения: " << test[n / 2 - 1] << endl;
				if (str == test[n / 2 - 1]) {
					cout << "Тест " << n / 2 << " пройден\n";
					cout << endl;
				}
				else
				{
					cout << "Тест " << n / 2 << " не пройден\n";
					cout << endl;
				}
			}
			else {
				cout << str << endl;
			}
			n++;
		}
	}
	//закрываем и очищаем
	F.close();

	return 0;
}

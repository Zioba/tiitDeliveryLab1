// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "tiit 1 lib.h"
#include <set>
#include "ctime"
#include <fstream>
#include <string>


using namespace std;

int main()

{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	node* Root = 0;

	int vel;

	int element, element1;

	int k;

	int n, n1;

	int x, x1;

	string test[7];

	set <int> st;



	string path = "E:\\blig_men.txt";

	ifstream F;
	F.open(path);
	n = 1;
	if (!F.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		string str;
		while (!F.eof())
		{
			str = "";
			getline(F, str);
			if (n == 1) {
				vel = atoi(str.c_str());
			}
			while ((n < vel + 2) and (n > 1)) {
				st.insert(atoi(str.c_str()));
				n++;
				str = "";
				getline(F, str);
			}
			if (n == (vel + 2)) {
				element = atoi(str.c_str());
			}
			if (n == (vel + 3)) {
				element1 = atoi(str.c_str());
			}
			if (n == (vel + 4)) {
				n1 = atoi(str.c_str());
			}
			if (n == (vel + 5)) {
				x = atoi(str.c_str());
			}
			if (n == (vel + 6)) {
				x1 = atoi(str.c_str());
			}


			n++;
		}
	}

	F.close();
	if ((n - 1) != (vel + 6)) {
		cout << "Неправильный ввод";
	}
	else {






		/*cout << "Введите кол-во элементов для будущего дерева: ";*/

	//	cin >> vel;

		cout << endl;

		//	while (st.size() < vel) {
		//		st.insert(rand() % (vel+100));
		//	}

		set<int>::iterator it; //создание итератора

		for (it = st.begin(); it != st.end(); it++) { // Вывод всех элементов

			Root = insert(Root, *it);// множества

		}





		cout << "Вывод AVL дерева: " << endl;

		print(Root);

		cout << endl;



		cout << endl;

		cout << "Добавим новый элемент в AVL дерево:" << endl;

		//cout << "Введите новый элемент: ";


		if (element > 0) {
			if (Search(element, Root)) {
				test[0] = "-1";
			}
			else {
				Root = insert(Root, element);
				if (Search(element, Root)) {
					test[0] = "1";
				}
				else {
					test[0] = "0";
				}
			}
		}
		else {
			test[0] = "-1";
		}


		cout << "Вывод AVL дерева: " << endl;

		print(Root);

		cout << endl;

		cout << "Удалим элемент из AVL дерева:" << endl;

		//cout << "Введите элемент: ";

		//cin >> element;


		cout << "Вывод AVL дерева: " << endl;

		if (Search(element1, Root)) {
			Root = remove(Root, element1);
			if (!Search(element1, Root)) {
				test[1] = "1";
			}
			else {
				test[1] = "0";
			}
		}
		else {
			test[1] = "-1";
		}
		print(Root);

		cout << endl;


		//cout << "Найдем какой-то элемент дерева: ";

	//	cin >> n;

		//cout<< Search(n1, Root)<<endl;
		if (Search(n1, Root)) {
			test[2] = "1";
		}
		else {
			test[2] = "-1";
		}

		//	cout << "Вывод мин элемента дерева: ";
		//	cout<< SearchMin(Root)<<endl;

		test[3] = to_string(SearchMin(Root));


		//	cout << "Вывод макс элемента дерева: ";
		//	cout << SearchMax(Root) << endl;
		test[4] = to_string(SearchMax(Root));
		int kk = -1;
		int* y;
		y = &kk;
		bool flag = true;
		//cout << "Введите число для которого будем искать ближайшее большее: ";
		//cin >> x;
		//cout << "Вывод ближайшего большего:";
		pr_obh_bol(Root, x, y, flag);
		test[5] = to_string(*y);

		int kk1 = -1;
		int* y1;
		y1 = &kk1;
		bool flag1 = true;
		//cout << "Введите число для которого будем искать ближайшее меньшее: ";
		//cin >> x1;
		//cout << "Вывод ближайшего меньшего:";
		pr_obh_men(Root, x1, y1, flag1);;
		test[6] = to_string(*y1);

		string path1 = "E:\\blig_bol.txt";

		ifstream F1;
		F1.open(path1);
		setlocale(LC_ALL, "Rus");
		if (!F1.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else
		{
			cout << "Файл открыт!" << endl;
			string str;
			int n = 2;
			while (!F1.eof())
			{
				str = "";
				getline(F1, str);
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

		F1.close();



	}
}

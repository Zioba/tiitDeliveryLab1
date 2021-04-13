#include "work.h"




void Output(vector <int> &number_of_elements, vector <int> &all_elements, int size, int init_for_output)
{
	for (int i = 0;i < number_of_elements.size(); i++)
	{
		init_for_output += 1;
		size = number_of_elements[i] + size;
		for (int j = init_for_output; j < size;j++)
		{
			cout << all_elements[j] << " ";
			init_for_output = j;
		}
		cout << endl;
	}

}

void Add_e(vector <int> &number_of_elements, vector <int> &all_elements, int current)
{
	int final_e = 0;
	int init_for_output = -1, size = 0, temp1 = 0, previos_e, temp5 = 0;
	int  cnt = 0, cnt1 = 0, initial_e = 0;
	for (int i = 0; i < number_of_elements.size();i++)
	{
		final_e += number_of_elements[i];
		for (int j = initial_e;j < final_e;j++)
		{
			if (current > all_elements[j])
			{
				cnt++;
			}
			cnt = initial_e + cnt;
			if (current < all_elements[j])
			{
				temp1 = all_elements[cnt];
				all_elements[cnt] = current;
				current = temp1;
				cnt1++;

			}

			if (cnt == final_e && cnt1 == 0)
			{
				previos_e = all_elements[j + 2];
				all_elements[j + 2] = all_elements[j + 1];
				all_elements[j + 1] = current;

				number_of_elements[i] = number_of_elements[i] + 1;

				temp5++;


			}

			if (cnt1 > 0)
			{
				j = final_e;
				initial_e = initial_e + number_of_elements[i];

			}

		}
		if (temp5 != 0)
		{
			i = number_of_elements.size();
		}

	}
	if (temp5 == 0)
	{
		number_of_elements.push_back(1);
		previos_e = current;
	}

	all_elements.push_back(previos_e);
	cout << endl;



}

void Test(int current, int s, int t, vector <int> &added, vector <int> &deleted)
{
	int repCurr = 0;

	vector <int> all_elements{ 2,4,5,3,9 };
	vector <int> number_of_elements{ 3,2 };
	vector <int> check;

	for (int i = 0; i < all_elements.size(); i++)
	{
		if (current == all_elements[i])
		{
			repCurr++;
		}
	}

	if (repCurr > 0 || t > 4)
	{
		cout << "ОШИБКА! ЗНАЧЕНИЕ НЕ ПОДХОДИТ" << endl;
	}
	else {
		int init_for_output = -1, size = 0, cnt1 = 0, spc = 0, spc1 = 0;





		cout << "Таблица Юнга" << endl;
		Output(number_of_elements, all_elements, size, init_for_output);





		for (int i = 0; i < all_elements.size(); i++)
		{
			if (current == all_elements[i])
			{
				cnt1++;
			}


		}

		if (cnt1 == 0)
		{
			Add_e(number_of_elements, all_elements, current);
			cout << "После добавления ( " << current << " ) таблица Юнга выглядит следующим образом " << endl;
			Output(number_of_elements, all_elements, size, init_for_output);
		}
		else
		{
			cout << "Введите другой элемент";


		}


		for (int i = 0; i < added.size(); i++)
		{
			if (added[i] == all_elements[i])
			{
				spc++;
			}
		}
		cout << endl;
		if (spc == added.size())
		{
			cout << endl << "Тест пройден" << endl;

		}

		else
		{
			cout << "Ошибка";
		}
		cout << endl;


		cout << "Удалим элемент с позиции ( " << s << " )  ( " << t << " ) " << endl;
		spc1 = 0;


		if (s > number_of_elements.size())
		{
			cout << "NO!";

		}
		else
		{
			Delete(all_elements, number_of_elements, check, s, t);
		}

		for (int i = 0; i < deleted.size(); i++)
		{
			if (deleted[i] == all_elements[i])
			{
				spc1++;
			}
		}

		if (spc1 == deleted.size())
		{
			cout << endl << "Тест пройден" << endl;
		}
		else
		{
			cout << "Ошибка";
		}
		spc1 = 0;
		spc = 0;


	}
}

void Delete(vector <int> &all_elements, vector <int> &number_of_elements, vector <int> check, int s, int t)
{
	int  init = 0, cnt = 0, fff = 0, j = 0, size = 0, init2 = 0, sum = 0, inst = 0, temp = 0, init_for_output = -1, zz = 0, temp1 = 0, qw = 0, cnt7 = 0;
	vector <int> buf;
	for (int i = 0;i < s - 1;i++)
	{
		init = init + number_of_elements[i];

	}
	for (int j = init;j < init + number_of_elements[s - 1];j++)
	{
		cnt++;
		if (cnt == t)
		{
			fff = all_elements[j];


		}
	}
	cout << endl;

	for (int i = 0;i < all_elements.size();i++)
	{
		if (fff > all_elements[i])
			cnt7++;
	}

	if (cnt7 == all_elements.size() - 1)
	{
		number_of_elements[t - 1]--;

		for (int i = 1;i < all_elements.size();i++)
		{
			if (all_elements[i - 1] == fff)
			{
				all_elements[i - 1] = all_elements[i];
			}
		}
		all_elements[number_of_elements[0] - 1] = fff;

		for (int i = 0;i < number_of_elements.size();i++)
		{
			temp1 = temp1 + number_of_elements[i];
			for (int j = zz;j < temp1;j++)
			{



				int all_elemenetsj = all_elements[j];
				cout << all_elements[j] << " ";
				init_for_output = j;
				buf.push_back(all_elemenetsj);



				qw = j;

			}
			zz = qw + 1;
			cout << endl;
		}
		cout << endl;
	}



	else {
		if (s == 1)
		{
			number_of_elements[0]--;
			for (int i = 0;i < number_of_elements.size();i++)
			{
				temp1 = temp1 + number_of_elements[i];
				for (int j = zz;j < temp1 + 1;j++)
				{
					if (all_elements[j] != fff)
					{
						int all_elemenetsj = all_elements[j];
						cout << all_elements[j] << " ";
						init_for_output = j;
						buf.push_back(all_elemenetsj);


					}
					qw = j;

				}
				zz = qw + 1;
				cout << endl;
			}
			cout << endl;

		}

		else
		{
			int sizeb = number_of_elements.size() - 1;
			inst = t - 1;
			for (int i = 0; i < number_of_elements.size() - 1;i++)
			{


				check.push_back(inst);
				inst = inst + number_of_elements[i];


			}


			int size_all = all_elements.size() - 1;
			int size_check = check.size() - 1;

			for (int i = size_check; i >= 0;i--)
			{
				int tg = check[i];

				if (fff > all_elements[tg])
				{
					temp = all_elements[tg];
					all_elements[tg] = fff;

				}
				fff = temp;
			}

			int isize = number_of_elements.size();
			if (number_of_elements[sizeb] != 1)
			{
				isize--;
			}


			cout << endl;



			for (int i = 0;i < isize - 1; i++)
			{
				init_for_output += 1;
				size = number_of_elements[i] + size;
				for (int j = init_for_output; j < size;j++)
				{
					int all_elemenetsj = all_elements[j];
					cout << all_elements[j] << " ";
					init_for_output = j;
					buf.push_back(all_elemenetsj);
				}
				cout << endl;
			}
		}
		
	}
	
	for (int i = 0; i < buf.size(); i++)
	{
		all_elements[i] = buf[i];
	}
}
/*Бор.Вставка строки в бор.Удаление строки из бора.Поиск строки в
боре.*/


#include <iostream>
#include <string>
#include "Bor.cpp"

using namespace std;

int main()
{
	vertex* root = new vertex();
	while (true)
	{
		cout << "Use only ENGLISH" << endl;
		cout << "\t1 - Add WORD\n" << "\t2 - Erase WORD\n" << "\t3 - Find WORD\n" << "\t4 - Show Tree\n" << "\t5 - Exit\n";
		char type;
		cin >> type;
		if (type == '1')
		{
			string word;
			system("cls");
			cout << "Word to add (say no to probel)" << endl;
			cin >> word;
			add_string(word, root);
			system("cls");
		}
		else if (type == '2')
		{
			string word;
			system("cls");
			cout << "Word to erase" << endl;
			cin >> word;
			delete_string(word, root);
			system("cls");
		}
		else if (type == '3')
		{
			string word;
			system("cls");
			cout << "Find word" << endl;
			cin >> word;
			has_a_string(word, root) ? cout << "YES\n" : cout << "NO\n";
		}
		else if (type == '4')
		{
			system("cls");
			cout << "\n";
			clear_output();
			output_all_strings(root);
		}
		else if (type == '5')

			exit(0);
	}

	return 0;
}
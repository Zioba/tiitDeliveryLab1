#include "pch.h"
#include "Header.h"
#include <iostream>
#include <vector>
#include <iterator> 
#include <random>

using namespace std;

int main()
{
	int digit, L, R, element_nomer, Novoe_chislo, a;

	Fenv tree;

	cout << "Input dlinnu vectora" << endl;
	cin >> digit;

	tree.Vec.resize(digit);
	tree.Zer.resize(digit);

	for (int i = 0; i < digit; i++) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dist(0, 100);

		tree.Vec[i] = dist(gen);
		tree.Zer[i] = 0;
	}

	cout << "Your vector:       ";
	copy(tree.Vec.begin(), tree.Vec.end(), ostream_iterator<int>(cout, " "));

	for (int i = 0; i < tree.Vec.size(); i++)
		add(i, tree.Vec[i], tree);

	cout << "\nYour Fenvick tree: ";
	copy(tree.Zer.begin(), tree.Zer.end(), ostream_iterator<int>(cout, " "));

	while (true)
	{
		cout << "\nChoose:\n1.Sum\n2.Modify\n0.Exit" << endl;
		cin >> a;
		switch (a)
		{
		case 1: {
			cout << "\nVvedite otkuda: ";
			cin >> L;
			L = L - 1;

			cout << "Vvedite do kuda: ";
			cin >> R;
			R = R - 1;

			cout << "Result your sum is " << Sum(L, R, tree) << endl;
			break;
		}
		case 2: {
			cout << "Element pod kakim nomerom hotite izmenit'? ";
			cin >> element_nomer;
			int Z = element_nomer - 1;

			cout << "Vvedite na skolko hotite uvelichit'? ";
			cin >> Novoe_chislo;

			tree.Vec[Z] += Novoe_chislo;
			cout << "Your vector s izmeneniem:       ";
			copy(tree.Vec.begin(), tree.Vec.end(), ostream_iterator<int>(cout, " "));

			add(Z, Novoe_chislo, tree);

			cout << "\nYour Fenvick tree s izmeneniem: ";
			copy(tree.Zer.begin(), tree.Zer.end(), ostream_iterator<int>(cout, " "));
			break;
		}
		case 0: {
			exit(0);
		}
		}
	}
}
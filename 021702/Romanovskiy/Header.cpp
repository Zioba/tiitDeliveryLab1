#include "pch.h"
#include "Header.h"
#include <vector>
//#include <iostream>

using namespace std;

void add(int pos, int val, Fenv &tree)
{
	int n = tree.Vec.size();
	for (int i = pos; i < n; i = i | (i + 1)) {
		tree.Zer[i] += val;
	}
}

int Sum(int l, int r, Fenv &tree)
{
	int res = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
		//cout << "dobavlyaem " << tree.Zer[i] << endl;
		res += tree.Zer[i];
		//cout << "poluchaem " << res << endl;
	}

	for (int i = l-1; i >= 0; i = (i & (i + 1)) - 1) {
		//cout << "otnimayem " << tree.Zer[i] << endl;
		res -= tree.Zer[i];
		//cout << "poluchaem " << res << endl;
	}

	return res;
}
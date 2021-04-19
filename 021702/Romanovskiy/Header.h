#include <vector>

struct Fenv {

	std::vector<int> Vec;

	std::vector<int> Zer;
};

int Sum(int l, int r, Fenv &tree);


void add(int pos, int val, Fenv &tree);
#include"Bin_Tree.h"
#include<iostream>
#include<fstream>
#include <vector>
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	Bin_Tree tree1;
	int k;
	while (in >> k)
	{
		tree1.insert(k);
	}
	out << "Tree 1 inorder output: ";
	tree1.Inorder(out);
	out << "\n\n";

	out << "Delete 5: ";
	tree1.del(5);
	tree1.Inorder(out);
	out << "\n\n";

	out << "Delete 11: ";
	tree1.del(11);
	tree1.Inorder(out);
	out << "\n\n";

	Bin_Tree tree2;
	vector<int> arr = { 1,3,5,2,6,7,8,9,10 };
	tree2.array_tree(arr);

	out << "Tree 2 inorder output: ";
	tree2.Inorder(out);
	out << "\n\n";

	out << "Tree 2 postorder output: ";
	tree2.Postorder(out);
	out << "\n\n";

	out << "Tree 2 preorder output: ";
	tree2.Preorder(out);

	return 0;
}
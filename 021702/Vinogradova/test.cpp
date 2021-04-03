#include"BRTree.h"
#include<fstream>
#include<vector>

int main()
{
	BRTree tree;
	ifstream in("tests//input.txt");
	ifstream check("tests//check_input.txt");
	ofstream out("result.txt");
	int k;
	//TEST 1 - INPUT TREE
	vector<int> ans;
	while (in&&!in.eof())
	{
		in >> k;
		tree.insert(k);
	}
	while (!check.eof())
	{
		int k; check >> k;
		ans.push_back(k);
	}ans.pop_back();
	in.close(); check.close();
	vector<int> res;
	tree.Tree_to_Vector(res);
	if (res == ans)
		out << "Test 1 - Input - Ok\n";
	else out << "Test 1 - Input - Wrong answer\n";
	ans.resize(0);
	res.resize(0);
	//TEST 2 - ADD KEY
	in.open("tests//add.txt");
	check.open("tests//check_add.txt");
	in >> k; tree.insert(k);
	in >> k; tree.insert(k);
	while (!check.eof())
	{
		check >> k;
		ans.push_back(k);
	}ans.pop_back();
	in.close(); check.close();
	tree.Tree_to_Vector(res);
	if (res == ans)
		out << "Test 2 - Add - Ok\n";
	else out << "Test 2 - Add - Wrong answer\n";
	ans.resize(0);
	res.resize(0);
	//TEST 3 - SEARCH KEY
	in.open("tests//search.txt");
	check.open("tests//check_search.txt");
	in >> k; 
	if(tree.search(k))
		res.push_back(1);
	else 
		res.push_back(0);
	in >> k;
	if (tree.search(k))
		res.push_back(1);
	else
		res.push_back(0);
	in.close(); 
	check >> k; ans.push_back(k);
	check >> k; ans.push_back(k);
	check.close();
	if (res == ans)
		out << "Test 3 - Search - Ok\n";
	else out << "Test 3 - Search - Wrong answer\n";
	ans.resize(0);
	res.resize(0);

}
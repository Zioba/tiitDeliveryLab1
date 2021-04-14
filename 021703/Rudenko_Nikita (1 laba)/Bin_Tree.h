#include<fstream>
#include<vector>
using namespace std;
class Bin_Tree
{
private:
	struct Node *root;

	bool search(int key, Node* node);

	Node* List(int key);
	void inorder(Node*, ofstream&);
	void preorder(Node*, ofstream&);
	void postorder(Node*, ofstream&);
	void sort(vector<int>*);
	Node* array_tree(vector<int>, int, int);
public:
	Bin_Tree();
	void insert(int);
	void del(int);
	bool Search(int);
	void Inorder(ofstream&);
	void Preorder(ofstream&);
	void Postorder(ofstream&);
	void array_tree(vector<int>);
};


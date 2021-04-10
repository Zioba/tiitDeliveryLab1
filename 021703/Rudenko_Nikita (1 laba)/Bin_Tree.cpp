#include "Bin_Tree.h"
#include<iostream>
#include<fstream>
#include<vector>
#pragma once
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
};
	bool Bin_Tree::search(int key, Node* node)
	{
		if (node == NULL)return false;
		if (node->key == key)return true; 
		if (node->key > key)return search(key, node->left);
		if (node->key < key)return search(key, node->right);
	}

	Node* Bin_Tree::List(int key)
	{
		Node* tmp = new Node;
		tmp->key = key;
		tmp->right = NULL;
		tmp->left = NULL;
		return tmp;
	}
	void Bin_Tree::inorder(Node* node, ofstream& out)
	{
		if (node == NULL)return;
		inorder(node->left,out);
		out << node->key << ' ';
		inorder(node->right, out);
	}
	void Bin_Tree::preorder(Node* node, ofstream& out)
	{
		if (node == NULL)return;
		out << node->key << ' ';
		preorder(node->left, out);
		preorder(node->right, out);
	}
	void Bin_Tree::postorder(Node* node, ofstream& out)
	{
		if (node == NULL)return;
		postorder(node->left, out);
		postorder(node->right, out);
		out << node->key << ' ';
	}
	void Bin_Tree::sort(vector<int>* arr)
	{
		for (size_t i = 0; i < (*arr).size() - 1; i++)
		{
			for (size_t j = i + 1; j < (*arr).size(); j++)
			{
				if ((*arr)[i] > (*arr)[j])
				{
					int tmp = (*arr)[i];
					(*arr)[i] = (*arr)[j];
					(*arr)[j] = tmp;
				}
			}
		}
	}
	Node* Bin_Tree::array_tree(vector<int> arr, int l, int r)
	{
		if (l == r)
		{
			return NULL;
		}
		else
		{
			int mid =(l + r) / 2;
			int key = arr[mid];
			Node* tmp = new Node;
			tmp->key = key;
			tmp->left = array_tree(arr,l,mid);
			tmp->right = array_tree(arr,mid+1,r);
			return tmp;
		}
	}

	Bin_Tree::Bin_Tree()
	{
		root = NULL;
	}
	void Bin_Tree::insert(int key)
	{
		if (search(key, root))return;
		if (root == NULL)
		{
			root = List(key);
		}
		else
		{
			Node* tmp = root;
			Node* parent = tmp;
			while (tmp != NULL)
			{
				parent = tmp;
				if (tmp->key > key)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			tmp = List(key);
			if (key < parent->key)
				parent->left = tmp;
			else
				parent->right = tmp;
		}
	}
	void Bin_Tree::del(int key)
	{
		if (!search(key, root))return;
		Node* tmp, * par_tmp, * t, * par_t;
		tmp = root;
		par_tmp = NULL;

		while (tmp != NULL && tmp->key != key)
		{
			par_tmp = tmp;
			if (tmp->key > key) tmp = tmp->left;
			else tmp = tmp->right;
		}

		if (tmp->right == NULL)t = tmp->left; 
		else
			if (tmp->left == NULL)t = tmp->right;
			else
			{
				par_t = tmp;
				t = tmp->left;
				while (t->right != NULL)
				{
					par_t = t;
					t = t->right;
				}
				if (par_t == tmp)t->right = tmp->right;
				else
				{
					t->right = tmp->right;
					par_t->right = t->left;
					t->left = tmp->left;
				}
			}
		if (tmp == root)root = t;
		else
			if (tmp->key < par_tmp->key)
				par_tmp->left = t;
			else
				par_tmp->right = t;
		delete tmp;
	}
	bool Bin_Tree::Search(int key)
	{
		return search(key, root);
	}
	void Bin_Tree::Inorder(ofstream& out)
	{
		inorder(root,out);
	}
	void Bin_Tree::Preorder(ofstream& out)
	{
		preorder(root, out);
	}
	void Bin_Tree::Postorder(ofstream& out)
	{
		postorder(root, out);
	}
	void Bin_Tree::array_tree(vector<int> arr)
	{
		sort(&arr);
		for (size_t i = 1; i < arr.size(); i++)
		{
			if (arr[i] == arr[i - 1])return;
		}
		root = array_tree(arr, 0, arr.size());
	}


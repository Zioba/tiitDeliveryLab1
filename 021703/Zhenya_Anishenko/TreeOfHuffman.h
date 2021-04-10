#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <fstream>

using namespace std;

    class Node
    {
    public:
        int count;
        char symbol;
        Node* left;
        Node* right;

        Node() { }

        Node(char Symbol, int Count)
        {
            symbol = Symbol;
            count = Count;
        }

        Node(Node* l, Node* r)
        {
            symbol = 0;
            left = l;
            right = r;
            count = l->count + r->count;
        }
          void  Print_tree(Node* root, unsigned k = 0);
          
    };

    void BuildTable(Node* root, vector<bool>& code, map<char, vector<bool>>& table);
    bool SortNode(const Node* a, const Node* b);
    string Decode(string& str, map<vector<bool>, char>& table);
    


    


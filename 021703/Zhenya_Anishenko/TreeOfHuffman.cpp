#include "TreeOfHuffman.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <fstream>

using namespace std;

           
        

         void BuildTable(Node* root, vector<bool>& code, map<char, vector<bool>>& table)
        {
            if (root->left)
            {
                code.push_back(0);
                BuildTable(root->left, code, table);
            }

            if (root->right)
            {
                code.push_back(1);
                BuildTable(root->right, code, table);
            }

            if (root->symbol)
                table[root->symbol] = code;
            if (code.size())
                code.pop_back();
        }

         bool SortNode(const Node* a, const Node* b)
        {
            return a->count < b->count;

        }

        string Decode(string& str, map<vector<bool>, char>& table)
        {
            string out = "";
            vector<bool> code;
            for (int i = 0; i < str.length(); i++)
            {
                code.push_back(str[i] == '0' ? false : true);
                if (table[code])
                {
                    out += table[code];
                    code.clear();
                }
            }
            return out;
        }

        void Node::Print_tree(Node* root, unsigned k)
        {
            if (root != NULL) {
                Print_tree(root->left, k + 3);

                for (unsigned i = 0; i < k;i++) {
                    cout << "  ";
                }
                if (root->symbol) cout << root->count << "(" << root->symbol << ")" << endl;
                else cout << root->count << endl;
                Print_tree(root->right, k + 3);

            }
        }

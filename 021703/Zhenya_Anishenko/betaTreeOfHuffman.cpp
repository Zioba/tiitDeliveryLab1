
#include <iostream>
#include "TreeOfHuffman.h"
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
    int a = 0, c;

    fstream f;
    
    string raw;
   
    raw = argv[1];
    
    
    map<char, int> symbols;

    for (int i = 0; i < raw.length(); i++)
        symbols[raw[i]]++;

    list<Node*> trees;
    map<char, int>::iterator itr;
    for (itr = symbols.begin(); itr != symbols.end(); itr++)
    {
        Node* p = new Node(itr->first, itr->second);
        trees.push_back(p);
    }

    if (trees.size() == 0) {
        cout << "String is empty" << endl;

        f.open("Text0.txt", ios::out);
        f << '\n';
        f << "String is empty";
        f.close();
        
        system("pause");
        return 0;
    }
    else
    {
        if (trees.size() == 1)
        {
            Node* root = trees.front();
            
            cout << " - " << a << endl;
            cout << a << endl;
            f.open("Text1.txt", ios::out);
            f << '\n';
            f << "0";
            system("pause");
        }
        else
        {
            while (trees.size() != 1)

            {
                trees.sort(SortNode);

                Node* l = trees.front();
                trees.pop_front();
                Node* r = trees.front();
                trees.pop_front();

                Node* parent = new Node(l, r);
                trees.push_back(parent);
            }

            Node* root = trees.front();
            for (itr = symbols.begin();itr != symbols.end();itr++)
            {
                cout << itr->first << " : " << itr->second << endl;

            }
           
            root->Print_tree(root);
            vector<bool> code;
            map<char, vector<bool> > table;
            BuildTable(root, code, table);


            for (itr = symbols.begin(); itr != symbols.end(); itr++)
            {
                cout << itr->first << " - ";
                for (int j = 0; j < table[itr->first].size(); j++)
                    cout << table[itr->first][j];
                cout << endl;
            }

            string out = "";

            for (int i = 0; i < raw.length(); i++)
                for (int j = 0; j < table[raw[i]].size(); j++)
                {
                    out += table[raw[i]][j] + '0';
                   // cout << table[raw[i]][j];
                }
            cout << endl;
            cout << out.c_str() << endl;

            f.open("Text.txt", ios::out);
            f << '\n';
            f << out.c_str() << endl;
            f.close();

            map<vector<bool>, char> ftable;
            for (auto i = table.begin(); i != table.end(); i++)
                ftable[i->second] = i->first;
            cout << Decode(out, ftable).c_str() << endl;


            

            system("pause");
        }
    }
}


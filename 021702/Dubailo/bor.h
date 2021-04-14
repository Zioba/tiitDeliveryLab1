#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
//====================================

struct node {
    node *next[26];
    int strings;
    int child;
    node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        strings = 0;
    }
    
};

//=================================
void add(const string& s);
bool has(const string& s);
void write(node *v = root);
void delit(const string& s);

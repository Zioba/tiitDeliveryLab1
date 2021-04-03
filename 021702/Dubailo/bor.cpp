#include "bor.h"
node *root = new node();    //корневая вершина бора, соответствующая пустой строке.

void add(const string& s) {
    node *cur_v = root;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (cur_v->next[c - 'a'] == nullptr) {
            cur_v->next[c - 'a'] = new node();
            cur_v->child++;
        }

        cur_v = cur_v->next[c - 'a'];
    }

    cur_v->strings++;
}
//===================================
bool has(const string& s) {
    node *cur_v = root;

    for (int i = 0; i < s.length(); i++) {
        cur_v = cur_v->next[s[i] - 'a'];
        if (cur_v == nullptr) {
            return false;
        }
    }
    cout <<"Сктрока есть"<<endl;
    return cur_v->strings > 0;
}
//===============================
string cur_str = "";

void write(node *v = root) {
    for (int i = 0; i < v->strings; i++) {
        cout << cur_str << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (v->next[i] != nullptr) {
            cur_str.push_back('a' + i);
            write(v->next[i]);
            cur_str.pop_back();
        }
    }
    
}
//================================
void delit(const string& s){
    node *cur_v = root;
    node *temp= new node();
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        temp=cur_v;
        cur_v=cur_v->next[c-'a'];
    }
    if(cur_v->child==0)
    {
        delete cur_v;
        temp->next[s[s.length()-1]-'a']=NULL;
    }
    if(cur_v->child>0)
    {
        cur_v->strings=0;
    }
}

    

//==================================


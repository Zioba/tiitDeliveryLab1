#pragma once

struct node;

unsigned char height(node* p);

int bfactor(node* p);

void fixheight(node* p);

node* rotateright(node* p);

node* rotateleft(node* q);

node* balance(node* p);

node* insert(node* p, int k);

node* findmin(node* p);

node* removemin(node* p);

node* remove(node* p, int k);

int SearchMin(node* aBranch);

int SearchMax(node* aBranch);

bool Search(int aData, node* aBranch);

void print(node* aBranch);

void pr_obh_bol(node* aBranch, int n, int* k, bool flag);

void blig_bol(node* aBranch, int n, int* k, bool flag);

void pr_obh_men(node* aBranch, int n, int* k, bool flag);

void blig_men(node* aBranch, int n, int* k, bool flag);




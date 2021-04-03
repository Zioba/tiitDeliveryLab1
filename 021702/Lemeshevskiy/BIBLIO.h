#ifndef _BIBLIO_H_
#define _BIBLIO_H_
#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> buildSuffixArray(string txt, int n);
string minLexRotation(string str);
vector<int> kasai(string txt, vector<int> suffixArr);
#endif;

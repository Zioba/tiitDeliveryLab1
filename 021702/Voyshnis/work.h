#pragma once

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void Output(vector <int> &number_of_elements, vector <int> &all_elements, int size, int init_for_output);
void Add_e(vector <int> &number_of_elements, vector <int> &all_elements, int current);
void Delete(vector <int> &all_elements, vector <int> &number_of_elements, vector <int> check, int s, int t);
void Test(int current, int s, int t, vector <int> &added, vector <int> &deleted);
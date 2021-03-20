#pragma once
#include <iostream>
using namespace std;
struct deque
{
	int dt;
	int val[20];
};
deque push_front(deque d, int x);
deque push_back(deque d, int x);
int pop_front(deque* d);
int pop_back(deque* value);
bool compare(deque d1, deque d2);
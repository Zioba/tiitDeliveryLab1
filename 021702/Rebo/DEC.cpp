
#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
#include "../Project16/DEC.h"
using namespace std;



deque push_front(deque d, int x)
{
	if (d.dt == 20) return d;
	for (int curr = d.dt++ - 1; curr >= 0; curr--)
	{
		d.val[curr + 1] = d.val[curr];
	}
	d.val[0] = x;
	return d;
}
deque push_back(deque d, int x)
{
	if (d.dt == 20) return d;
	d.val[(d.dt++)] = x;
	return d;
}
int pop_front(deque* d)
{
	if (d->dt == 0) return 0;
	int temp = d->val[0];
	for (int curr = 0; curr < d->dt; curr++)
	{
		d->val[curr] = d->val[curr + 1];
	}
	d->dt--;
	return temp;
}
int pop_back(deque* value)
{
	if (value->dt == 0) return 0;
	return value->val[(value->dt--)];
}
bool compare(deque d1, deque d2)
{
	if (d1.dt != d2.dt) return false;
	int i = 0;
	while (i < d1.dt)
	{
		if (d1.val[i] != d2.val[i]) return false;
		i++;
	}
	return true;
}

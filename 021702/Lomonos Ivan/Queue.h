#pragma once
class Queue
{
private:
	struct Node* begin, * end;
public:
	Queue();
	void push(int key);
	int pop();
};


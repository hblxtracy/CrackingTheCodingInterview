#pragma once
#include<stack>
using namespace std;

class QueueViaStacks
{
public:
	QueueViaStacks();
	~QueueViaStacks();

	void Enqueue(int data);
	int Dequeue();
	int Peek();
	int Size();
private:
	stack<int> stackOne;
	stack<int> stackTwo;
};


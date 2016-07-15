#include"stdafx.h"
#include"QueueViaStacks.h"
#include<stack>
#include <iostream>
using namespace std;
QueueViaStacks::QueueViaStacks()
{	
}

QueueViaStacks::~QueueViaStacks()
{
}

void QueueViaStacks::Enqueue(int data)
{
	stackOne.push(data);
}

int QueueViaStacks::Dequeue()
{
	if(stackOne.empty()&&stackTwo.empty())
		throw new exception("Queue is empty!\n");

	int value;
	if (stackTwo.empty())
	{
		while (!stackOne.empty())
		{
			stackTwo.push(stackOne.top());
			stackOne.pop();
		}

	}
	value = stackTwo.top();
	stackTwo.pop();
	return value;
}

int QueueViaStacks::Peek()
{
	if (stackOne.empty() && stackTwo.empty())	
		throw new exception("Queue is empty!\n");

	if (stackTwo.empty())
	{
		while (!stackOne.empty())
		{
			stackTwo.push(stackOne.top());
			stackOne.pop();
		}

	}
	return stackTwo.top();
}

int QueueViaStacks::Size()
{
	return (stackOne.size() + stackTwo.size());
}
#include"stdafx.h"
#include "StackMin.h"
#include <iostream>
using namespace std;

StackMin::StackMin()
{
	top = NULL;	
}

StackMin::~StackMin()
{
	while (top != NULL)
	{
		Node* temp = top;
		top = top->previous;
		delete temp;
	}
}

void StackMin::Push(int data)
{
		Node* temp = new Node;
		temp->data = data;

		if (top != NULL)
		{
			if (data < top->currentMin)
				temp->currentMin = data;
			else
				temp->currentMin = top->currentMin;
		}
		else
			temp->currentMin = data;

		temp->previous = top;
		top = temp;
}

int StackMin::Pop()
{
	if (top == NULL)
		throw new exception("Stack is empty!/n");
	int value;
	Node* temp = new Node;
	temp = top;
	top = top->previous;
	value = temp->data;
	delete temp;
	return value;
}

int StackMin::Min()
{
	if (top == NULL)
		throw new exception("Stack is empty!/n");
	return top->currentMin;
}

int StackMin::Peek()
{
	if (top == NULL)
		throw new exception("Stack is empty!\n");
	return top->data;
}

bool StackMin::IsEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

void StackMin::Print()
{
	if (top == NULL)
		throw new exception("Stack is empty!\n");
	cout << "Print Stack: ";
	Node* temp = new Node;
	temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->previous;
	}
	delete temp;
	cout << "\n";
}
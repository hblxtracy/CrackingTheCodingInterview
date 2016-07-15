#pragma once
using namespace std;

class StackMin
{
public:
	StackMin();
	~StackMin();
	void Push(int data);
	int Pop();
	int Peek();
	bool IsEmpty();
	void Print();
	int Min();

private:
	struct Node
	{ 
		int data;
		Node* previous;
		int currentMin;
	};
	
	Node* top;

};

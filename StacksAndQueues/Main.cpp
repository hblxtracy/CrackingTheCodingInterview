// StacksAndQueues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "StackMin.h"
#include "QueueViaStacks.h"
using namespace std;

//3.1 Three in One: Describe how you could use a single array to implement three stacks.
//Hints: #2, #72, #38, #58 

//3.3 Stack of Plates : Imagine a(literal) stack of plates.If the stack gets too high, it might topple.
//Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
//threshold.Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
//composed of several stacks and should create a new stack once the previous one exceeds capacity.
//SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
//(that is, pop() should return the same values as it would if there were just a single stack).
//FOLLOW UP
//Implement a function popAt(int index) which performs a pop operation on a specific sub - stack.
//Hints:#64, #87



//3.5 Sort Stack : Write a program to sort a stack such that the smallest items are on the top.You can use
//an additional temporary stack, but you may not copy the elements into any other data structure
//(such as an array).The stack supports the following operations : push, pop, peek, and is Empty.
//Hints : # 15, #32, #43

//3.6 Animal Shelter : An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first 
//out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, 
//or they can select whether they would prefer a dog or a cat(and will receive the oldest animal of
//that type).They cannot select which specific animal they would like.Create the data structures to
//maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
//and dequeueCat.You may use the built - in Linked list data structure.
//Hints : #22, #56, #63



int main()
{
	//3.2 Stack Min: How would you design a stack which, in addition to push and pop, has a function min 
	//which returns the minimum element ? Push, pop and min should all operate in O(1) time.
	//Hints : #27, #59, #78

	StackMin MyMinStack;
	cout << MyMinStack.IsEmpty() << endl;

	MyMinStack.Push(25);
	cout << MyMinStack.IsEmpty() << endl;

	MyMinStack.Push(30);
	MyMinStack.Push(15);
	MyMinStack.Push(5);

	MyMinStack.Print();
	cout << "Peek: " << MyMinStack.Peek() << endl;
	cout << "Current Minimum: " << MyMinStack.Min() << endl;
	cout << "Pop: " << MyMinStack.Pop() << endl;
	cout << "Current Minimum: " << MyMinStack.Min() << endl;
	cout << "Pop: " << MyMinStack.Pop() << endl;
	cout << "Current Minimum: " << MyMinStack.Min() << endl;
	cout << "Peek: " << MyMinStack.Peek() << endl;
	MyMinStack.Print();

	//3.4 Queue via Stacks : Implement a MyQueue class which implements a queue using two stacks.
	//Hints : #98, #114
	QueueViaStacks MyQueue;
	//MyQueue.Enqueue(15);
	//MyQueue.Enqueue(20);
	//MyQueue.Enqueue(25);
	cout << "Size of my QViaStacks: " << MyQueue.Size() << endl;
	cout << "Peek my QViaStacks: " << MyQueue.Peek()<<endl;
	MyQueue.Dequeue();
	cout << "Dequeue and Peek: " << MyQueue.Peek() << endl;
	cout << "Size of my QViaStacks: " << MyQueue.Size() << endl;

	getchar();

	return 0;
}


#include "stdafx.h"
#include "TowerOfHanoi.h"
#include<stack>
#include<iostream>

TowerOfHanoi::TowerOfHanoi(int disckNum)
{
	for (int i = disckNum; i >0; i--)
		stackA.push(i);
	moveCount = 0;
	diskNumTOH = disckNum;
}


TowerOfHanoi::~TowerOfHanoi()
{
}


int TowerOfHanoi::SolveTOH()
{
	if(diskNumTOH&1)//odd number of disks
	{ 
		while(1)
		{
			Move(stackA, stackC);
			if (moveDir)
				cout << "Step " << moveCount << ": Moved " << stackC.top() << " from Rod A to C.\n";
			else																				
				cout << "Step " << moveCount << ": Moved " << stackA.top() << " from Rod C to A.\n";
			if (stackA.empty() && stackB.empty())
				break;

			Move(stackA, stackB);																
			if (moveDir)																		
				cout << "Step " << moveCount << ": Moved " << stackB.top() << " from Rod A to B.\n";
			else																				
				cout << "Step " << moveCount << ": Moved " << stackA.top() << " from Rod B to A.\n";
			if (stackA.empty() && stackB.empty())
				break;

			Move(stackB, stackC);																
			if (moveDir)																		
				cout << "Step " << moveCount << ": Moved " << stackC.top() << " from Rod B to C.\n";
			else																				
				cout << "Step " << moveCount << ": Moved " << stackB.top() << " from Rod C to B.\n";
			if (stackA.empty() && stackB.empty())
				break;
		}		
	}
	else  //even number of disks
	{
		while (1)
		{
			Move(stackA, stackB);
			if (moveDir)
				cout << "Step " << moveCount << ": Moved " << stackB.top() << " from Rod A to B.\n";
			else
				cout << "Step " << moveCount << ": Moved " << stackA.top() << " from Rod B to A.\n";
			if (stackA.empty() && stackB.empty())
				break;

			Move(stackA, stackC);
			if (moveDir)
				cout << "Step " << moveCount << ": Moved " << stackC.top() << " from Rod A to C.\n";
			else
				cout << "Step " << moveCount << ": Moved " << stackA.top() << " from Rod C to A.\n";
			if (stackA.empty() && stackB.empty())
				break;

			Move(stackB, stackC);	
			if (moveDir)
				cout << "Step " << moveCount << ": Moved " << stackC.top() << " from Rod B to C.\n";
			else
				cout << "Step " << moveCount << ": Moved " << stackB.top() << " from Rod C to B.\n";
			if (stackA.empty() && stackB.empty())
				break;
		}
	}
	return moveCount;
}

void TowerOfHanoi::Move(stack<int> &stackOne, stack<int> &stackTwo)
{
	if (stackOne.empty() && stackTwo.empty())
		return;

	if((!stackOne.empty()&&!stackTwo.empty()&&stackOne.top()<stackTwo.top())||(stackTwo.empty()))
	{ 
		int temp = stackOne.top();
		stackTwo.push(temp);
		stackOne.pop();		
		moveCount++;
		moveDir = true;
		return;
	}
	else if((!stackOne.empty() && !stackTwo.empty() && stackOne.top()>stackTwo.top()) || (stackOne.empty()))
	{	
		int temp = stackTwo.top();
		stackOne.push(temp);
		stackTwo.pop();
		moveCount++;	
		moveDir = false;
		return;
	}
	return;
}

#pragma once
#include<stack>
using namespace std;

class TowerOfHanoi
{
public:
	TowerOfHanoi(int disckNum);
	~TowerOfHanoi();
	
	int SolveTOH();
	void Move(stack<int> &stackOne, stack<int> &stackTwo);

private:
	stack<int> stackA;
	stack<int> stackB;
	stack<int> stackC;
	int moveCount;
	bool moveDir;
	int diskNumTOH;
};



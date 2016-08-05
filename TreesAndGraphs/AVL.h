#pragma once
#include"BST.h"
class AVL:private BST
{
private:
	struct AVLNode:Node
	{
		int height;
	};
public:
	AVL();
	~AVL();
	using BST::ClearTree;
	int Height(AVLNode* &t);
	void Insert(AVLNode* &t, int key);
};


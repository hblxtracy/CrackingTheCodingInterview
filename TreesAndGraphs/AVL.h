#pragma once
#include"BST.h"
class AVL
{
private:
	struct Node
	{
		int key;
		Node* left = NULL;
		Node* right = NULL;
		int height;
	};
public:
	Node* root;
	AVL();
	~AVL();
	void ClearTree(Node* t);
	int CalHeight(Node* &t);
	void Insert(Node* &t, int key);
	Node* Delete(Node* &t, int key);
	void InOrderTreeWalk(Node* t);
	void Rebalance(Node* &t);
	void RightRotation(Node* &t);
	void LeftRotation(Node* &t);
	Node* Maximum(Node* t);
	Node* Minimum(Node* t);
};


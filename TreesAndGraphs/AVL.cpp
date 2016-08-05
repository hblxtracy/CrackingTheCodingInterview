#include "stdafx.h"
#include "AVL.h" 
#include <algorithm>
#include <iostream>

using namespace std;

AVL::AVL()
{
}


AVL::~AVL()
{
	ClearTree(root);
}

void AVL::ClearTree(Node* t)
{
	if (t == NULL)
		return;
	if (t->left != NULL)
		ClearTree(t->left);
	if (t->right != NULL)
		ClearTree(t->right);
	delete t;
	return;
}

int AVL::CalHeight(Node* &t )
{
	
	if (t == NULL)
		return -1;
	int l_height = (t->left == NULL) ? -1 : t->left->height;
	int r_height = (t->right == NULL) ? -1 : t->right->height;
	return max(l_height,r_height)+1;
}

void AVL::Insert(Node* &t, int key)
{
	if (t == NULL)
	{
		Node* n = new Node;
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		n->height = 0;
		t = n;
		return;
	}

	if (key < t->key || key == t->key)
	{
		Insert(t->left, key);
		t->height = CalHeight(t);
		int balance = CalHeight(t->left) - CalHeight(t->right);
		if (balance > 1 || balance < -1)
			Rebalance(t);
	}		
	else
	{
		Insert(t->right, key);
		t->height = CalHeight(t);
		int balance = CalHeight(t->left) - CalHeight(t->right);
		if (balance > 1 || balance < -1)
			Rebalance(t);
	}		
}

void AVL::InOrderTreeWalk(Node* t)
{
	if (t == NULL)
		return;
	InOrderTreeWalk(t->left);
	cout << t->key << "-"<<t->height<<" ";
	InOrderTreeWalk(t->right);
}

void AVL::Rebalance(Node *& t)
{
}

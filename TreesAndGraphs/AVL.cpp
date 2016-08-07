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

int AVL::CalHeight(Node* &t)
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
		n->height = CalHeight(n);
		t = n;
		return;
	}

	if (key < t->key || key == t->key)
	{
		Insert(t->left, key);
		//t->left->parent = t;
		t->height = CalHeight(t);
		int balance = CalHeight(t->left) - CalHeight(t->right);
		if (balance > 1 || balance < -1)
			Rebalance(t);
	}		
	else
	{
		Insert(t->right, key);
		//t->right->parent = t;
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
	if (CalHeight(t->left)>CalHeight(t->right))   //left heavy
	{
		if(CalHeight(t->left->left)>CalHeight(t->left->right))  //LL
		{ 
			RightRotation(t);
		}
		else if(CalHeight(t->left->left)<CalHeight(t->left->right)) //LR
		{
			LeftRotation(t->left);
			RightRotation(t);
		}
	}
	else if(CalHeight(t->left)<CalHeight(t->right))  //right heavy
	{ 
		if (CalHeight(t->right->left)<CalHeight(t->right->right))  //RR
		{
			LeftRotation(t);
		}
		else if (CalHeight(t->right->left)>CalHeight(t->right->right)) //LR
		{
			RightRotation(t->right);
			LeftRotation(t);
		}
	}
	return;
}

void AVL::RightRotation(Node *& t)
{
	Node* pivot = t->left;	
	t->left = pivot->right;
	t->height = CalHeight(t);
	pivot->right = t;
	pivot->height = CalHeight(pivot);
	t = pivot;
}

void AVL::LeftRotation(Node *& t)
{
	Node* pivot = t->right;	
	t->right = pivot->left;
	t->height = CalHeight(t);
	pivot->left = t;
	pivot->height = CalHeight(pivot);
	t = pivot;
}

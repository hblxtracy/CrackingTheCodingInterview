#include "stdafx.h"
#include "RB.h"
#include <iostream>

using namespace std;

RB::RB()
{
}


RB::~RB()
{
}

void RB::ClearTree(Node* t)
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

bool RB::IsRed(Node* t)
{
	if (t == NULL)
		return false;
	return t->red;
}

void RB::ChangeColor(Node* &t)
{
	if (IsRed(t))
		t->red = false;
	else
		t->red = true;
}

RB::Node* RB::U(Node* &t)
{
	if (t->parent == NULL)
	{
		cout << "Node does not have parent.";
		return NULL;
	}
	if (t->parent->parent == NULL)
	{
		cout << "Node does not have grandparent.";
		return NULL;
	}
	if (t->parent == t->parent->parent->left)
		return t->parent->parent->right;
	else
		return t->parent->parent->left;
}

RB::Node* RB::S(Node* &t)
{
	if (t->parent == NULL)
	{
		cout << "Node does not have parent.";
			return NULL;
	}
	if (t = t->parent->left)
		return t->parent->right;
	else
		return t->parent->left;
}

RB::Node* RB::G(Node* &t)
{
	if (t->parent == NULL)
	{
		cout << "Node does not have parent.";
		return NULL;
	}
	if (t->parent->parent == NULL)
	{
		cout << "Node does not have grandparent.";
		return NULL;
	}
	return t->parent->parent;
}

RB::Node* RB::P(Node* const &t)
{
	return t->parent;
}

void RB::RightRotation(Node* &t)
{
	Node* p = t->parent;    
	Node* pivot = t->left;

	t->left = pivot->right;
	if (t->left!=NULL)
	t->left->parent = t;

	pivot->right = t;
	t->parent = pivot;

	pivot->parent = p;
	t = pivot;
	return;
}

void RB::LeftRotation(Node* &t)
{
	Node* p = t->parent;
	Node* pivot = t->right;

	t->right = pivot->left;
	if (t->right != NULL)
		t->right->parent = t;

	pivot->left = t;
	t->parent = pivot;

	pivot->parent = p;
	t = pivot;
	return;
}


void RB::Insert(Node* &t, int key)
{
	if (t == NULL)
	{
		t->key = key;
		t->left = NULL;
		t->right = NULL;
		if (t == root)
			t->red = false;
		else
			t->red = true;
		return;
	}

	if (key < t->key)
		Insert(t->left, key);
	else if (key>t->key)
		Insert(t->right, key);
	else
	{
		cout << key << " is found, cannot insert!/n";
		return;
	}

	if (t->left != NULL)
	{
		t->left->parent = t;
		if (t->red)
			InsertFix(t->left);
	}
		
	if (t->right != NULL)
	{ 	
		t->right->parent = t;
		if (t->red)
			InsertFix(t->left);
	}
		

}

void RB::InsertFix(Node* &t)
{
	if(U(t)->red) //if uncle is red, change color of p, u and g.
	{ 
		Node* p = P(t);
		Node* u = U(t);
		Node* g = G(t);
		ChangeColor(p);
		ChangeColor(u);
		ChangeColor(g);
	}
	else
	{





	}

	if (root != NULL&root->red)
		ChangeColor(root);
}
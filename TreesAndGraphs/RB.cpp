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

RB::Node* RB::P(Node* &t)
{
	return t->parent;
}

void RB::InOrderTreeWalk(Node* t)
{
	if (t == NULL)
		return;
	InOrderTreeWalk(t->left);
	cout << boolalpha;
	cout << t->key << "-" << t->red << " ";
	InOrderTreeWalk(t->right);
}


void RB::RightRotation(Node* &t)
{
	Node* p = t->parent;    
	Node* pivot = t->left;
	if (t == root)
		root = pivot;
	else if (t == p->left)
		p->left = pivot;
	else
		p->right = pivot;
	pivot->parent = p;

	t->left = pivot->right;
	if (t->left!=NULL)
	t->left->parent = t;

	pivot->right = t;
	t->parent = pivot;
	t = pivot;
	return;
}

void RB::LeftRotation(Node* &t)
{
	Node* p = t->parent;
	Node* pivot = t->right;
	if (t == root)
		root = pivot;
	else if (t == p->left)
		p->left = pivot;
	else
		p->right = pivot;
	pivot->parent = p;

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
		Node* n = new Node;;
		n->key = key;
		n->left = NULL;
		n->right = NULL;

		if (t == root)
			n->red = false;
		else
			n->red = true;
		t = n;
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
			InsertFix(t->right);
	}
}

void RB::InsertFix(Node* &t)
{
	bool tmp;
	if (t == root||!t->red)
		return;
	else
	{

		Node* p = P(t);
		Node* u = U(t);
		Node* g = G(t);
		if (IsRed(u)) //if uncle is red, change color of p, u and g.
		{
			ChangeColor(p);
			ChangeColor(u);
			if (g != root)
				ChangeColor(g);
		}
		else
		{

			if (t == p->right && p == g->right)  //RR
			{
				LeftRotation(g);
				tmp = IsRed(g);
				g->red = g->left->red;
				g->left->red = tmp;
			}
			else if (t == p->left && p == g->right)  //RL
			{
				RightRotation(p);
				LeftRotation(g);
				tmp = IsRed(g);
				g->red = g->left->red;
				g->left->red = tmp;
			}
			else if (t == p->left && p == g->left) //LL
			{
				RightRotation(g);
				tmp = IsRed(g);
				g->red = g->right->red;
				g->right->red = tmp;

			}
			else                                 //LR
			{
				LeftRotation(p);
				RightRotation(g);
				tmp = IsRed(g);
				g->red = g->right->red;
				g->right->red = tmp;
			}
		}

		if (root != NULL&&root->red)
			ChangeColor(root);
		if (g->red)
		InsertFix(g->child);
	}
}
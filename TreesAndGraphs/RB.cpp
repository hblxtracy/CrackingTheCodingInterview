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
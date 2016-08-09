#include "stdafx.h"
#include "RB.h"


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
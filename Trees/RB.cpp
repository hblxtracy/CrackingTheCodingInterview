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

RB::Node* RB::Maximum(Node* t)
{
	if (t == NULL)
	{
		//cout << "Tree is empty./n";
		return t;
	}

	while (t->right != NULL)
	{
		t = t->right;
	}
	//cout << "Maximum is: " << t->key << endl;
	return t;
}

RB::Node* RB::Minimum(Node* t)
{
	if (t == NULL)
	{
		//cout << "Tree is empty./n";
		return t;
	}

	while (t->left != NULL)
	{
		t = t->left;
	}
	//cout << "Minimum is: " << t->key << endl;
	return t;
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


void RB::Insert(Node* &t,Node* &p, int key)
{
	if (t == NULL)
	{
		Node* n = new Node;;
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		n->parent = p;

		if (t == root)
		{
			n->parent = NULL;
			n->red = false;
		}
			
		else
			n->red = true;
		t = n;

		if (p != NULL&&p->red)
			InsertFix(t);
		return;
	}

	if (key < t->key)
		Insert(t->left,t, key);
	else if (key>t->key)
		Insert(t->right,t, key);
	else
	{
		cout << key << " is found, cannot insert!/n";
		return;
	}
}

void RB::InsertFix(Node* &t)
{
	bool tmp;
	if (t == root || !t->parent->red)
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
			InsertFix(g);
	}
}

void RB::DoubleBlackFix(Node* &x)
{
	Node* p = P(x);
	Node* w = S(x);
	if (x == root)
		x->red = false;
	//x's sibling w is red.
	else if (x != root && IsRed(w))  
	{
		DBF_case1(x);      	
	}
	//x's sibling w is black and both w's children are black.
	else if (x != root && !IsRed(w) && !IsRed(w->left) && !IsRed(w->right))
	{
		DBF_case2(x);
	}
	else if (x != root && !IsRed(w) && (IsRed(w->left) || IsRed(w->right)))
	{
		if ((x == p->left&&!IsRed(w->right)) || (x == p->right&&!IsRed(w->left)))
		{
			DBF_case3(x);
		}
		else
		{
			DBF_case4(x);
		}
	}
	return;
}

//x's sibling w is red.
void RB::DBF_case1(Node* &x)
{
	Node* w = S(x);
	ChangeColor(w);
	ChangeColor(x->parent);
	if (x == x->parent->left)
		LeftRotation(x->parent);
	else
		RightRotation(x->parent);
	DoubleBlackFix(x);
	return;
}

//x's sibling w is black and both w's children are black.
void RB::DBF_case2(Node* &x)
{
	Node* w = S(x);
	bool org_color_p = x->parent->red;
	x->red = false;
	w->red = true;
	x->parent->red = false;
	if (!org_color_p)
	{
		//Now x' parent is double black.
		DoubleBlackFix(x->parent);
	}
	return;
}

void RB::DBF_case3(Node* &x)
{
	Node* w = S(x);
	if (x == x->parent->left && IsRed(w->left))
	{
		ChangeColor(w);
		ChangeColor(w->left);
		RightRotation(w);
	}
	else
	{
		ChangeColor(w);
		ChangeColor(w->right);
		LeftRotation(w);
	}
	DoubleBlackFix(x);
	return;
}

void RB::DBF_case4(Node* &x)
{
	Node* w = S(x);
	Node* p = P(x);
	bool tmp = p->red;
	p->red = w->red;
	w->red = tmp;
	if (x = x->parent->left)
	{
		LeftRotation(p);
	}
	else
	{
		RightRotation(p);
	}
	return;
}


RB::Node* RB::Delete(Node* &t, int key)
{

	if (t == NULL)
	{
		cout << "Key is not found./n";
		return t;
	}

	if (key < t->key)
		Delete(t->left, key);
	else if (key > t->key)
		Delete(t->right, key);
	//key is found, do deletion.
	else                    
	{
		//Case A: both t's children are NULL.
		if (t->left == NULL&&t->right == NULL)
		{
			bool color_t = t->red;
			bool isRoot = (t == root) ? true : false;
			Node* p = t->parent;
			delete t;
			t = NULL;
			//t is red node or t is root node, delete it without doing anything.
			if (color_t || isRoot)
			{
				//do nothing.
			}
			else                              
			{			
				//t is black and not root, p(t) is red => change p(t) to black and delete t.
				if (p->red)           
				{
					ChangeColor(p);
				}
				//double black deletion.
				else                          
				{
					DoubleBlackFix(p);
				}
			}			


		}
		//Case B1: one of t's child is NULL.
		else if (t->left != NULL&&t->right == NULL)
		{
			bool color_t = t->red;
			bool color_d = t->left->red;
			Node* temp = t;
			t = t->left;
			t->parent = temp->parent;
			delete temp;
			temp = NULL;


			if (color_t)
			{ 			
				//do nothing.
			}
			else if (!color_t&&color_d)
			{ 
				ChangeColor(t);
			}
			else if (!color_t&&!color_d)
			{
				DoubleBlackFix(t);
			}

		}
		//Case B2: one of t's child is NULL.
		else if (t->left == NULL&&t->right != NULL)
		{
			bool color_t = t->red;
			bool color_d = t->right->red;
			Node* temp = t;
			t = t->right;
			t->parent = temp->parent;
			delete temp;
			temp = NULL;

			if (t->red)
			{
				//do nothing.
			}
			else if (!color_t&&color_d)
			{
				ChangeColor(t);
			}
			else if (!color_t&&!color_d)
			{
				DoubleBlackFix(t);
			}
		}
		//Case C: both t's children are not NULL.
		else
		{
			Node* n = Minimum(t->right);
			t->key = n->key;
			Delete(t->right, n->key);
		}
		return t;
	}
}

#include "stdafx.h"
#include "AVL.h" 
#include <algorithm>
#include <iostream>
#include <stack>

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

AVL::Node* AVL::Delete(Node* &t, int key)
{

	if (t == NULL)
	{
		cout << "Key is not found./n";
		return t;
	}
	int balance;
	if (key < t->key)
	{	
		Delete(t->left, key);
		t->height = CalHeight(t);
		balance = CalHeight(t->left) - CalHeight(t->right);
		if (balance > 1 || balance < -1)
			Rebalance(t);
	}		
	else if (key > t->key)
	{
		Delete(t->right, key);
		t->height = CalHeight(t);
		balance = CalHeight(t->left) - CalHeight(t->right);
		if (balance > 1 || balance < -1)
			Rebalance(t);
	}		
	else
	{
		if (t->left == NULL&&t->right == NULL)
		{
			delete t;
			t = NULL;
		}
		else if (t->left != NULL&&t->right == NULL)
		{
			Node* temp = t;
			t = t->left;
			delete temp;
			temp = NULL;
			t->height = CalHeight(t);
		}
		else if (t->left == NULL&&t->right != NULL)
		{
			Node* temp = t;
			t = t->right;
			delete temp;
			temp = NULL;
			t->height = CalHeight(t);
		}
		else
		{
			stack<Node*> trace;
			Node* n = t->right;
			trace.push(t);
			while (n->left != NULL)
			{
				trace.push(n);
				n = n->left;				
			}
			t->key = n->key;
			Delete(t->right, n->key);

			Node* tmp;
			while (!trace.empty())
			{
				tmp = trace.top();
				trace.pop();
				tmp->height = CalHeight(tmp);
				balance = CalHeight(tmp->left) - CalHeight(tmp->right);
				if (balance > 1 || balance < -1)
					Rebalance(tmp);
			}
		}

		return t;
	}
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

	if (key < t->key)
	{
		Insert(t->left, key);
	}		
	else if (key>t->key)
	{
		Insert(t->right, key);
	}		
	else
	{
		cout << key << " is found, cannot insert!/n";
		return;
	}
	t->height = CalHeight(t);
	int balance = CalHeight(t->left) - CalHeight(t->right);
	if (balance > 1 || balance < -1)
		Rebalance(t);
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
		if(CalHeight(t->left->left)<CalHeight(t->left->right)) //LR
		{
			LeftRotation(t->left);
			RightRotation(t);
		}
		else                                                    //LL
		{
			RightRotation(t);
		}
	}
	else if(CalHeight(t->left)<CalHeight(t->right))  //right heavy
	{ 
		if (CalHeight(t->right->left)>CalHeight(t->right->right)) //RL
		{
			RightRotation(t->right);
			LeftRotation(t);
		}
		else                                                     //RR
		{
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
	if (t == root)
		root = pivot;
	t = pivot;
	return;
}

void AVL::LeftRotation(Node *& t)
{
	Node* pivot = t->right;	
	t->right = pivot->left;
	t->height = CalHeight(t);
	pivot->left = t;
	pivot->height = CalHeight(pivot);
	if (t == root)
		root = pivot;
	t = pivot;
	return;
}


AVL::Node* AVL::Maximum(Node* t)
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

AVL::Node* AVL::Minimum(Node* t)
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



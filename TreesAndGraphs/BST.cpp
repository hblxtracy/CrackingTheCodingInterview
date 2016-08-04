#include "stdafx.h"
#include "BST.h"
#include <iostream>

using namespace std;

BST::BST()
{
	root = NULL;
}


BST::~BST()
{
	ClearTree(root);
}

void BST::ClearTree(Node* t)
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

void BST::Insert(Node* &t, int newKey)
{
	if (t==NULL)
	{
		Node* n = new Node;
		n->key = newKey;
		n->left = NULL;
		n->right = NULL;
		t = n;
		return;
	}

	if (newKey < t->key || newKey == t->key)
		Insert(t->left, newKey);
	else
		Insert(t->right, newKey);	
}

BST::Node* BST::Delete(Node* &t, int key)
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
		}
		else if (t->left == NULL&&t->right != NULL)
		{
			Node* temp = t;
			t = t->right;
			delete temp;
			temp = NULL;
		}
		else
		{
			Node* n = Minimum(t->right);
			t->key = n->key;
			Delete(t->right, n->key);
		}
		return t;
	}	
}

void BST::InOrderTreeWalk(Node* t)
{
	if (t == NULL)
		return;
	InOrderTreeWalk(t->left);	
	cout <<t->key << " ";
	InOrderTreeWalk(t->right);
}

void BST::PostOrderTreeWalk(Node* t)
{
	if (t == NULL)
		return;
	PostOrderTreeWalk(t->left);	
	PostOrderTreeWalk(t->right);
	cout << t->key << " ";
}

void BST::PreOrderTreeWalk(Node* t)
{
	if (t == NULL)
		return;
	cout << t->key << " ";
	PostOrderTreeWalk(t->left);
	PostOrderTreeWalk(t->right);
}

BST::Node* BST::Search(Node* t, int key)
{
	if (t == NULL)
	{

		cout << key << " is not found!\n";
		return t;
	}

	if (t->key > key)
		return Search(t->left, key);
	if (t->key < key)
		return	Search(t->right, key);
	if (t->key == key)
	{
		cout << key << " is found!\n";
		return t;
	}

}

BST::Node* BST::Maximum(Node* t)
{
	if (t == NULL)
	{
		cout << "Tree is empty./n";
		return t;
	}

	while (t->right!=NULL)
	{
		t = t->right;
	}
	cout << "Maximum is: " << t->key << endl;
	return t;
}

BST::Node* BST::Minimum(Node* t)
{
	if (t == NULL)
	{
		cout << "Tree is empty./n";
		return t;
	}
		
	while (t->left != NULL)
	{
		t = t->left;
	}
	cout << "Minimum is: " << t->key << endl;
	return t;
}

BST::Node* BST::SearchParent(Node* t, int key)
{
	if (t == NULL)
	{
		cout << "Tree is empty.\n";
		return t;
	}
	if (t->key > key) //go to left subtree.
	{
		if (t->left == NULL)
		{
			cout << key << " is not found!\n";
			return t;
		}
		if (t->left->key == key)
		{
			cout << "The parent of " << key << " is " << t->key << ".\n";
			return t;
		}
		return SearchParent(t->left, key);
	}
	else
	{
		if (t->right == NULL)
		{
			cout << key << " is not found!/n";
			return t;
		}
		if (t->right->key == key)
		{
			cout <<"The parent of " << key <<" is "<<t->key<< ".\n";
			return t;
		}
		return SearchParent(t->right, key);
	}


}




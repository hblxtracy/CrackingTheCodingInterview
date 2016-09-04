#pragma once
class BST
{	
private:
	struct Node
	{
		int key;
		Node* left;
		Node* right;
	};
	

public:
	Node* root;
	BST();
	~BST();
	void ClearTree(Node* t);
	void Insert(Node* &t, int key);
	Node* Delete(Node* &t, int key);
	void InOrderTreeWalk(Node* t);
	void PostOrderTreeWalk(Node* t);
	void PreOrderTreeWalk(Node* t);
	Node* Search(Node* t, int key);
	Node* Maximum(Node* t);
	Node* Minimum(Node* t);
	Node* SearchParent(Node* t, int key);

	
};


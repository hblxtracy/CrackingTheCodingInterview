#pragma once
class RB
{
	struct Node
	{
		int key;
		Node* left = NULL;
		Node* right = NULL;
		Node* parent = NULL;
		bool red;
	};

	
		
public:
	Node* root;

	RB();
	~RB();
	void ClearTree(Node* t);
	void Insert(Node* &t, Node* &p, int key);
	void InsertFix(Node* &t);
	void RightRotation(Node* &t);
	void LeftRotation(Node* &t);
	bool IsRed(Node *t);
	void ChangeColor(Node* &t);
	void InOrderTreeWalk(Node* t);
	Node* U(Node* &t);
	Node* S(Node* &t);
	Node* G(Node* &t);
	Node* P(Node* &t);
	
};


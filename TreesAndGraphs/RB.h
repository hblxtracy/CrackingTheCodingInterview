#pragma once
class RB
{
private:
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
	void Insert(Node* &t, int key);
	void RightRotation(Node* &t);
	void LeftRotation(Node* &t);
	bool IsRed(Node *t);
	void ChangeColor(Node* &t);
	Node* U(Node* &t);
	Node* S(Node* &t);
	Node* G(Node* &t);
	Node* P(Node* &t);
};


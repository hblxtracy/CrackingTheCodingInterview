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
};


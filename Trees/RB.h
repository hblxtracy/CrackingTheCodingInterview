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
	Node* U(Node* &t);
	Node* S(Node* &t);
	Node* G(Node* &t);
	Node* P(Node* &t);
	void RightRotation(Node* &t);
	void LeftRotation(Node* &t);
	void InsertFix(Node* &t);
	void ChangeColor(Node* &t);
	void DoubleBlackFix(Node* &t);
	void DBF_case1(Node* &t);
	void DBF_case2(Node* &t);
	void DBF_case3(Node* &t);
	void DBF_case4(Node* &t);
public:
	Node* root;
	RB();
	~RB();
	void ClearTree(Node* t);
	void Insert(Node* &t, Node* &p, int key);
	Node* Delete(Node* &t, int key);
	Node* Maximum(Node* t);
	Node* Minimum(Node* t);
	bool IsRed(Node *t);
	void InOrderTreeWalk(Node* t);

	
};


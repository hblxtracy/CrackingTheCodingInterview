// TreesAndGraphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include "AVL.h"
#include "RB.h"
#include "MaxHeap.h"
#include <iostream>
using namespace std;

void PrintArray(int* A, int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
	return;
}

struct TreeNode
{
	int key;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* MinTreeInsert(int arr[], int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	TreeNode* n = new TreeNode;
	n->key = arr[mid];
	n->left = MinTreeInsert(arr, start, mid-1);
	n->right = MinTreeInsert(arr, mid+1, end);
	return n;
}

void CopyBST(TreeNode* node, int* &arr, int arrSize, int i)
{
	if (node == NULL)
		return;
	CopyBST(node->left, arr, arrSize, i);
	if (i < arrSize)
	{
		arr[i] = node->key;
		i++;
	}
	else
		return;
	CopyBST(node->right, arr, arrSize, i);
}

bool ValidateBST(TreeNode* node, int lastValue)
{
	if (node == NULL)
		return true;
	if (!ValidateBST(node->left, lastValue))
		return false;
	if (node->key < lastValue || node->key == lastValue)
		return false;
	lastValue = node->key;
	if (!ValidateBST(node->right, lastValue))
		return false;


	return true;
}

int FirstCommonAncestor(TreeNode* node, int value1, int value2)
{
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Binary Search Tree
	int bstArraySize = 11;		
	int bstArray[] = { 15, 6, 18, 3, 7, 17, 20, 2, 13, 4, 9 };
	cout << "BST Input Array: " ;
	PrintArray(bstArray, bstArraySize);

	BST myBST;
	for (int i = 0; i < bstArraySize; i++)
		myBST.Insert(myBST.root, bstArray[i]);

	cout << "InOrderTreeWalk: ";
	myBST.InOrderTreeWalk(myBST.root);
	cout << endl;

	cout << "PreOrderTreeWalk: ";
	myBST.PreOrderTreeWalk(myBST.root);
	cout << endl;

	cout << "PostOrderTreeWalk: ";
	myBST.PostOrderTreeWalk(myBST.root);
	cout << endl;

	myBST.Search(myBST.root, 100);
	myBST.Search(myBST.root, 20);
	myBST.Maximum(myBST.root);
	myBST.Minimum(myBST.root);
	myBST.SearchParent(myBST.root, 9);

	cout << "Delete Node 15: ";
	myBST.Delete(myBST.root, 15);	
	myBST.InOrderTreeWalk(myBST.root);
	cout << endl;
	cout << endl;

	//Max Heap
	int table[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1, 0, 0, 0, 0};
	int heapSize = 10;
	int* maxHeapArray = new int[15];

	for (int i = 0; i < heapSize; i++)
		*(maxHeapArray + i) = table[i];
	cout << "Max-Heap: ";
	PrintArray(maxHeapArray, heapSize);
	MaxHeap myMaxHeap;
	myMaxHeap.MaxHeapify(maxHeapArray, heapSize, 1);
	cout << "Max-Heapified 1: ";
	PrintArray(maxHeapArray, heapSize);

	for (int i = 0; i < heapSize; i++)
		*(maxHeapArray + i) = table[i];
	cout << "Max-Heap: ";
	PrintArray(maxHeapArray, heapSize);
	myMaxHeap.BuildHeap(maxHeapArray, heapSize);
	cout << "BuildHeap: ";
	PrintArray(maxHeapArray, heapSize);
	cout << "HeapExtractMax: " << myMaxHeap.HeapExtractMax(maxHeapArray, heapSize) << endl;
	cout << "Remaining: ";		
	PrintArray(maxHeapArray, heapSize - 1);
	cout << "HeapInsert 32: \n";
	myMaxHeap.HeapInsert(maxHeapArray, heapSize - 1, 32);
	cout << "New Heap: ";
	PrintArray(maxHeapArray, heapSize);

	for (int i = 0; i < heapSize; i++)
		*(maxHeapArray + i) = table[i];
	cout << "Max-Heap: ";
	PrintArray(maxHeapArray, heapSize);
	myMaxHeap.HeapSort(maxHeapArray, heapSize);
	cout << "HeapSort: ";
	PrintArray(maxHeapArray, heapSize);
	cout << endl;

	//AVL tree
	int avlArraySize =11;
	//int avlArray[] = { 15, 6, 18, 3, 7, 17, 20, 2, 13, 4, 9 };
	int avlArray[] = { 30, 50, 40, 60, 70, 17, 20, 2, 13, 4, 9 };
	cout << "AVL Input Array: ";
	PrintArray(avlArray, avlArraySize);
	AVL myAVL;
	for (int i = 0; i < avlArraySize; i++)
	{
		myAVL.Insert(myAVL.root, avlArray[i]);
		myAVL.InOrderTreeWalk(myAVL.root);
		cout << endl;
	}

	cout << "Delete 30: \n";
	myAVL.Delete(myAVL.root, 30);
	myAVL.InOrderTreeWalk(myAVL.root);
	cout << endl;

	cout << "Delete 13: \n";
	myAVL.Delete(myAVL.root, 13);
	myAVL.InOrderTreeWalk(myAVL.root);
	cout << endl;

	cout << "Delete 20: \n";
	myAVL.Delete(myAVL.root, 20);
	myAVL.InOrderTreeWalk(myAVL.root);
	cout << endl;

	//RB tree
	int rbArraySize = 11;
	//int rbArray[] = { 1, 3, 2, 4, 5, 6, 8, 7, 9, 10, 11 };
	int rbArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	cout << "RB Input Array: ";
	PrintArray(rbArray, rbArraySize);

	RB myRB;
	for (int i = 0; i < rbArraySize; i++)
	{
		myRB.Insert(myRB.root, myRB.root, rbArray[i]);
		myRB.InOrderTreeWalk(myRB.root);
		cout << endl;
	}

	RB myRB2;
	myRB2.Insert(myRB2.root, myRB2.root, 50);
	myRB2.Insert(myRB2.root, myRB2.root, 20);
	myRB2.Insert(myRB2.root, myRB2.root, 30);
	myRB2.Insert(myRB2.root, myRB2.root, 40);
	myRB2.Insert(myRB2.root, myRB2.root, 45);
	myRB2.Insert(myRB2.root, myRB2.root, 43);
	myRB2.Insert(myRB2.root, myRB2.root, 44);
	myRB2.Insert(myRB2.root, myRB2.root, 42);
	myRB2.InOrderTreeWalk(myRB2.root);
	cout << endl;
	myRB2.Delete(myRB2.root, 50);
	myRB2.InOrderTreeWalk(myRB2.root);
	cout << endl;




	//4.2 Minimal Tree : Given a sorted(increasing order) array with unique integer elements, write an
	//	algorithm to create a binary search tree with minimal height.
	int minTree[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	TreeNode* n = MinTreeInsert(minTree, 0, 9);

	//4.5 Validate BST: Implement a function to  check if a  binary tree is a binary  search  tree.
	int* valArray = new int[10];
	CopyBST(n, valArray, 10, 0);
	for (int i = 0; i < 10; i++)
		cout << i << " ";
	cout << endl;

	cout << ValidateBST(n, -1000000)<<endl;

	//4.8 First Common Ancestor: Design an algorithm and write code to find the first common ancestor 
	// of two nodes in a binary tree.Avoid storing additional nodes in a data structure.NOTE: This is not
	//necessarily a binary search tree.

	int binaryTree[] = { 3, 5, 2, 6, 9, 7, 1, 4, 8, 10};
	TreeNode* bt = MinTreeInsert(binaryTree, 0, 9);



	//4.9 BST Sequences : A binary search tree was created by traversing through an array from left to right
	//	and inserting each element.Given a binary search tree with distinct elements, print all possible
	//	arrays that could have led to this tree.
	

	//4.1O Check Subtree : Tl and T2 are two very large binary trees, with Tl much bigger than T2.Create an
	//	algorithm to determine ifT2 is a subtree of Tl.
	//	A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2.
	//	That is, if you cut off the tree at node n, the two trees would be identical.


	//4.11 Random Node : You are implementing a binary search tree class from scratch, which, in addition
	//	to insert, find, and delete, has a method getRandomNode() which returns a random node
	//	from the tree.All nodes should be equally likely to be chosen.Design and implement an algorithm
	//	for getRandomNode, and explain how you would implement the rest of the methods.


	getchar();

	return 0;
}


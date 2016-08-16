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
	getchar();



	//4.2 Minimal Tree : Given a sorted(increasing order) array with unique integer elements, write an
	//	algorithm to create a binary search tree with minimal height.
	int minTree[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	return 0;
}


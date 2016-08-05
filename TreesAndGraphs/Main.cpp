// TreesAndGraphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include "AVL.h"
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
	cout << "Input Array:     " ;
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
	AVL myAVL;
	//for (int i = 0; i < bstArraySize; i++)
	//myAVL.Insert(myBST.root, bstArray[i]);

	getchar();
	return 0;
}


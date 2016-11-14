// SortingAndSearching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include <iostream>
using namespace std;

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 8;

	int a[n] = { 24, 13, 9, 64, 7, 23, 34, 47 };

	int* A = new int[n];
	memcpy(A, a, sizeof(int)*n);
	cout << "Original Array: " << endl;
	PrintArray(A, n);
	InsertionSort is;
	is.InsertionSortFun(A, n);
	cout << "Sorted Array (InsertionSort): " << endl;
	PrintArray(A, n);
	delete[] A;


	int* B = new int[n];
	memcpy(B, a, sizeof(int)*n);
	cout << "Original Array: " << endl;
	PrintArray(B, n);
	SelectionSort ss;
	ss.SelectionSortFun(B, n);
	cout << "Sorted Array (SelectionSort): " << endl;
	PrintArray(B, n);
	delete[] B;



	int* C = new int[n];
	memcpy(C, a, sizeof(int)*n);
	cout << "Original Array: " << endl;
	PrintArray(C, n);
	BubbleSort bs;
	bs.BubbleSortFun(C, n);
	cout << "Sorted Array (BubbleSort): " << endl;
	PrintArray(C, n);
	delete[] C;

	int* D = new int[n];
	memcpy(D, a, sizeof(int)*n);
	cout << "Original Array: " << endl;
	PrintArray(D, n);
	MergeSort ms;
	ms.MergeSortFun(D, 0, n - 1);
	cout << "Sorted Array (MergeSort): " << endl;
	PrintArray(D, n);
	delete[] D;

	cin.get();
	return 0;
}


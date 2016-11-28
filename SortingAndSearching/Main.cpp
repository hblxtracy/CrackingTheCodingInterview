// SortingAndSearching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <iostream>
#include <vector>
using namespace std;

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int* SortedMerge(int* a, int* b, int la, int lb)
{
	int* p_a = a + la - 1;
	int* p_b = b + lb - 1;
	int* p_e = a + la + lb - 1;
	while (p_a >= a || p_b >= b)
	{
		if (*p_a > *p_b)
		{
			*p_e = *p_a;
			p_e--;
			p_a--;
		}
		else
		{
			*p_e = *p_b;
			p_e--;
			p_b--;
		}
	
	}

	return a;
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


	int* E = new int[n];
	memcpy(E, a, sizeof(int)*n);
	cout << "Original Array: " << endl;
	PrintArray(E, n);
	QuickSort qs;
	qs.QuickSortFun(E, 0, n - 1);
	cout << "Sorted Array (QuickSort): " << endl;
	PrintArray(E, n);
	delete[] E;


	//10.1 Sorted Merge : You are given two sorted arrays, A and B, where A has a large enough buffer at the
	//	end to hold B.Write a method to merge B into A in sorted order.

	int arr_a[] = { 1, 3, 5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int arr_b[] = { 2, 4, 6, 8 };
	int la = 4;
	int lb = 4;
	cout << "10.1: Array A: " << endl;
	PrintArray(arr_a, la);
	cout << "Array B: " << endl;
	PrintArray(arr_b, lb);
	cout << "Sorted Array: " << endl;
	SortedMerge(arr_a, arr_b, la, lb);
	PrintArray(arr_a, la + lb);

	//10.2 Group Anagrams : Write a method to sort an array of strings so that all the anagrams are next to
	//	each other.
	vector<string> vos = { "cat", "dog", "tac", "god", "act" };

	cin.get();
	return 0;
}


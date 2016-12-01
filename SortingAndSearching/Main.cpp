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

int BinarySearch(int *a, int begin, int end, int value)
{
	if (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (value == a[mid])
			return mid;
		else if (value > a[mid])
			return BinarySearch(a, mid + 1, end, value);
		else if (value < a[mid])
			return BinarySearch(a, begin, mid - 1, value);
	}
	else
		return -1;
}

int SearchRotatedArray(int* a, int begin, int end, int value)
{
	int mid = (begin + end) / 2;
	if (value == a[mid])
		return mid;
	if (begin > end)
		return -1;

	if (a[begin] < a[mid])
	{
		if (value<a[mid])
			return SearchRotatedArray(a, begin, mid - 1, value);
		else
			return SearchRotatedArray(a, mid + 1, end, value);

	}
	else if (a[begin]>a[mid])
	{
		if (value > a[mid])
			return SearchRotatedArray(a, mid + 1, end, value);
		else
			return SearchRotatedArray(a, begin, mid - 1, value);
	}
	else if (a[begin] == a[mid])
	{
		if (a[mid] != a[end])
		{
			return SearchRotatedArray(a, mid + 1, end, value);
		}
		else
		{
			int result = SearchRotatedArray(a, begin, mid - 1, value);
			if (result == -1)
				result = SearchRotatedArray(a, mid + 1, end, value);
			return result;
		}
	}
}

int SparseSearch(string* a, int begin, int end, string s)
{
	if (a == NULL || s == "" || begin > end)
		return -1;

	int mid = (begin + end) / 2;
	if (a[mid] == "")
	{
		int left = mid - 1;
		int right = mid + 1;
		while (1)
		{
			if (left<begin && right>end)
				return -1;
			else if (left>=begin && a[left]!="")
			{
				mid = left;
				break;
			}
			else if (right <= end && a[right] != "")
			{
				mid = right;
				break;
			}
			left--;
			right++;
		}

	}

	if (strcmp(s.c_str(), a[mid].c_str()) == 0)
		return mid;
	else if (strcmp(s.c_str(), a[mid].c_str()) < 0)
		return SparseSearch(a, begin, mid, s);
	else
		return SparseSearch(a, mid, end, s);
		
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

	//10.3 Search in Rotated Array : Given a sorted array of n integers that has been rotated an unknown number of times, 
	//write code to find an element in the array.You may assume that the array was originally sorted in increasing order.
	//EXAMPLE lnput : find5in{ 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 } Output: 8 (the index of 5 in the array)	
	//int sortedArr[] = { 1, 3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25 };
	//int result = BinarySearch(sortedArr, 0, 11, 5);
	int rotatedArr[] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	cout << "Rotated Array: " << endl;
	PrintArray(rotatedArr, 11);
	int result3 = SearchRotatedArray(rotatedArr, 0, 11, 5);
	cout << "Search for 5: " <<result3<< endl;

	//10.4 Sorted Search, No Size : You are given an array - like data structure Listy which lacks a size method.
	//It does, however, have an elementAt(i) method that returns the element at index i in 0(1) time.
	//If i is beyond the bounds of the data structure, it returns - 1. (For this reason, the data structure only supports positive integers.) 
	//Given a Listy which contains sorted, positive integers, find the index at which an element x occurs.
	//If x occurs multiple times, you may return any index.pg 150


	//10.5 Sparse Search : Given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string.
	//EXAMPLE Input : ball, { "at", "", "","", "ball","","", "car", "" , "" , "dad", "",""} Output: 4
	string aos[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };
	
	int result5 = SparseSearch(aos, 0, 12, "ball");
	cout << "10.5: Search for \"ball\": " << result5 << endl;

	
	//10.8 Find Duplicates : You have an array with all the numbers from 1 to N, where N is at most 32, 000. 
	//The array may have duplicate entries and you do not know what N is.
	//With only 4 kilobytes of memory available, how would you print all duplicate elements in the array ? pg 151



	cin.get();
	return 0;
}


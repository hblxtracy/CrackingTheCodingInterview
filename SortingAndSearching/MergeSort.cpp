#include "stdafx.h"
#include "MergeSort.h"
#include <algorithm>
using namespace std;

MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::MergeSortFun(int* a, int l, int r)
{
	if (l < r)   
	{
		int m = l + (r - l) / 2;
		MergeSortFun(a, l, m);
		MergeSortFun(a, m + 1, r);
		Merge(a, l, m, r);
	}
	return;
}

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void MergeSort::Merge(int* a, int l, int m, int r)
{
	
	int* b = new int[m-l+1];
	for (int p = l; p <= m; p++)
		b[p - l] = a[p];
	int* c = new int[r - m];
	for (int p = m + 1; p <= r; p++)
		c[p - m - 1] = a[p];
	int bi = 0, ci = 0, ai = l;
	while (bi < m - l + 1 && ci < r - m)
	{
		if (b[bi]<c[ci])
		{
			a[ai] = b[bi];
			bi++;
		}
		else
		{
			a[ai] = c[ci];
			ci++;
		}	
		ai++;
	}

	while (bi < m - l + 1)
	{	
		a[ai] = b[bi];
		bi++;
		ai++;
	}

	while (ci<r - m)
	{
		a[ai] = c[ci];
		ci++;
		ai++;
	}	
	delete[] b;
	delete[] c;
}

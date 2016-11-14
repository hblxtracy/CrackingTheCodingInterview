#include "stdafx.h"
#include "QuickSort.h"
#include <algorithm>
using namespace std;


QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}

void QuickSort::QuickSortFun(int* a, int l, int r)
{
	if (l < r)     
	{
		// pi is partitioning index, arr[p] is now  at right place
		int pi = Partition(a, l, r);

		// Separately sort elements before / partition and after partition
		QuickSortFun(a, l, pi - 1);
		QuickSortFun(a, pi + 1, r);
	}
	return;
}

int QuickSort::Partition(int* a, int l, int r)
{
	int pivot_value = a[r];
	int pIndex = l;
	for (int i = l; i < r; i++)
	{
		if (a[i]<=pivot_value)
		{
			swap(a[pIndex], a[i]);
			pIndex++;
		}
	
	}
	swap(a[r], a[pIndex]);

	return pIndex;
}
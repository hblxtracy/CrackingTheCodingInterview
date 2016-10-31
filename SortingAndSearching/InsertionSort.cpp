#include "stdafx.h"
#include "InsertionSort.h"


InsertionSort::InsertionSort()
{
}


InsertionSort::~InsertionSort()
{
}

void InsertionSort::InsertionSortFun(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		//compare a[j] with a[j-1] to a[0] and instert it.
		int j = i;
		int temp;
		while (j>0 && a[j]<a[j - 1])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}
}

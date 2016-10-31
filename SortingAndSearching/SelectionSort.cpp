#include "stdafx.h"
#include "SelectionSort.h"


SelectionSort::SelectionSort()
{
}


SelectionSort::~SelectionSort()
{
}

void SelectionSort::SelectionSortFun(int* a, int n)
{
	int localMin;
	int temp;

	for (int i = 0; i < n - 1; i++)
	{
		localMin = a[i];

		//swap min(a[i+1] to a[n-1]) with a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}
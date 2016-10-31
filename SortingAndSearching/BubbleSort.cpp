#include "stdafx.h"
#include "BubbleSort.h"


BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}


void BubbleSort::BubbleSortFun(int* a, int n)
{

	int temp;
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}

}
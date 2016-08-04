#include "stdafx.h"
#include "MaxHeap.h"


MaxHeap::MaxHeap()
{
}


MaxHeap::~MaxHeap()
{
}

int MaxHeap::Parent(int i)
{
	return (i-1)/2;
}

int MaxHeap::Left(int i)
{
	return 2*i+1;
}

int MaxHeap::Right(int i)
{
	return 2*i+2;
}

void MaxHeap::MaxHeapify(int * A, int n, int i)
{
	int l = Left(i);
	int r = Right(i);
	int max = i;
	if (l<n&&A[l]>A[max])
		max = l;
	if (r<n&&A[r]>A[max])
		max = r;
	if (max == i)
		return;
	int tmp = A[i];
	A[i] = A[max];
	A[max] = tmp;
	MaxHeapify(A, n, max);
}

void MaxHeap::BuildHeap(int* A, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(A, n, i);
	}
	return;
}
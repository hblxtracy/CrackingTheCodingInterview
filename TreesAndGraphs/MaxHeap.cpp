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
	return i/2;
}

int MaxHeap::Left(int i)
{
	return 2*i;
}

int MaxHeap::Right(int i)
{
	return 2*i+1;
}

void MaxHeap::MaxHeapify(int * A, int heapSize, int i)
{

}

#pragma once
class MaxHeap
{
private:

public:
	MaxHeap();
	~MaxHeap();
	int Parent(int i);
	int Left(int i);
	int Right(int i);
	void MaxHeapify(int* A, int heapSize, int i);
};


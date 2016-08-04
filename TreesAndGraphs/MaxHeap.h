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
	void MaxHeapify(int* A, int arrayLength, int i);
	void BuildHeap(int* A, int arrayLength);
	void HeapSort(int* A, int arrayLength);
};


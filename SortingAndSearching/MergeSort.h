#pragma once
class MergeSort
{
public:
	MergeSort();
	~MergeSort();
	void MergeSortFun(int* a, int l, int r);
	void Merge(int* a, int l, int m, int r);
};


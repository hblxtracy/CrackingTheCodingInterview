#pragma once
class QuickSort
{
public:
	QuickSort();
	~QuickSort();
	void QuickSortFun(int* a, int l, int r);
	int Partition(int* a, int l, int r);
};


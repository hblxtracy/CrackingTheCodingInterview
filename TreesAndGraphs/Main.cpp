// TreesAndGraphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int inputArray[] = { 15, 6, 18, 3, 7, 17, 20, 2, 13, 4, 9};
	cout << "Input Array:     " ;
	BST myBST;
	for (int i = 0; i < 11; i++)
	{ 
		cout << inputArray[i] << " ";
		myBST.Insert(myBST.root, inputArray[i]);
	}		
	cout << endl;

	cout << "InOrderTreeWalk: ";
	myBST.InOrderTreeWalk(myBST.root);
	cout << endl;

	cout << "PreOrderTreeWalk: ";
	myBST.PreOrderTreeWalk(myBST.root);
	cout << endl;

	cout << "PostOrderTreeWalk: ";
	myBST.PostOrderTreeWalk(myBST.root);
	cout << endl;

	myBST.Search(myBST.root, 100);
	myBST.Search(myBST.root, 20);
	myBST.Maximum(myBST.root);
	myBST.Minimum(myBST.root);
	myBST.SearchParent(myBST.root, 9);


	cout << "Delete Node 15: ";
	myBST.Delete(myBST.root, 15);	
	myBST.InOrderTreeWalk(myBST.root);

	getchar();
	return 0;
}


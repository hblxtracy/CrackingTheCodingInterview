// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int Fibonacci(int n)
{
	if (n < 0)
		return -1;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int TripleStep(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return TripleStep(1) + TripleStep(2) + 1;
	if (n > 3)
		return TripleStep(n - 1) + TripleStep(n - 2) + TripleStep(n - 3);
}

void RobotInGrid(string str, int r, int c)
{
	if (r < 0 || c < 0)
		return;
	if (r == 0 && c == 0)
		cout << str << endl;
	else
	{
		str.append("-");
		RobotInGrid(str, r - 1, c);

		str.erase(str.end() - 1);

		str.append("|");
		RobotInGrid(str, r, c - 1);
	}
}

void Parens(string str, int leftRem, int rightRem)
{
	if (leftRem > rightRem || leftRem < 0)
		return;


	if (leftRem == 0 && rightRem == 0)
	{
		cout << str << endl;
	}
	else
	{
		str.append("(");
		Parens(str, leftRem - 1, rightRem);
		str.erase(str.end() - 1);

		str.append(")");
		Parens(str, leftRem, rightRem - 1);
	}

}


vector<string> PowerSet(string set, int n)
{
	vector<string> allsubsets;
	if (n == 1)
	{
		allsubsets.push_back(set);
		return allsubsets;
	}
	else
	{
		string sc = string(1, set.at(0));
		set.erase(set.begin());
		allsubsets = PowerSet(set, n - 1);		
		int psize = allsubsets.size();
		for (int i = 0; i < psize; i++)
		{
			allsubsets.push_back(allsubsets[i] + sc);
		}
		allsubsets.push_back(sc);
		return allsubsets;
	}
}


int MagicIndex(int* a, int begin, int end)
{
	if ((end-begin)<2)
		return -1;
	else
	{ 
		int mid = (begin + end) / 2;
		if (a[mid] > mid)
		{
			end = mid;
			MagicIndex(a, begin, end);
		}
		else if (a[mid] < mid)
		{
			begin = mid;
			MagicIndex(a, begin, end);
		}
		else
		{
			return mid;
		}
	}
}

void Permute(char*a, int begin, int end)
{
	if (begin == end)
	{
		cout << a<<endl;
	}
	else
	{
		for (int j = begin; j <= end; j++)
		{
			swap(a[begin], a[j]);
			Permute(a, begin + 1, end);
			swap(a[begin], a[j]);
		}
	}	
}




void PermuteWithDups(char*a, int begin, int end)
{
	if (begin == end)
	{
		cout << a << endl;
	}
	else
	{
		bool dupe[256] = { false };
		for (int j = begin; j <= end; j++)
		{ 

			if (!dupe[a[j]])
			{
				dupe[a[j]] = true;
				swap(a[begin], a[j]);
				PermuteWithDups(a, begin + 1, end);
				swap(a[begin], a[j]);
			}	
		}
	}
}


//8.5 Recursive Multiply : Write a recursive function to multiply two positive integers without using the
//*operator.You can use addition, subtraction, and bit shifting, but you should minimize the number
//of those operations.
//Hints : #166, #203, #227, #234, #246, #280

//8.6 Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.
//That is, given a screen(represented by a two - dimensional array of colors), a point, and a new color,
//fill in the surrounding area until the color changes from the original color.

//8.7 Coins: Given an infinite number of quarters(25 cents), dimes(10 cents), nickels(5 cents) and pennies(1 cent), 
//write code to calculate the number of ways of representing n cents.
int MakeChange(int n)
{
	if (n < 5)
		return 1;
	if (n == 5)
		return 2;
}

	
//8.8 Eight Queens: Write an algorithm to print all ways of arranging eight queens on a chess board 
//so that none of them share the same row, column or diagonal.

//8.13 Stack of Boxes : You have a stack of n boxes, with widths wi, heights hi, and depths di.The boxes
//cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly
//larger than the box above it in width, height, and depth.Implement a method to compute the
//height of the tallest possible stack.The height of a stack is the sum of the heights of each box.
//Hints : #755, #194, #274, #260, #322, #368, #378
		
//8.14 Boolean Evaluation : Given a boolean expression consisting of the symbols 0 (false), 1 (true), &
//(AND), I(OR), and / \ (XOR), and a desired boolean result value result, implement a function to
//count the number of ways of parenthesizing the expression such that it evaluates to result.
//EXAMPLE
//countEval("l /\01011", false) -> 2
//countEval("0&0&0&1/\ ll0", true) -> 10
//Hints: #748, #168, #197, #305, #327

int _tmain(int argc, _TCHAR* argv[])
{
	//8.1 Write a method to generate the nth Fibonacci number.
	cout << "Fibonacci: ";
	for (int i = 1; i < 15; i++)
	{
		cout << Fibonacci(i) << " ";
	}
	cout << "\n" ;

	//8.1Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
	//steps at a time.Implement a method to count how many possible ways the child can run up the
	//stairs.
	//Hints: #152, #178, #217, #237, #262, #359
	cout << "Triple Step(10): " << TripleStep(10) << endl;

	//8.4 Permutations without Dups: Write a method to compute all permutations of a string of unique
	//characters.
	cout << "Permutations without Dups: ABCD" << endl;
	char a[] = "ABCD";
	string str = "ABCD";
	Permute(a, 0, 3);

	//8.8 Permutations with Dups: Write a method to compute all permutations of a string whose characters
	//are not necessarily unique.The list of permutations should not have duplicates.
	//Hints:#761, #790, #222, #255
	cout << "Permutations with Dups: ABBC" << endl;
	char b[] = "ABBC";
	PermuteWithDups(b, 0, 3);


	//8.3 Power Set: Write a method that returns all subsets of a set.
	cout << "Power Set: ABCD" << endl;
	string ps_input = "ABCD";
	vector<string> ps_result = PowerSet(ps_input, 4);
	for (int i = 0; i < ps_result.size(); i++)
	{
		cout << ps_result.at(i) << " ";
	}
	cout << endl;

	//8.5 Parens: Implement an algorithm to print all valid(e.g., properly opened and closed) 
	//combinations of n - pairs of parentheses.
	//EXAMPLE:
	//input : 3 (e.g., 3 pairs of parentheses)
	//output : ()()(), ()(()), (())(), ((()))
	cout << "Parens: 3" << endl;
	string paraens_str = "";
	Parens(paraens_str, 3, 3);

	//8.2 Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns. 
	//The robot can only move in two directions, right and down, but certain cells are "off limits" such that
	//the robot cannot step on them.Design an algorithm to find a path for the robot from the top left to
	//the bottom right.
	cout << "Robot in a Grid: Row-2, Col-3" << endl;
	string rg_str = "";
	RobotInGrid(rg_str, 2, 3);

	//8.3 Magic Index: A magic index in an array A [ 0...n -1] is defined to be an index such that A[i] = i.
	//Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
	//array A.
	//FOLLOW UP
	//What if the values are not distinct ?
	//Hints : #770, #204, #240, #286, #340
	cout << "MagicIndex: " <<endl;
	int mi_input1[] = {-8, -5, 1, 2, 4, 8, 9, 13, 15, 35};
	int mi_resut1 = MagicIndex(mi_input1, 0, 9);
	cout << "resut1: " << mi_resut1 << endl;
	int mi_input2[] = { -28, -15, -11, -3, 2, 3, 6, 8, 11, 12, 15};
	int mi_resut2 = MagicIndex(mi_input2, 0, 10);
	cout << "resut2: " << mi_resut2 << endl;



	getchar();
	return 0;
}


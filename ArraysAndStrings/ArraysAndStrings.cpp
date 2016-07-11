// ArraysAndStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;

//1.2 Write code to reverse a C-Style String. (C-String means that "abcd" is represented as five characters, including the null character.)

//1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
//FOLLOW UP
//Write the test cases for this method.

//1.1 Is Unique: Implement an algorithm to determine if a string  has all unique characters. What if you
//cannot use additional  data structures ?
//Hints: #44, #7£¬ #117, #732
bool IsUnique(string str)
{
	bool count[128] = { false };
	if (str.length() > 128)
		return false;
	int ind;

	for (int i = 0; i < str.length(); i++)
	{
		ind = str.at(i);
		if (count[ind])
			return false;
		count[ind] = true;
	}
	return true;
}

bool IsUniqueBitwise(string str)
{
	if (str.length() > 32)
		return false;
	int checker = 0;
	int ind;
	for (int i = 0; i < str.length(); i++)
	{
		ind = str.at(i) - 'a';
		if (checker & (1 << ind))
			return false;
		checker = checker | 1 << ind;
	}
	return true;
}


//1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other?
//Hints:  #7,  #84, #722,  #737

bool CheckPermutation(string a, string b)
{
	if (a.length() != b.length())
		return false;
	int count[128] = { 0 };
	int ind;

	for (int i = 0; i < a.length(); i++)
	{
		ind = a.at(i);
		count[ind]++;
	}

	for (int j = 0; j < b.length(); j++)
	{
		ind = b.at(j);
		count[ind]--;
		if (count[ind] < 0)
			return false;
	}

	return true;
}

//1.3 URLify: Write a method to replace all spaces in a string with %20? 
//You may assume that the string has sufficient space at the end to hold the additional characters, 
//and that you are given the "true" length of the string.
//EXAMPLE
//Input: "Mr John Smith    ",
//Output: "Mr%20John%20Smith"
//Hints: #53, #118
void ReplaceSpaces(char inputArray[], int trueLength)
{
	int spaceCount = 0;
	for (int i = 0; i < trueLength; i++)
	{
		if (inputArray[i] == ' ')
			spaceCount++;
	}

	inputArray[trueLength + 2 * spaceCount] = '\0';
	
	for (int i = trueLength-1; i >= 0; i--)
	{
		if (inputArray[i] == ' ')
		{
			inputArray[i + spaceCount * 2] = '0';
			inputArray[i + spaceCount * 2-1] = '2';
			inputArray[i + spaceCount * 2-2] = '%';
			spaceCount--;
		}
		else
		{ 			
			inputArray[i + spaceCount * 2] = inputArray[i];
		}		
	}

	return;
}

//1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
//A palindrome is a word or phrase that is the same forwards and backwards.A permutation
//is a rearrangement of letters.The palindrome does not need to be limited to just dictionary words.
//EXAMPLE
//Input : Tact Coa
//Output : True(permutations : "taco cat", "atco eta", etc.)
//Hints: #106, #121, #134, #136

bool IsPalindromePermutation(string str)
{
	int bitVector=0;
	int val;
	for (int i = 0; i < str.length(); i++)
	{
		if ((str.at(i) > 'A') && (str.at(i) < 'Z'))
			val = str.at(i) - 'A';
		else if((str.at(i) > 'a') && (str.at(i) < 'z'))
			val = str.at(i) - 'a';
		else continue;

		bitVector = bitVector ^ (1 << val);
	}

	if (bitVector & (bitVector - 1))
		return false;

	return true;
	
}

//1.5 One Away: There are three types of edits that can be performed on strings: insert a character,
//remove a character, or replace a character.Given two strings, write a function to check if they are
//one edit(or zero edits) away.
//EXAMPLE
//pale, ple -> true
//pales, pale -> true
//pale, bale -> true
//pale, bake -> false
//Hints:#23, #97, #130

bool OneAway(string a, string b)
{
	if (a.length() == b.length())
	{
		if (a==b)
			return true;
		else
		{
			bool diffFound = false;
			for (int i = 0; i < a.length(); i++)
			{
				if (a.at(i) != b.at(i))
				{				
					if (diffFound)
						return false;

					diffFound=true;
				}
			}

		}
		return true;
	}

	if ((a.length() == (b.length() + 1)) || (a.length() == (b.length() - 1)))
	{
		int ia = 0;
		int ib = 0;	
		bool diffFound = false;			
		while (ia < a.length() && ib < b.length())			
		{
			if (a.at(ia) != b.at(ib))
			{
				if (diffFound)
					return false;
				diffFound = true;
				if (a.length() > b.length())
					ib--;
				else
					ia--;
			}
			ia++;
			ib++;
		}
		return true;
	}

	return false;
}

//1.6 String Compression: Implement a method to perform basic string compression using the counts
//of repeated characters.For example, the string aabcccccaaa would become a2blc5a3.If the
//"compressed" string would not become smaller than the original string, your method should return
//the original string.You can assume the string has only uppercase and lowercase letters(a - z).
//Hints:#92, #110
string StringCompression(string str)
{
	string compressedStr = "";
	char previousChar=str.at(0);
	int charCount=0;
	string countStr;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) != previousChar)
		{
			countStr = to_string(charCount);
			compressedStr += previousChar;
			compressedStr += countStr;
			previousChar = str.at(i);
			charCount = 0;
		}			
		charCount++;		
	}
	countStr = to_string(charCount);
	compressedStr += previousChar;
	compressedStr += countStr;

	if (compressedStr.length() < str.length())
		return compressedStr;
	else
		return str;
}

//1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 
//bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
//Hints: #51, #100
void PrintMatrix(int matrix[][5], int sizeofRow, int sizeofCol)
{
	for (int i = 0; i <sizeofRow; i++)
	{
		for (int j = 0; j < sizeofCol; j++)
			cout << matrix[i][j]<<" ";
		cout << endl;
	}
}

void RotateElement(int matrix[][5], int x, int y, int n)
{
	int temp = matrix[n - y - 1][x];
	matrix[n - y - 1][x] = matrix[n - x - 1][n - y - 1];
	matrix[n - x - 1][n - y - 1] = matrix[y][n - x - 1];
	matrix[y][n - x - 1] = matrix[x][y];
	matrix[x][y] = temp;
}

void RotateMatrix90(int matrix[][5], int n)
{
	for (int i = 0; i < n / 2; i++)
		for (int j = i; j < n - i - 1; j++)
			RotateElement(matrix, i, j, 5);
}

void RotateMatrixMethod2(int matrix[][5], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
		for(int j=i+1; j<n; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}

	for(int i=0;i<n;i++)
		for(int j=0; j<n/2;j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[i][n - j - 1];
			matrix[i][n - j - 1] = temp;
		}
	
}

//1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, 
//its entire row and column is set to 0.
//Hints:#17,   #74,   #702
void ZeroMatrix(int matrix[][5], int sizeofRow, int sizeofCol)
{
	int rowBit = 0;
	int colBit = 0;
	for(int i=0;i<sizeofRow;i++)
		for (int j = 0; j < sizeofCol; j++)
		{
			if (matrix[i][j] == 0)
			{
				rowBit = rowBit | 1 << i;
				colBit = colBit | 1 << i;
			}
		}

	for (int i = 0; i < sizeofRow; i++)
	{
		if (rowBit & 1 << i)
		{
			for (int j = 0; j < sizeofCol; j++)
				matrix[i][j] = 0;
		}
	}

	for (int j = 0; j < sizeofCol; j++)
	{
		if (colBit & 1 << j)
		{
			for(int i=0; i<sizeofRow; i++)
				matrix[i][j] = 0;
		}
	}
}

//1.9 String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. 
//Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring 
//(i.e., "waterbottle"is a rotation of "erbottlewat".
//Hints: #34, #88, #104
bool IsSubstring(string a, string b)
{
	if (b.length() > a.length())
		return false;
	int lengthDiff = a.length() - b.length();
	int lengthB = b.length();
	for (int i = 0; i < lengthDiff; i++)
	{
		if(a.substr(i, lengthB)==b)
		return true;
	}
	return false;
}
bool CheckStringRotation(string a, string b)
{
	if (a.length() != b.length())
		return false;
	string doubleA = a.append(a);

	if (IsSubstring(doubleA, b))
		return true;

	return false;
}

int main()
{
	bool result;
	string InputString = "Hello";
	result = IsUnique(InputString);
	//cout << result << endl;
	InputString = "QWERTYUIOPASDF asdfghjk";
	result = IsUnique(InputString);
	//cout << result << endl;
	InputString = "hello";
	result = IsUniqueBitwise(InputString);
	//cout << result << endl;
	InputString = "abcdefg hijklmnop";
	result = IsUniqueBitwise(InputString);
	//cout << result << endl;
	

	string InputStringA = "Hello";
	string InputStringB = "lloHe";
	result = CheckPermutation(InputStringA, InputStringB);
	//cout << result << endl;
	
	char InputArray[] = "Mr John Smith*(&(()*)(^&*";
	int trueLength = 13;
	ReplaceSpaces(InputArray,trueLength);
	//cout << InputArray << endl;

	InputString = "Tact Coa";
	result = IsPalindromePermutation(InputString);
	//cout << result << endl;

	InputStringA = "pale";
	InputStringB = "pale";
	result = OneAway(InputStringA, InputStringB);
	//cout << result << endl;
	InputStringA = "pale";
	InputStringB = "ale";
	result = OneAway(InputStringA, InputStringB);
	//cout << result << endl;
	InputStringA = "pale";
	InputStringB = "pales";
	result = OneAway(InputStringA, InputStringB);
	//cout << result << endl;
	InputStringA = "pale";
	InputStringB = "bale";
	result = OneAway(InputStringA, InputStringB);
	//cout << result << endl;
	InputStringA = "pale";
	InputStringB = "bae";
	result = OneAway(InputStringA, InputStringB);
	//cout << result << endl;

	InputString = "aabcccccaaa";
	string OutputString = StringCompression(InputString);
	//cout << InputString << endl;
	//cout << OutputString << endl;

	int matrix[][5] =
	{
		{ 11, 12, 13, 14, 15 },
		{ 21, 22, 23, 24, 25 },
		{ 31, 32, 33, 34, 35 },
		{ 41, 42, 43, 44, 45 },
		{ 51, 52, 53, 54, 55}
	};

	//PrintMatrix(matrix, 5, 5);

	//RotateMatrix90(matrix, 5);

	//PrintMatrix(matrix, 5, 5);

	RotateMatrixMethod2(matrix, 5);

	//PrintMatrix(matrix, 5, 5);

	int matrix2[][5] =
	{
		{ 11, 12, 13, 14, 15 },
		{ 0, 22, 23, 24, 0 },
		{ 31, 32, 33, 34, 35 },
		{ 41, 42, 0, 44, 45 }
	};

	//PrintMatrix(matrix2, 4, 5);

	ZeroMatrix(matrix2, 4, 5);

	//PrintMatrix(matrix2, 4, 5);

	InputStringA = "waterbottle";
	InputStringB = "erbottlewat";
	result = CheckStringRotation(InputStringA, InputStringB);
	//cout << result << endl;

	getchar();

	return 0;
}


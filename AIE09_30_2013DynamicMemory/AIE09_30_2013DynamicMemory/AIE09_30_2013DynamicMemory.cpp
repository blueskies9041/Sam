// AIE09_30_2013DynamicMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void sort(int * sortedArray[]);

int _tmain(int argc, _TCHAR* argv[])
{
	int input = 0;
	int size = 0;
	int * theirArray; 
	theirArray = new int [size] ;

	cout << " How many numbers? " << endl;
	cin >> size;
	cout << " Fill array: " << endl;

	for(int i = 0; i < size; i++)
	{
		cout << "[" << i << "] :" ;
		cin >> theirArray[i];
		cout << endl;
	}

	cout << endl;

	//sorting
	int temp = 0;
	int count = size;


	

	

	for(int i = size; i > -1 ; i--)
	{
		cout << theirArray[i - 1] << " ";
	}

	cin.get();
	cin.get();

	return 0;
}

void sort(int inArray[], int size)
{
	
}

	

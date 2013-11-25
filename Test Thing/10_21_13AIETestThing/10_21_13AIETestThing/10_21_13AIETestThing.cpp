// 10_21_13AIETestThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char * sFizz = "Fizz" ;
	char * sBuzz = "Buzz" ;

	//srand(time(NULL));

	int size = 0;
	int * inArray = new int[size];

	cout << " Numbers in array: " << endl;
	cin >> size;
	
	for(int i = 0; i < size; i++)
	{
		cout << "inArray[" << i << "]:" ; 
		cin >> inArray[i];
		cout << endl;
	}

	cout << endl;

	for(int i = 0; i < size; i++)
	{
		if(inArray[i] % 3 == 0 && inArray[i] % 5 == 0)
			cout << sFizz << " " << sBuzz << endl;
		if(inArray[i] % 3 == 0 && inArray[i] != 0)
			cout << sFizz << endl;
		if(inArray[i] % 5 == 0 && inArray[i] != 0) 
			cout << sBuzz << endl;
		else
			cout << i << endl;
	}

	cin.get();
	cin.get();
	return 0;
}


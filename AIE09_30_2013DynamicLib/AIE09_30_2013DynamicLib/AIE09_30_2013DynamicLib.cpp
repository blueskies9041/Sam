// AIE09_30_2013DynamicLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char * makeString(char * String)
{
	int size = sizeof(String);
	char * buffer = new char[size];
	buffer = String;

	return buffer;
}

//char * newString(char * nextString, char * addedString)
//{
//	int size = sizeof(nextString) + sizeof(addedString);
//	char * buffer = new char[size];
//	buffer = strcat(buffer, nextString);
//	buffer = strcat(buffer, addedString);
//	
//	return buffer;
//}

char * mergeStrings(char * aString, char * addedString)
{
	char * newString = new char[(sizeof(aString) + sizeof(addedString))];
	memcpy(newString, aString, sizeof(newString));
	memmove(newString, newString + sizeof(addedString), sizeof(addedString));
	memcpy(newString, addedString, sizeof(newString));

	return newString;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char * aString = makeString("Hey I'm Sam ");
	char * anotherString = makeString("Fuck everything.");
	cout << aString;

	cout << mergeStrings(aString, anotherString);
	

	cin.get();
	cin.get();

	return 0;
}


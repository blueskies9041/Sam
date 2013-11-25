#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

bool Search(char * str, char item);
void RemoveDuplicates( char * str);

int main()
{
	char * str = "AABBCCD";
	RemoveDuplicates(str);

	cin.get();
	cin.get();

	return 0;
}

bool Search(char * str, char item)
{
	for(int i = 0 ; i < strlen(str); i++)
		if(item == str[i])
			return true;
		return false;
}

void RemoveDuplicates( char * str)
{
	vector<char> newString;
	vector<char>::iterator it;

	int count = 0;

	while(str[count] != '\0')
	{
		if(Search(str, str[count]))
			newString.push_back(str[count]);
		cout << str[count];
		count++;
	}
	
	cout << endl;

	for(it = newString.begin(); it != newString.end(); it++)
	{
		cout << *it;
	}

}
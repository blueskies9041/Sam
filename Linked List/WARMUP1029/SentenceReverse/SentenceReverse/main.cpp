#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

void SentenceReverse(char * str);

int main()
{

	char * str = "Hi I am Sam";
	
	SentenceReverse(str);

	cin.get();

	return 0;
}

void SentenceReverse(char * str)
{
	int iWordCount = 1;
	int iCharCount = 0;
	char * strReversed = nullptr;

	for(int i = 0 ; i < std::string(str).length() ; i++)
	{
		iCharCount++;
		if(isspace(str[i]))
			iWordCount++;
	}

	strReversed = new char[iCharCount];

	cout << iCharCount << endl;
	cout << iWordCount;
	//cout << strReversed;

}
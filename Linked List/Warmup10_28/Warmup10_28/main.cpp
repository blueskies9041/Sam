#include <iostream>
#include <string.h>

using namespace std;

void Reverse(char * a_cpString);

int main()
{
	char * cpString = "olleH" ;

	Reverse(cpString);
	
	cin.get();
	cin.get();

	return 0;
}

void Reverse(char * a_cpString)
{
	cout << a_cpString;

	char * cpReversedString = a_cpString;

	while(*cpReversedString)
		cpReversedString++;

	cpReversedString--;

	char tmp;
	while(a_cpString < cpReversedString)
	{
		tmp = *a_cpString;
		*a_cpString = *cpReversedString;
		a_cpString++;
		cpReversedString--;
	}

	cout << cpReversedString;

		

}
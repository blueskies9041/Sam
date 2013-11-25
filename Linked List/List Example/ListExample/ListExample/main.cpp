#include <iostream>
#include <list>
#include <vector>

using namespace std;


//Functions for list template
// .reverse() - Reverses list
// .unique() - Deletes all duplicate list members
// .sort() ???
// .insert(position, item);
// advance(iterator_Name, elements_to_Advance);

int main()
{
	std::list<int> intList;
	std::list<int>::iterator i;

	intList.push_back(2);
	intList.push_back(5);
	intList.push_back(4);

	i = intList.begin();
	advance(i, 3);

	intList.insert(i , 5);

	advance(i, -2);
	intList.insert(i, 14);
	cout << endl;


	for(i = intList.begin();  i != intList.end(); ++i)
			cout << *i << endl;

	intList.reverse();
	cout << endl;

	for(i = intList.begin();  i != intList.end(); ++i)
			cout << *i << endl;


	cout << endl << intList.size();

	cin.get();

	return 0;
}

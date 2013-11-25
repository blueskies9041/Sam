#include "banana.h"

int main()
{
	Banana bOne;
	Banana bTwo(1);
	Banana bThree(bOne);

	bTwo = bOne;

	bOne.Display();
	bTwo.Display();
	bThree.Display();

	system("pause");

	return 0;
}

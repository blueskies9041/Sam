//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>

#include "Game.h" //Has all my other includes

int main( int argc, char* argv[] )
{	
	//srand( time(NULL) );

	const int iScreenWidth = 1280;
	const int iScreenHeight = 780;

	Initialise(iScreenWidth, iScreenHeight, false);

	Level LevelOne;
	Player PlayerOne;

	do 
	{
		UpdateGame(PlayerOne, LevelOne);
		
	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}


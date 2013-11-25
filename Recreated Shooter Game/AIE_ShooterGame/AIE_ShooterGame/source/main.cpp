//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
//#include <iostream>

#include "Game.h" //Has all my other includes
//
//void debugGame(Game daGame);

int main( int argc, char* argv[] )
{	
	//srand( time(NULL) );
	const int iScreenWidth = 1280;
	const int iScreenHeight = 780;

	Initialise(iScreenWidth, iScreenHeight, false);
	
	Game DaGame;

	do 
	{
		DaGame.UpdateGame();

		if(DaGame.GetExit())
			break;

	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}

//void debugGame(Game daGame)
//{
//	system("cls");
//	//daGame.GetLevel().DebugLevel();
//	//daGame.GetLevel().GetPlayer().DebugPlayer();
//}

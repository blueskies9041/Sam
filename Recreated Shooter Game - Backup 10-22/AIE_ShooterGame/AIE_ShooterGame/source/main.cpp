//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
//#include <iostream>

#include "Game.h" //Has all my other includes

void debugGame(Game daGame);

int main( int argc, char* argv[] )
{	
	//srand( time(NULL) );
	const int iScreenWidth = 1280;
	const int iScreenHeight = 780;

	Initialise(iScreenWidth, iScreenHeight, false);

	int iMouseX;
	int iMouseY;

	bool debug = true;
	
	enum GAME_STATE
	{
		MENU,
		GAME,
		END,
	};

	void (Game::*Process)() = nullptr;

	Game DaGame;
	GAME_STATE eCurrentState = GAME;

	do 
	{
		GetMouseLocation(iMouseX, iMouseY);

		if(eCurrentState == MENU)
			Process = &Game::UpdateMenu;
		if(eCurrentState == GAME)
			Process = &Game::UpdateGame;

		if((iMouseX > 610 && iMouseX < 720) && (iMouseY > 180 && iMouseY < 200) && (eCurrentState == MENU && GetMouseButtonDown(0) ) )
			eCurrentState = GAME;

		(DaGame.*Process)();

		if(debug)
		{
			debug = !debug;
			debugGame(DaGame);
		}
		if(IsKeyDown('U'))
		{
			debug = !debug;
		} // DEBUGGING

	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}

void debugGame(Game daGame)
{
	system("cls");
	//daGame.GetLevel().DebugLevel();
	daGame.GetLevel().GetPlayer().DebugPlayer();
}

//////////////////////////////////////////////////////////////////////////
// TO DO NEXT CLASS: Start implementing level class design, divide up
// different types of game objects (sprites) into separate abstract classes
// and child classes. ( Screen for Menu/Level , InteractiveObject for Player/Enemy/Projectile )
// Also maybe work on menu thing.
// Implement state machines into all classes along the way.
//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Game.h"


int main( int argc, char* argv[] )
{	
	
	int iLevelWidth = 1024;
	int iLevelHeight = 768;
	
	Initialise( iLevelWidth, iLevelHeight , false, "Game!" );
	
	Game TheGame;

	do 
	{
		TheGame.Update();

	} while ( FrameworkUpdate() == false );
	

	Shutdown();

	return 0;
}


//////////////////////////////////////////////////////////////////////////
// TO DO NEXT CLASS: Start implementing level class design, divide up
// different types of game objects (sprites) into separate abstract classes
// and child classes. ( Screen for Menu/Level , InteractiveObject for Player/Enemy/Projectile )
// Also maybe work on menu thing.
// Implement state machines into all classes along the way.
//////////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "MenuState.h"

int main( int argc, char* argv[] )
{	
	
	int iLevelWidth = 1024;
	int iLevelHeight = 768;
	
	Initialise( iLevelWidth, iLevelHeight , false, "Game!" );
	
	Game TheGame;
	TheGame.ChangeState( MenuState::Instance() );
	do 
	{
		TheGame.Update();

	} while ( FrameworkUpdate() == false );
	

	Shutdown();

	return 0;
}


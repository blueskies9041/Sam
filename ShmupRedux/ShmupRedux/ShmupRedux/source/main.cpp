//////////////////////////////////////////////////////////////////////////

#include "Engine.h"
#include "IntroState.h"

int main( int argc, char* argv[] )
{	
	int iLevelWidth = 1024;
	int iLevelHeight = 768;

	Initialise(iLevelWidth, iLevelHeight, false, "Game!");

	Engine Game;

	Game.ChangeState(IntroState::Instance());

	do 
	{
		Game.Update();

	} while ( FrameworkUpdate() == false );
	

	Shutdown();

	return 0;
}


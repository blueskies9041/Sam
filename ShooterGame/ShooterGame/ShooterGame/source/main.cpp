//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Prototypes.h"

unsigned int uiBgImage = -1;



int main( int argc, char* argv[] )
{	
	const int iScreenWidth = 1680;
	const int iScreenHeight = 1050;
	Initialise( iScreenWidth, iScreenHeight, false, "Game" );

	uiBgImage = CreateSprite("./images/Blue Eye.png", iScreenWidth, iScreenHeight, false);
	Player MainCharacter;

	do 
	{
		DrawSprite(uiBgImage);	
		
		MainCharacter.Move();
		MainCharacter.Control();
		
		MainCharacter.Draw();
	} while ( FrameworkUpdate() == false );
	

	Shutdown();

	return 0;
}


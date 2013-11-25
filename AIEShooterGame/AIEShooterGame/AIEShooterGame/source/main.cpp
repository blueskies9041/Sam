//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "Vector2D.h"
#include "Sprite.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>

unsigned int uiBgImage = -1;

int main( int argc, char* argv[] )
{	
	const int iScreenWidth = 1680;
	const int iScreenHeight = 1050;
	Initialise( iScreenWidth, iScreenHeight, false);

	uiBgImage = CreateSprite("./images/Blue Eye.png", iScreenWidth, iScreenHeight, false);

	Vector2D playerPosition(840, 625);
	Vector2D playerSpeed(0,0);
	Sprite Player(playerPosition, playerSpeed, 100, 100, -1); 

	do 
	{
		DrawSprite(uiBgImage);

	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}


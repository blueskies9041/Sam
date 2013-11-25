//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "Prototypes.h"
#include "Player.h"
#include "gameObject.h"
#include "Projectile.h"
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
	Initialise( iScreenWidth, iScreenHeight, false, "Game" );

	uiBgImage = CreateSprite("./images/Blue Eye.png", iScreenWidth, iScreenHeight, false);

	Player MainCharacter;
	
	do 
	{
		DrawSprite(uiBgImage);
		MainCharacter.Draw();
		MainCharacter.HandleInput();
		/*MainCharacter.Shoot(*newBullet);*/


		Move(MainCharacter);


	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}

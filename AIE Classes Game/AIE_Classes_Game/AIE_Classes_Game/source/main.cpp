//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Vector2D.h"
#include "Sprite.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Level.h"
#include "MiscFunctions.h"

const int iScreenWidth = 1280;
const int iScreenHeight = 780;

int main( int argc, char* argv[] )
{	
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

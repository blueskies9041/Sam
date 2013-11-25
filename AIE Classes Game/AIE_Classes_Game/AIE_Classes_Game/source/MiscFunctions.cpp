#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "MiscFunctions.h"

void UpdateGame(Player &a_PlayerOne, Level &a_CurrentLevel)
{
	a_CurrentLevel.UpdateLevel(a_PlayerOne);
	a_PlayerOne.UpdatePlayer();

	//Temporary collision handling
	
}
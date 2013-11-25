#include "Game.h"

void UpdateGame(Player &a_PlayerOne, Level &a_CurrentLevel)
{
	a_CurrentLevel.UpdateLevel(a_PlayerOne);
	a_PlayerOne.UpdatePlayer();

}

void UpdateMenu()
{
	
}

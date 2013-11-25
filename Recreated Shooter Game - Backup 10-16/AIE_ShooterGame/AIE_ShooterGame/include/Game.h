#ifndef _GAME_H_
#define _GAME_H_

#include "AIE.h"
#include "Vector2D.h"
#include "Sprite.h"
#include "Player.h"
#include "Projectile.h"
#include "Level.h"

void UpdateGame(Player &a_PlayerOne, Level &a_CurrentLevel);
void UpdateMenu();

#endif
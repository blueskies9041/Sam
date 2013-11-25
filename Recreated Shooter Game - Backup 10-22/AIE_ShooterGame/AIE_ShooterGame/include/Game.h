#ifndef _GAME_H_
#define _GAME_H_

#include "AIE.h"
#include "Vector2D.h"
#include "Sprite.h"
#include "Player.h"
#include "Projectile.h"
#include "Level.h"

using namespace std;

class Game
{
	private:

		Level Menu;
		Level LevelOne;
		
	public:

		Game();
		~Game();
		void UpdateGame();
		void UpdateMenu();
		
		inline Level GetLevel() { return LevelOne; }
};


#endif
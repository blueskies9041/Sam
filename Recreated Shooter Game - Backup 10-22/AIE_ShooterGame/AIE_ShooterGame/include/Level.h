#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "AIE.h"
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include <time.h>
#include <stdlib.h>

class Level 
{
	private:
		
		int m_iNumTriggers;
		int m_iNumEnemies;
		int m_iCurrentEnemy;

		bool * m_abTriggers;

		Sprite Background; //Background for Menu
		Sprite * Sidebars;
		Sprite LongBackground;
		Enemy * Enemies;  
		Player PlayerOne;

	public:

		float m_fDistanceFromPlayer;
//=================================================================================//
//FUNCTION NAME: LEVEL CONSTRUCTOR
//RETURN TYPE: ??
//ARGUMENTS: NONE
//DESCRIPTION: Initialises and creates sprites for: the level, the scrolling level
//sidebars, the player, the enemies, and their respective projectiles.
//=================================================================================//
		Level();
		Level(int Menu); //Overloaded constructor for creating the Menu level only
//=================================================================================//
//FUNCTION NAME: LEVEL DECONSTRUCTOR
//RETURN TYPE: ??
//ARGUMENTS: NONE
//DESCRIPTION: 
//=================================================================================//
		~Level();

		void CreateEnemies(int a_iArraySize);
		void SpawnEnemyWave(int a_iArrayPosition, int a_iNumSpawn);
		void CameraManager();
		void UpdateLevel();
		void SpawnTriggers();
		void HandleCollisions();
		void DebugLevel();

		//ACCESS

		void SetCurrentEnemy(int a_SetCurrentEnemy) { m_iCurrentEnemy = a_SetCurrentEnemy; }

		inline Sprite GetLongBg() { return LongBackground; } 
		inline Player GetPlayer() { return PlayerOne; }
		inline int GetCurrentEnemy() { return m_iCurrentEnemy; }
		inline Sprite GetBackground() { return Background; }

};
#endif

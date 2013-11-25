#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Vector2D.h"
#include "AIE.h"
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include <time.h>
#include <stdlib.h>

class Level 
{
	private:
		int m_iWidth;
		int m_iHeight;
		int m_iSpriteID;
		int m_iNumEnemies;
		int m_iEnemyCount;

		Vector2D * EnemyPositions;
		Enemy * Enemies; 
	public:


		Level();
		~Level();

		Vector2D * LoadEnemyPositions(int a_iArraySize);
		Enemy * CreateEnemies(int a_iArraySize);

		void UpdateLevel(Player &_aPlayerOne);
		void SpawnEnemy(Enemy &a_Enemy, Player &a_Player, Vector2D a_SpawnPos); //Spawning just moves an offscreen enemy to an onscreen position
		
		//getters and setters, inline defs
		int GetWidth() { return m_iWidth; }
		int GetHeight() { return m_iHeight; }
		int GetSpriteID() { return m_iSpriteID; }
		int GetEnemyCount() { return m_iEnemyCount; }

		void SetWidth(int a_iItsSpeed) { m_iWidth = a_iItsSpeed; }
		void SetHeight(int a_iItsHeight) { m_iHeight = a_iItsHeight; }
		void SetSpriteID(int a_iItsSpriteID) { m_iSpriteID = a_iItsSpriteID; }
		void SetEnemyCount(int a_iItsEnemyCount) { m_iEnemyCount = a_iItsEnemyCount; }
};
#endif

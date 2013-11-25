//////////////////////////////////////////////////////////// 
// File: Level.h
// Author: Sam Legus	 
// Date Created: 10/1/2013
// Brief: Header for Level.cpp, which defines the Level class.
////////////////////////////////////////////////////////////

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
		
		int m_iNumTriggers; //Number of triggers for trigger array.
		int m_iNumEnemies; //Number of enemies for enemy array.
		int m_iScore; //Player's score.
		bool * m_abTriggers; //For enemys spawning
		bool m_bComplete; //Completion flag
		Sprite UIHealth; //Master health icon to be duplicated.
		Sprite UIAmmo; //Master ammo icon to duplicated.
		int * m_aiUIHealthCopies; //Array for storage of duplicated sprite IDs
		int * m_aiUIAmmoCopies; // " "
		Sprite Background; //Background for Menu
		Sprite * Sidebars; //Array of sprites for 4 scrolling sidebars
		Sprite LongBackground; //Sprite for moving level background
		Enemy * Enemies;  //Enemy array
		Player PlayerOne; //Player
		    
	public:

		float m_fDistanceFromPlayer; //Tracks the distance of the player from the bottom edge of LongBg

	/*	FUNCTION: Default Level Object Constructor
		BRIEF: Initializes all vital members of the level class using InitWorld(), InitUnits(), and 
		InitInterface(). */
		Level();
	/*	FUNCTION: Overloaded Level Object Constructor
		BRIEF: Used to create the menu and game over screens. 0 as arg = Menu, 1 as arg = GameOver */
		Level(int a_iSplashID); 
	/*	FUNCTION: Level Deconstructor
		BRIEF: n/a */
		~Level();
	/*	FUNCTION: InitWorld()
		BRIEF: Initializes the background art and terrain for the level. Also initializes the enemy spawn
		triggers.
		RETURN: void */
		void InitWorld();
	/*	FUNCTION: CreateEnemies(...)
		ARGUMENTS: int a_iArraySize
		BRIEF: Initializes a number of enemies equal to array size argument
		RETURN: void */
		void CreateEnemies(int a_iArraySize);
	/*	FUNCTION: InitUnits()
		BRIEF: Calls CreateEnemies, and initializes the Player.
		RETURN: void */
		void InitUnits();
	/*	FUNCTION: InitInterface()
		BRIEF: Initializes master sprites for interface icons. Duplicates sprites using the integer arrays stored in level.
		RETURN: void */
		void InitInterface();
	/*	FUNCTION: SpawnEnemyWave(...)
		ARGUMENTS: int a_iArrayPosition, int a_iNumSpawn
		BRIEF: Spawns a number of enemies equal to spawn number argument, from a position in the Enemy array equal the array position 
		argument.
		RETURN: void */
		void SpawnEnemyWave(int a_iArrayPosition, int a_iNumSpawn);
	/*	FUNCTION: CameraManager()
		BRIEF: Manages scrolling movement of sidebars and long background(the moving level).
		RETURN: void */
		void CameraManager();
	/*	FUNCTION: SpawnTrigger()
		BRIEF: Checks player's distance from the level's bottom edge, and spawns a wave of enemies if the trigger is true.
		Triggers are flagged to true everytime the player moves up 400 units.
		RETURN: void */
		void SpawnTriggers();
	/*	FUNCTION: UpdateWorld()
		BRIEF: Organization function. Calls CameraManager() and SpawnTriggers(), updates Level's distance from player, and sets the
		level's complete flag to true once the player reaches the end.
		RETURN: void */
		void UpdateWorld();
	/*	FUNCTION: UpdateInterface()
		BRIEF: Draws interface strings and sprites.
		RETURN: void */
		void UpdateInterface();
	/*	FUNCTION: HandleCollisions()
		BRIEF: Manages events for collision between player bullets and enemies and enemy bullets and the player.
		RETURN: void */
		void HandleCollisions();
	/*	FUNCTION: UpdateUnits()
		BRIEF: Calls update function for active enemies and the player. Also calls HandleCollisions()
		RETURN: void */
		void UpdateUnits();
	/*	FUNCTION: UpdateLevel()
		BRIEF: Master organizer function, calls UpdateWorld(), UpdateUnits(), and UpdateInterface()
		RETURN: void */
		void UpdateLevel();
		//void DebugLevel();

	/*	FUNCTIONS: INLINE ACCESS FUNCTIONS
		BRIEF: Getters and Setters for member variables of Level class. */
		inline int SetScore(int a_iSetScore) { m_iScore = a_iSetScore; }
		inline int GetScore() { return m_iScore; }
		inline bool GetComplete() { return m_bComplete; }
		inline void SetComplete(bool a_bCompleteSet) {m_bComplete = a_bCompleteSet;}
		inline Sprite GetLongBg() { return LongBackground; } 
		inline Player GetPlayer() { return PlayerOne; }
		inline Sprite GetBackground() { return Background; }

};
#endif

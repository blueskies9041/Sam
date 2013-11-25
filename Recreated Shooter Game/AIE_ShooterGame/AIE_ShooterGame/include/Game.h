//////////////////////////////////////////////////////////// 
// File: Game.h
// Author: Sam Legus	 
// Date Created: 10/1/2013
// Brief: Header for Game.cpp, which defines the Game class.
////////////////////////////////////////////////////////////

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
	public:

		//Enumeration for traveling between " Levels " (Menu, LevelOne, and GameOver) and exiting the game.
		enum GAME_STATE
		{
			MENU,
			GAME,
			END,
			EXIT,
		};
		
	/*	FUNCTION: Game Object Constructor
		BRIEF: Sets the exit flag for the game to false so it doesn't close immediately on the first
		update cycle. Sets the GameState to MENU, and creates the Menu, LevelOne, and GameOver levels.*/
		Game();
	/*	FUNCTION: Game Object Deconstructor
		BRIEF: Does nothing. */
		~Game();

	/*	FUNCTION: UpdateGame
		BRIEF: Calls the appropriate update function based on the current GAME_STATE
		RETURN: void */
		void UpdateGame();
	/*	FUNCTION: UpdateMenu
		BRIEF: Draws the menu wallpaper, and tests for button clicks on the Play and Exit Buttons.
		Switches game to GAME state on play click and END state and EXIT state on exit click.
		RETURN: void */
		void UpdateMenu();
	/*	FUNCTION: UpdateLevelOne
		BRIEF: Calls LevelOne's update function, tests for the complete flag and switches game to the 
		end state if it's true.
		RETURN: void */
		void UpdateLevelOne();
	/*	FUNCTION: UpdateLevelOne
		BRIEF: Draws the GameOver screen wallpaper and tests for clicks on the Play Again and Exit buttons.
		Switches to END state on exit click and GAME state on Play Again
		RETURN: void */
		void UpdateGameOver();
		
	/*	FUNCTIONS: INLINE ACCESS FUNCTIONS
		BRIEF: Getters and Setters for member variables of Game class. */

		inline void SetState(GAME_STATE eStateToSetTo) { eCurrentState = eStateToSetTo; }
		inline bool GetExit() { return m_bExit; }
		inline void SetExit(bool a_bSetExit) { m_bExit = a_bSetExit ;}
		inline GAME_STATE GetState() { return eCurrentState; }
		inline Level GetLevel() { return LevelOne; }

		//Function pointer to be used with GameStates in UpdateGame()
		void (Game::*Process)();

		

	private:

		bool m_bExit;
		Level Menu;
		Level GameOver;
		Level LevelOne;
		
		GAME_STATE eCurrentState;

};


#endif
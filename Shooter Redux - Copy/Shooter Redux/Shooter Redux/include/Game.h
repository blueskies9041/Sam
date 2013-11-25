//////////////////////////////////////////////////////////// 
// File: Game.h
// Author: Sam Legus	 
// Date Created: 11/1/2013
// Brief: Header for Game.cpp, which defines the Game class. 
////////////////////////////////////////////////////////////


#ifndef _GAME_H_
#define _GAME_H_

#include "AIE.h"
#include "Menu.h"

class Game
{
	public:

		enum GAME_STATE
		{
			MENU,
			GAME,
			GAME_OVER,
			EXIT,
		};

		Game();
		~Game();
		void Update();

		inline int GetMouseX() { return m_iMouseX; }
		inline int GetMouseY() { return m_iMouseY; }

	private:

		Menu MainMenu;
		Menu GameOver;
		int m_iMouseX;
		int m_iMouseY;
		GAME_STATE eCurrentState;
};

#endif
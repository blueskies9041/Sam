//////////////////////////////////////////////////////////// 
// File: Game.h
// Author: Sam Legus	 
// Date Created: 11/1/2013
// Brief: Header for Game.cpp, which defines the Game class. 
////////////////////////////////////////////////////////////


#ifndef _GAME_H_
#define _GAME_H_

#include "AIE.h"
#include <vector>

using namespace std;

class GameState;

class Game
{
	public:

		Game();
		~Game();
		void Update();

		void ChangeState(GameState * opState);
		void PushState(GameState * opState);
		void PopState(GameState * opState);

		inline int GetMouseX() { return m_iMouseX; }
		inline int GetMouseY() { return m_iMouseY; }

	private:

		int m_iMouseX;
		int m_iMouseY;
		vector<GameState*> states;
};

#endif
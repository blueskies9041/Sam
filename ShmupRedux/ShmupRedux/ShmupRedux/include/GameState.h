#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include "Engine.h"

class GameState
{
	public:

		//Create virtual functions for re-definition in other states
		virtual void Init() = 0;
		virtual void Update(Engine * a_opGame) = 0;

		//Common function shared by all game states in order to be able to traverse state machine
		void ChangeState(Engine * a_opGame, GameState * a_opState)
		{
			a_opGame->ChangeState(a_opState);
		}

	protected:

	GameState() {}
	unsigned int m_uiBackgroundID;


};

#endif
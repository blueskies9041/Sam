#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include "Game.h"

class GameState
{
public:

	virtual void Init() = 0;
	virtual void Cleanup() = 0;
	virtual void Update(Game* a_oGame) = 0;

	void ChangeState(Game* a_opGame, GameState * a_opState)
	{
		a_opGame->ChangeState(a_opState);
	}

protected:
	GameState() {}
};

#endif
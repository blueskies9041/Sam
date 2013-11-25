#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "AIE.h"
#include <vector>
using namespace std;

class GameState; //Temporarily define a GameState class so that GameState can be used as an argument for function prototypes.
/* NOTE : FORWARD DECLARATIONS MUST USE POINTERS */

class Engine
{
	public:

		void Init();
		void ChangeState(GameState * a_opState);
		void PushState(GameState * a_opState);
		void PopState(GameState * a_opState);
		void Update();

	private:	

		vector<GameState*> states;
};

#endif
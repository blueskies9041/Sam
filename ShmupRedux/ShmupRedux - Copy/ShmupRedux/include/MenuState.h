#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include "AIE.h"
#include "GameState.h"

class MenuState : public GameState
{
	public:
		void Init();
		void Update(Engine * a_opGame);

		//Tutorial called this "Singleton Implementation"
		static MenuState * Instance()
		{
			return &sm_oMenuState;
		}

	protected:
		//Singleton Implementation
		MenuState () {}

	private:
		//Singleton Implementation
		static MenuState sm_oMenuState;
		

};
#endif
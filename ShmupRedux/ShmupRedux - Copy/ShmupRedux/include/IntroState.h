#ifndef _INTROSTATE_H_
#define _INTROSTATE_H_

#include "AIE.h"
#include "GameState.h"

class IntroState : public GameState
{
	public:
		void Init();
		void Update(Engine * a_opGame);

		//Tutorial called this "Singleton Implementation"
		//Used to access an instance of the class within other .cpps
		static IntroState * Instance()
		{
			return &sm_oIntroState;
		}

	protected:
		//Single Implementation
		IntroState () {}

	private:
		//Singleton Implementation
		static IntroState sm_oIntroState;
		unsigned int m_uiBackgroundID;

};
#endif
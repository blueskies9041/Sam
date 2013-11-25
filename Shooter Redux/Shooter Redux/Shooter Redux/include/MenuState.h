#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include "AIE.h"
#include "GameState.h"
//#include "UIButton.h"

class MenuState : public GameState
{
public:
	
	virtual void Init();
	virtual void Cleanup();
	virtual void Update(Game* a_opGame);

	static MenuState * Instance()
	{
		return &sm_oMenuState;
	}

protected:

	MenuState() {}
	~MenuState() {}

private:

	static MenuState sm_oMenuState;
	unsigned int uiBackgroundID;
	//vector<UIButton> aoButtons;

};

#endif
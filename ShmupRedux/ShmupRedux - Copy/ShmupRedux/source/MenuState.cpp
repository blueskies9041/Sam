#include "Aie.h"
#include "Engine.h"
#include "GameState.h"
#include "MenuState.h"
#include "IntroState.h"
#include "LevelOneState.h"

//Singleton Implementation
MenuState MenuState::sm_oMenuState;

void MenuState::Init()
{
	m_uiBackgroundID = CreateSprite("./images/menuBG.png", 1024, 768, true);
	MoveSprite(m_uiBackgroundID, 1024 / 2 , 768 / 2);
}

void MenuState::Update(Engine * a_opGame)
{
	DrawSprite(m_uiBackgroundID);
		if(GetMouseButtonDown(0))
			ChangeState(a_opGame, LevelOneState::Instance());
}
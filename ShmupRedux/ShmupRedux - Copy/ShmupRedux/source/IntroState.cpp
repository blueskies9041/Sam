#include "Aie.h"
#include "Engine.h"
#include "GameState.h"
#include "IntroState.h"
#include "MenuState.h"

//Singleton Implementation
IntroState IntroState::sm_oIntroState;

void IntroState::Init()
{
	m_uiBackgroundID = CreateSprite("./images/introBG.png", 1024, 768, true);
	MoveSprite(m_uiBackgroundID, 1024 / 2 , 768 / 2);
}

void IntroState::Update(Engine * a_opGame)
{
	DrawSprite(m_uiBackgroundID);
	if(GetMouseButtonDown(0))
		ChangeState(a_opGame, MenuState::Instance());
}
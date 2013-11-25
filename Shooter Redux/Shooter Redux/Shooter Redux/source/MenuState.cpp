#include "MenuState.h"
#include "AIE.h"
#include "GameState.h"
#include "Vector2D.h"

MenuState MenuState::sm_oMenuState;

void MenuState::Init()
{
	Vector2D vBGDimensions(1024.0f, 768.0f);

	uiBackgroundID = CreateSprite("./images/menu.png", 1024, 768, true);
	MoveSprite(uiBackgroundID,  vBGDimensions.GetX() / 2 ,  vBGDimensions.GetY() / 2);
}

void MenuState::Update(Game* a_opGame)
{
	DrawSprite(uiBackgroundID);
}





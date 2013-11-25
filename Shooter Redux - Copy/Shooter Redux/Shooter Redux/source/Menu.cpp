#include "Menu.h"

using namespace std;
Menu::Menu()
{

}

Menu::Menu(char * cpFilepath, int a_iNumButtons)
{
	Vector2D vBGDimensions(1024.0f, 768.0f);
	Vector2D vPlayButtonPos(475.0f, 180.0f);
	Vector2D vExitButtonPos(475.0f, 230.0f);
	Vector2D vOptionsButtonPos(475.0f, 280.0f);

	std::vector<char *> acp_ButtonTexts;
		acp_ButtonTexts.push_back("Play");
		acp_ButtonTexts.push_back("Exit");
		acp_ButtonTexts.push_back("Options");

	m_iBackgroundID = CreateSprite( cpFilepath, vBGDimensions.GetX(), vBGDimensions.GetY(), true);
	MoveSprite(m_iBackgroundID,  vBGDimensions.GetX() / 2 ,  vBGDimensions.GetY() / 2);

	//char * acp_ButtonTexts[3] = { "Play" , "Exit", "Options" }; 

	ButtonList.push_back(UIButton(vPlayButtonPos,  18 * (sizeof(acp_ButtonTexts[0]) - 1) , 32 , acp_ButtonTexts[0]));
	ButtonList.push_back(UIButton(vExitButtonPos,  18 * (sizeof(acp_ButtonTexts[1]) - 1) , 32 , acp_ButtonTexts[1]));
	ButtonList.push_back(UIButton(vOptionsButtonPos,  18 * (sizeof(acp_ButtonTexts[2]) - 1) , 32 , acp_ButtonTexts[2]));
	
	acp_ButtonTexts.erase(acp_ButtonTexts.begin(), acp_ButtonTexts.end());
}

Menu::~Menu()
{

}

void Menu::Update()
{
	DrawSprite(m_iBackgroundID);
	//Iterate through button list and update each button
	for(std::list<UIButton>::iterator i = ButtonList.begin(); i != ButtonList.end(); i++)
	{
		i->Update();
	}
}
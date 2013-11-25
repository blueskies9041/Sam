
Menu::Menu(char * imgFile, int numButtons, char * ButtonNames[numButtons])
{
	
	const int c_iLetterWidth = 18;
	const int c_iButtonHeight = 32;
	
	//Background stuff, stays same
	Vector2D vBGDimensions(1024.0f, 768.0f);
	m_iBackgroundID = CreateSprite( cpFilepath, vBGDimensions.GetX(), vBGDimensions.GetY(), true);
	MoveSprite(m_iBackgroundID,  vBGDimensions.GetX() / 2 ,  vBGDimensions.GetY() / 2);
	
	//Button Stuff
		//Create button positions based on numButtons
		
		Vector2D * vButtonPositions = new Vector2D[numButtons];
		for(int i = 0 ; i < numButtons; i++)
		{
			vButtonPositions[i].SetX(480.0f);
			vButtonPositions[i].SetY(180.0f + (i*50));
		}
		
		for(int i = 0 ; i < numButtons; i++)
		{
			ButtonList.push_back(UIButton(vButtonPositions[i], c_iLetterWidth * (sizeof(ButtonNames[i]) - 1), c_iButtonHeight, ButtonNames[i]));
		}
		
		
		for(int i = 0; i < numButtons; i++)
		{
			ButtonList.push_back(...)
		}
		
		
}

//

	Vector2D vBGDimensions(1024.0f, 768.0f);
	Vector2D vPlayButtonPos(475.0f, 180.0f);
	Vector2D vExitButtonPos(475.0f, 230.0f);
	Vector2D vOptionsButtonPos(475.0f, 280.0f);

	m_iBackgroundID = CreateSprite( cpFilepath, vBGDimensions.GetX(), vBGDimensions.GetY(), true);
	MoveSprite(m_iBackgroundID,  vBGDimensions.GetX() / 2 ,  vBGDimensions.GetY() / 2);

	char * acp_ButtonTexts[3] = { "Play" , "Exit", "Options" }; 

	ButtonList.push_back(UIButton(vPlayButtonPos,  18 * (sizeof(acp_ButtonTexts[0]) - 1) , 32 , acp_ButtonTexts[0]));
	ButtonList.push_back(UIButton(vExitButtonPos,  60 , 32 , acp_ButtonTexts[1]));
	ButtonList.push_back(UIButton(vOptionsButtonPos,  105 , 32 , acp_ButtonTexts[2]));
	
	//
		char * cpPlaceHolderText = "Button";
	//Constants for button creation
	const int c_iLetterWidth = 18;
	const int c_iButtonHeight = 32;

	Vector2D * vButtonPositions = new Vector2D[a_iNumButtons];
	UIButton * UIButtons = new UIButton[a_iNumButtons];

	//Create positions for buttons for button creation
	for(int i = 0 ; i < a_iNumButtons; i++)
	{
		vButtonPositions[i].SetX(480.0f);
		vButtonPositions[i].SetY(180.0f + (i*50));
	}

	//Add buttons to button list
	for(int i = 0 ; i < a_iNumButtons; i++)
	{
		UIButtons[i] = UIButton(vButtonPositions[i], c_iLetterWidth * sizeof(cpPlaceHolderText), c_iButtonHeight, cpPlaceHolderText);
		ButtonList.push_back(UIButtons[i]);
	}
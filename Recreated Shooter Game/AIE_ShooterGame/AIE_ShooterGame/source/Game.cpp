#include "Game.h"

int iMouseX = 0;
int iMouseY = 0;

Game::Game()
{
	SetExit(false);
	//Passing 0 as an arg to Level(int SplashID) will create the menu.
	Menu = Level(0); 
	//Passing 1 as an arg to Level(int SplashID) will create the game over screen.
	GameOver = Level(1);
	//Passing no argument creates level one.
	LevelOne = Level();	
	eCurrentState = MENU;
}

Game::~Game()
{

}

void Game::UpdateMenu()
{
	Menu.GetBackground().Move();
	Menu.GetBackground().Draw();

	GetMouseLocation(iMouseX, iMouseY);
	if((iMouseX > 610 && iMouseX < 720) && (iMouseY > 180 && iMouseY < 200) && (GetMouseButtonDown(0) ) )
			eCurrentState = GAME;
	if((iMouseX > 630 && iMouseX < 680) && (iMouseY > 220 && iMouseY < 250) && (GetMouseButtonDown(0) ) )
			eCurrentState = EXIT;
}

void Game::UpdateLevelOne()
{
	LevelOne.UpdateLevel();
	if(LevelOne.GetComplete())
		eCurrentState = END;
}

void Game::UpdateGameOver()
{
	GameOver.GetBackground().Move();
	GameOver.GetBackground().Draw();
	GetMouseLocation(iMouseX, iMouseY);
	if((iMouseX > 500 && iMouseX < 760) && (iMouseY > 345 && iMouseY < 395) && (GetMouseButtonDown(0) ) )
	{
			eCurrentState = GAME;
			LevelOne = Level(); //THIS MAY BREAK THE GAME AT SOME POINT
	}
	if((iMouseX > 500 && iMouseX < 610) && (iMouseY > 410 && iMouseY < 460) && (GetMouseButtonDown(0) ) )
	{
		eCurrentState = EXIT;
	}

}

void Game::UpdateGame()
{
	if(eCurrentState == MENU)
			Process = &Game::UpdateMenu;
	if(eCurrentState == GAME)
			Process = &Game::UpdateLevelOne;
	if(eCurrentState == END)
			Process = &Game::UpdateGameOver;
	if(eCurrentState == EXIT)
		m_bExit = true;

	(this->*Process)();
}



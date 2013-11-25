#include "Game.h"

Game::Game()
{
	MainMenu = Menu("./images/menu.png", 3);
	//GameOver = Menu("./images/gameover.png");
}

Game::~Game()
{

}


void Game::Update()
{
	GetMouseLocation(m_iMouseX, m_iMouseY);

	MainMenu.Update();
}



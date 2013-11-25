#include "Game.h"

Game::Game()
{
	Menu = Level(0);
	LevelOne = Level();
}

Game::~Game()
{

}

void Game::UpdateMenu()
{
	Menu.GetBackground().Move();
	Menu.GetBackground().Draw();
}

void Game::UpdateGame()
{
	LevelOne.UpdateLevel();
}



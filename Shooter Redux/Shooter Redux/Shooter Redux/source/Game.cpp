#include "AIE.h"
#include "Game.h"
#include "GameState.h"

Game::Game()
{

}

Game::~Game()
{

}


void Game::ChangeState(GameState * a_opState)
{
	states.push_back(a_opState);
	states.back()->Init();
}

void Game::Update()
{
	GetMouseLocation(m_iMouseX, m_iMouseY);

	states.back()->Update(this);
}



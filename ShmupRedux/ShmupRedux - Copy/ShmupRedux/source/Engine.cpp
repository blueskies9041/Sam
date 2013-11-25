#include "AIE.h"
#include "GameState.h"
#include "Engine.h"

using namespace std;

void Engine::Init()
{

}

void Engine::Update()
{
	states.back()->Update(this);
}

void Engine::ChangeState(GameState * a_opState)
{
	states.push_back(a_opState);
	states.back()->Init();
}

void Engine::PushState(GameState * a_opState)
{
	
}

void Engine::PopState(GameState * a_opState)
{

}
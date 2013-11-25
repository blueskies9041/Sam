#include "Aie.h"
#include "Engine.h"
#include "GameState.h"
#include "MenuState.h"
#include "LevelOneState.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Vector2D.h"

LevelOneState LevelOneState::sm_oLevelOneState;

void LevelOneState::Init()
{
	unsigned int uiWallpaperSpriteID = CreateSprite("./images/leveloneBG.png", 1024, 768, true);
	m_aUnits.push_back(new Enemy);
	m_aUnits.push_back(new Player);
	
	m_aBackgroundElements.push_back(uiWallpaperSpriteID);

	for(std::vector<Unit*>::iterator it = m_aUnits.begin(); it != m_aUnits.end(); ++it)
	{
		(*it)->Init();
	}

	for(std::vector<unsigned int>::iterator it  = m_aBackgroundElements.begin(); it != m_aBackgroundElements.end(); ++it)
	{
		MoveSprite( *it, 512, 384  );
	}
	
}

void LevelOneState::Update(Engine * a_opGame)
{
	HandleCollisions();

	for(std::vector<unsigned int>::iterator it= m_aBackgroundElements.begin(); it != m_aBackgroundElements.end(); ++it)
	{
		DrawSprite(*it);
	}

	for(std::vector<Unit*>::iterator it = m_aUnits.begin(); it != m_aUnits.end(); ++it)
	{
		(*it)->Update();
	}

	if(GetMouseButtonDown(0))
	{
		ChangeState(a_opGame, MenuState::Instance());
		Cleanup();
	}
}

void LevelOneState::Cleanup()
{
	while(!m_aUnits.empty())
		delete m_aUnits.back(), m_aUnits.pop_back();
	while(!m_aBackgroundElements.empty())
	{
		//m_aBackgroundElements.erase(m_aBackgroundElements.begin(), m_aBackgroundElements.end());
		m_aBackgroundElements.pop_back();
	}
}

bool LevelOneState::CheckBoxCollision(Entity &a_roSource, Entity &a_roTarget)
{
	return (abs(a_roSource.GetPositionX() - a_roTarget.GetPositionX() * 2) < (a_roSource.GetWidth() + a_roTarget.GetWidth()))
		&& (abs(a_roSource.GetPositionY() - a_roTarget.GetPositionY() * 2) < (a_roSource.GetHeight() + a_roTarget.GetHeight()));
}

void LevelOneState::HandleCollisions()
{
				
}
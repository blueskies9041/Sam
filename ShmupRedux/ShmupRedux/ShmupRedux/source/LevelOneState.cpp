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
typedef std::vector<Unit*>::iterator UnitIterator;
typedef std::vector<Projectile*>::iterator ProjectileIterator;

void LevelOneState::Init()
{
	unsigned int uiWallpaperSpriteID = CreateSprite("./images/leveloneBG.png", 1024, 768, true);
	m_aUnits.push_back(new Player);
	m_aUnits.push_back(new Enemy);

	
	m_aBackgroundElements.push_back(uiWallpaperSpriteID);

	for(UnitIterator it = m_aUnits.begin(); it != m_aUnits.end(); ++it)
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

void LevelOneState::HandleCollisions()
{
	for(size_t i = 0; i < m_aUnits[0]->GetProjectiles().size(); ++i)
	{
		m_aUnits[1]->HandleCollision( *(m_aUnits[0]->GetProjectiles()[i]) );
	}
}
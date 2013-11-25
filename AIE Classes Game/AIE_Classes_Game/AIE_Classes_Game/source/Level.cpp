#include "Level.h"



Level::Level()
{
	m_iWidth = 1280;
	m_iHeight = 780;
	m_iSpriteID = CreateSprite("./images/Background.png", m_iWidth, m_iHeight, false);
	m_iNumEnemies = 10;

	EnemyPositions = LoadEnemyPositions(m_iNumEnemies);
	Enemies = CreateEnemies(m_iNumEnemies);
}

Level::~Level()
{

}

Vector2D * Level::LoadEnemyPositions(int a_iArraySize)
{
	EnemyPositions = new Vector2D[a_iArraySize];
	for(int i = 0; i < a_iArraySize; i++)
	{
		EnemyPositions[i].SetX(240.0f + i * 100);
		EnemyPositions[i].SetY(80.0f);
	}

	return EnemyPositions;
}

Enemy * Level::CreateEnemies(int a_iArraySize)
{
	Enemies = new Enemy[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Enemies[i] = Enemy();
		Enemies[i].Create("./images/GrayBox.png");
	}

	return Enemies;
}

void Level::UpdateLevel(Player &a_PlayerOne)
{
	DrawSprite(m_iSpriteID);

	if(a_PlayerOne.GetPositionY() < 290)
	{
		for(int i = 0 ; i < m_iNumEnemies; i++)
		{
			if(!Enemies[i].GetSpawned())
			{
				SpawnEnemy(Enemies[i] , a_PlayerOne, EnemyPositions[i]);
				Enemies[i].SetSpawned(true);
			}
		}
	}
	
	for(int j = 0; j < m_iNumEnemies; j++)
		Enemies[j].UpdateEnemy(a_PlayerOne);
}

void Level::SpawnEnemy(Enemy &a_Enemy, Player &a_Player, Vector2D a_SpawnPos)
{
	a_Enemy.SetPosition(a_SpawnPos);
}


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

void Level::CameraManager()
{


}

void Level::UpdateLevel(Player &a_PlayerOne)
{
	//Draw Background
	DrawSprite(m_iSpriteID);

	//If player crosses boundary, spawn enemies according to enemy positions array.
	SpawnTriggers(a_PlayerOne);

	//Handle all sprite collisions
	HandleCollisions(a_PlayerOne);

	//Updates enemies AI in accordance with Player's current position
	for(int j = 0; j < m_iNumEnemies; j++)
		Enemies[j].UpdateEnemy(a_PlayerOne);

}

void Level::SpawnEnemy(Enemy &a_Enemy, Player &a_Player, Vector2D a_SpawnPos)
{
	a_Enemy.SetPosition(a_SpawnPos);
}

void Level::SpawnTriggers(Player &a_PlayerOne)
{
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
}

void Level::HandleCollisions(Player &a_PlayerOne)
{
	//Checks Enemy Bullets Collisions with Player
	for(int k = 0; k < m_iNumEnemies; k++)
	{
		if(Enemies[k].GetSpawned())
		{
			for(int n = 0 ; n < Enemies[k].GetMaxAmmo() ; n++)
			{
				if(a_PlayerOne.CheckBoxCollision(Enemies[k].GetBullets()[n]))
				{
					a_PlayerOne.SetPositionX(100); //Need reset bullet position/speed function, implement health afterwards
					a_PlayerOne.SetPositionY(100);
					a_PlayerOne.SetHp( a_PlayerOne.GetHp() - 1);
				}	
			}
		}
	}

	//Checks Player Bullets Collisions with Enemies
	
	for(int j = 0 ; j < a_PlayerOne.GetMaxAmmo(); j++)
	{
		for(int i = 0; i < m_iNumEnemies; i++)
		{
			if(a_PlayerOne.GetBullets()[j].CheckBoxCollision(Enemies[i]))
			{
				Enemies[i].SetPositionX(500); 
				Enemies[i].SetPositionY(500);
				Enemies[i].SetHp(Enemies[i].GetHp() - 1);
			}
		}
	}

}

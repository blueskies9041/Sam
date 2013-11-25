#include "Level.h"

//CONSTRUCTOR
Level::Level()
{
	Vector2D bgPos(640,390);
	Vector2D SideBarPositions[4];
		SideBarPositions[0] = Vector2D(30, -390);
		SideBarPositions[1] = Vector2D(30, 1190);
		SideBarPositions[2] = Vector2D(1250, -390);
		SideBarPositions[3] = Vector2D(1250, 1190);

	Vector2D longBgPos(640,-780); //longBg is the actual level/terrain
	Vector2D defaultSpd(0,0);
	Vector2D halfBgSpd(0,2); //Sidebar speed
	Vector2D longBgSpd(0,0.2f);

	Background = Sprite(bgPos, defaultSpd, 1280, 780, -1);
	Background.Create("./images/background.png");
	Background.Move();

	Sidebars = new Sprite[4];
	for(int i = 0; i < 4; i++)
	{
		Sidebars[i] = Sprite(SideBarPositions[i], halfBgSpd, 60, 1580, -1);
		Sidebars[i].Create("./images/halfbgbar.png");
	}
	
	LongBackground = Sprite(longBgPos, longBgSpd, 1160, 3160, -1);
	LongBackground.Create("./images/longbackground.png");
	
	m_iNumEnemies = 40;
	m_iCurrentEnemy = -1;
	PlayerOne = Player();

	CreateEnemies(m_iNumEnemies);

	m_fDistanceFromPlayer = 0.0f;
	m_iNumTriggers = 8;

	m_abTriggers = new bool [m_iNumTriggers];
	for(int i = 0; i < m_iNumTriggers; i++)
	{
		m_abTriggers[i] = false;
	}

}

Level::Level(int Menu)
{
	Vector2D bgPos(640, 390);
	Vector2D bgSpd(0,0);

	Background = Sprite(bgPos, bgSpd, 1280, 780, -1);
	Background.Create("./images/background.png");
}

//DECONSTRUCTOR
Level::~Level()
{

}

//FUNCTION CREATES ENEMIES
void Level::CreateEnemies(int a_iArraySize)
{
	Enemies = new Enemy[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Enemies[i] = Enemy();
		Enemies[i].Create("./images/GrayBox.png");
	}
}

void Level::SpawnEnemyWave(int a_iArrayPosition,int a_iNumSpawn)
{
	int iCount = 0;
	for(int i = a_iArrayPosition; i < a_iArrayPosition + a_iNumSpawn; i++)
	{
		iCount++;
		Enemies[i].SetSpawned(true);
		if(Enemies[i].GetPositionX() < 0 && Enemies[i].GetPositionY() < 0 && !Enemies[i].GetDead())
		{
			Enemies[i].SetPositionY(Background.GetPositionY() - 430);
			Enemies[i].SetPositionX(370 +(iCount * 100.0f));
		}
	}
}



//FUNCTION DOES THAT CHEATY CAMERA METHOD JUSTIN TAUGHT ME, MOVES LEVEL + SIDEBARS
void Level::CameraManager()
{
	for(int i = 0 ; i < 4; i++)
	{
		Sidebars[i].Move();
		Sidebars[i].Draw();
	}

	LongBackground.Move();
	LongBackground.Draw();

	if(Sidebars[1].GetPositionY() > 1580)
		Sidebars[1].SetPositionY(Sidebars[0].GetPositionY() - 1580);
	if(Sidebars[0].GetPositionY() > 1580)
		Sidebars[0].SetPositionY(Sidebars[1].GetPositionY() - 1580);
	if(Sidebars[3].GetPositionY() > 1580)
		Sidebars[3].SetPositionY(Sidebars[2].GetPositionY() - 1580);
	if(Sidebars[2].GetPositionY() > 1580)
		Sidebars[2].SetPositionY(Sidebars[3].GetPositionY() - 1580);
	
}

//FUNCTION UPDATES LEVEL (PLAYER, ENEMIES, THEIR RESPECTIVE PROJECTILES, TRIGGERS FOR ENEMY SPAWNS, AND COLLISION BETWEEN ALL
//PLAYERS, ENEMIES, AND THEIR RESPECTIVE HOSTILE PROJECTILES
void Level::UpdateLevel()
{
	//Camera manager manages backgrounds and camera logic
	CameraManager();

	//Determine player's distance from the bottom edge of the level
	m_fDistanceFromPlayer = abs(PlayerOne.GetPositionY() - LongBackground.GetPositionY() - (LongBackground.GetHeight() / 2));
	
	PlayerOne.UpdatePlayer();

	////If player crosses boundary, spawn enemies according to enemy positions array.
	SpawnTriggers();

	//Updates enemies AI in accordance with Player's current position
	for(int j = 0; j < m_iNumEnemies; j++)
		Enemies[j].UpdateEnemy(PlayerOne);

	//Handle all sprite collisions
	HandleCollisions();

	if(m_fDistanceFromPlayer > 3200)
		;;
}

//FUNCTION CHECKS IF A PLAYER HAS CROSSED A BOUNDARY AND THEN SPAWNS AN ENEMY
void Level::SpawnTriggers()
{
	//Spawn a wave every 400 pixels moved
	for(int i = 0 ; i < m_iNumTriggers ; i++)
	{
		if(m_fDistanceFromPlayer > 400 * (i + 1))
			m_abTriggers[i] = true;
	}

	for(int i = 0 ; i < m_iNumTriggers ; i++)
	{
		if(m_abTriggers[i])
		{
			SpawnEnemyWave(i * 5, 5);
		}
	}

}

//FUNCTION HANDLES COLLISIONS BETWEEN PLAYER, ENEMY, AND THEIR RESPECTIVE HOSTILE BULLETS
void Level::HandleCollisions()
{
	//Checks Enemy Bullets Collisions with Player
	for(int k = 0; k < m_iNumEnemies; k++)
	{
		if(Enemies[k].GetSpawned())
		{
			for(int n = 0 ; n < Enemies[k].GetMaxAmmo() ; n++)
			{
				if(PlayerOne.CheckBoxCollision(Enemies[k].GetBullets()[n]))
				{
					if(Enemies[k].GetBullets()[n].GetAlive())
						PlayerOne.SetHp(PlayerOne.GetHp() - 1);
					Enemies[k].GetBullets()[n].SetAlive(false);
				}	
			}
		}
	}

	//Checks Player Bullets Collisions with Enemies
	
	for(int j = 0 ; j < PlayerOne.GetMaxAmmo(); j++)
	{
		for(int i = 0; i < m_iNumEnemies; i++)
		{
			if(PlayerOne.GetBullets()[j].CheckBoxCollision(Enemies[i]))
			{
				Enemies[i].SetHp(Enemies[i].GetHp() - 1);
				PlayerOne.GetBullets()[j].SetAlive(false);
			}
		}
	}

}

void Level::DebugLevel()
{
	cout << "Level's Private Variables" << endl << endl;
	cout << " int m_iNumTriggers: " << m_iNumTriggers << endl;
	cout << " int m_iNumEnemies: " << m_iNumEnemies << endl;
	cout << " int m_iCurrentEnemy: " << m_iCurrentEnemy << endl;

	for(int i = 0 ; i < m_iNumTriggers; i++)
	{
		if(m_abTriggers[i])
			cout << " bool m_abTriggers[" << i << "] : True" << endl;
		else if(!m_abTriggers[i])
			cout << " bool m_abTriggers[" << i << "] : False" << endl;
		else
			cout << " bool m_abTriggers[" << i << "] : Error" << endl;
	}

	cout << " float m_fDistanceFromPlayer: " << m_fDistanceFromPlayer << endl << endl;
	cout << "Sprite ID's " << endl;
	cout << " BG:" << Background.GetSpriteID() << endl;
	cout << " LongBG(Scrolling Level): " << LongBackground.GetSpriteID() << endl;
	cout << " Sidebars: " ;
	for(int i = 0 ; i < 4 ; i ++)
		cout << Sidebars[i].GetSpriteID() << " ";
	cout << endl;
}
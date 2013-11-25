#include "Level.h"

Vector2D Dead(-100, -100);
int iCount = 0;

//CONSTRUCTOR
Level::Level()
{
	m_bComplete = false;
	InitWorld(); 
	InitUnits();
	InitInterface();
}

Level::Level(int a_iSplashID)
{
	Vector2D bgPos(640, 390);
	Vector2D bgSpd(0,0);

	if(a_iSplashID == 0)
	{
		Background = Sprite(bgPos, bgSpd, 1280, 780, -1);
		Background.Create("./images/menu.png");
	}
	if(a_iSplashID == 1)
	{
		Background = Sprite(bgPos, bgSpd, 1280, 780, -1);
		Background.Create("./images/gameover.png");
	}
}

//DECONSTRUCTOR
Level::~Level()
{

}

void Level::InitWorld()
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
	Vector2D longBgSpd(0,0.5f);
	
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

	m_fDistanceFromPlayer = 0.0f;
	m_iNumTriggers = 8;
	m_abTriggers = new bool [m_iNumTriggers];

	for(int i = 0; i < m_iNumTriggers; i++)
	{
		m_abTriggers[i] = false;
	}
}

//FUNCTION CREATES ENEMIES
void Level::CreateEnemies(int a_iArraySize)
{
	Enemies = new Enemy[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Enemies[i] = Enemy();
	}
}

void Level::InitUnits()
{
	m_iScore = 0;
	m_iNumEnemies = 40;
	PlayerOne = Player();
	CreateEnemies(m_iNumEnemies);
}

void Level::SpawnEnemyWave(int a_iArrayPosition,int a_iNumSpawn)
{
	for(int i = a_iArrayPosition; i < a_iArrayPosition + a_iNumSpawn; i++)
	{
		if(!Enemies[i].GetSpawned())
		{
			iCount++;
			Enemies[i].SetSpawned(true);
			Enemies[i].SetPositionY(Background.GetPositionY() - 300);
			Enemies[i].SetPositionX(370 +(iCount * 100.0f));
			if(iCount >= a_iNumSpawn)
				iCount = 0;
		}
	}
}


void Level::InitInterface()
{
	Vector2D hpBarPos(225, 115);
	Vector2D ammoCounterPos(225, 165);
	Vector2D defaultSpd(0,0);

	UIHealth = Sprite(hpBarPos, defaultSpd, 27, 27, -1);
	UIHealth.Create("./images/UIHealth.png");
	UIAmmo = Sprite(ammoCounterPos, defaultSpd, 27 , 27, -1);
	UIAmmo.Create("./images/UIAmmo.png");

	m_aiUIHealthCopies = new int[PlayerOne.GetHp()];
	m_aiUIAmmoCopies = new int [PlayerOne.GetAmmo()];

	for(int i = 0 ; i < PlayerOne.GetHp() ; i++)
	{
		m_aiUIHealthCopies[i] = DuplicateSprite(UIHealth.GetSpriteID());
		MoveSprite(m_aiUIHealthCopies[i], hpBarPos.GetX() + (i * 50), hpBarPos.GetY());
	}
	
	for(int j = 0 ; j < PlayerOne.GetAmmo() ; j++)
	{
		m_aiUIAmmoCopies[j] = DuplicateSprite(UIAmmo.GetSpriteID());
		MoveSprite(m_aiUIAmmoCopies[j], ammoCounterPos.GetX() + (j * 50), ammoCounterPos.GetY());
	}
}

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

//FUNCTION DOES THAT CHEATY CAMERA METHOD JUSTIN TAUGHT ME, MOVES LEVEL + SIDEBAR

void Level::UpdateWorld()
{
	m_fDistanceFromPlayer = abs(PlayerOne.GetPositionY() - LongBackground.GetPositionY() - (LongBackground.GetHeight() / 2));
	CameraManager();
	SpawnTriggers();
	if(m_fDistanceFromPlayer > 3000)
		m_bComplete = true;
}

void Level::UpdateInterface()
{
	static char as_cScore[3] = {'\n'};
	sprintf(as_cScore, "Score: %d", m_iScore);

	DrawString("Health - " , 100 , 100, (0xFF,0xFF,0xFF,0xFF));
	DrawString("Ammo - " , 100 , 140 , (0xFF,0xFF,0xFF,0xFF));
	DrawString(as_cScore , 100 , 180 , (0xFF,0xFF,0xFF,0xFF));

	for(int i = 0 ; i < PlayerOne.GetHp() ; i++)
	{
		DrawSprite(m_aiUIHealthCopies[i]);
	}

	for(int j = 0 ; j < PlayerOne.GetAmmo() ; j++)
	{
		DrawSprite(m_aiUIAmmoCopies[j]);
	}
}

//FUNCTION HANDLES COLLISIONS BETWEEN PLAYER, ENEMY, AND THEIR RESPECTIVE HOSTILE BULLETS
void Level::HandleCollisions()
{
	//Checks Enemy Bullets Collisions with Player
	for(int k = 0; k < m_iNumEnemies; k++)
	{
		if(Enemies[k].GetAlive())
		{
			for(int n = 0 ; n < Enemies[k].GetMaxAmmo() ; n++)
			{
				if(PlayerOne.CheckBoxCollision(Enemies[k].GetBullets()[n]))
				{
					PlayerOne.SetHp(PlayerOne.GetHp() - 1);
					Enemies[k].GetBullets()[n].SetPosition(Dead);
				}	
			}
		}
	}

	//Checks Player Bullets Collisions with Enemies
	for(int i = 0; i < m_iNumEnemies; i++)
	{
		for(int j = 0 ; j < PlayerOne.GetMaxAmmo(); j++)
		{
			if(PlayerOne.GetBullets()[j].CheckBoxCollision(Enemies[i]))
			{
				Enemies[i].SetHp(Enemies[i].GetHp() - 1);
				PlayerOne.GetBullets()[j].SetPosition(Dead);
				m_iScore++;
			}
		}
	}

	

}


void Level::UpdateUnits()
{
	PlayerOne.UpdatePlayer();
	for(int j = 0; j < m_iNumEnemies; j++)
		Enemies[j].UpdateEnemy(PlayerOne);
	HandleCollisions();
}


//FUNCTION UPDATES LEVEL (PLAYER, ENEMIES, THEIR RESPECTIVE PROJECTILES, TRIGGERS FOR ENEMY SPAWNS, AND COLLISION BETWEEN ALL
//PLAYERS, ENEMIES, AND THEIR RESPECTIVE HOSTILE PROJECTILES
void Level::UpdateLevel()
{
	UpdateWorld();
	UpdateUnits();
	UpdateInterface();		
}

//void Level::DebugLevel()
//{
//	cout << "Level's Private Variables" << endl << endl;
//	cout << " int m_iNumTriggers: " << m_iNumTriggers << endl;
//	cout << " int m_iNumEnemies: " << m_iNumEnemies << endl;
//
//	for(int i = 0 ; i < m_iNumTriggers; i++)
//	{
//		if(m_abTriggers[i])
//			cout << " bool m_abTriggers[" << i << "] : True" << endl;
//		else if(!m_abTriggers[i])
//			cout << " bool m_abTriggers[" << i << "] : False" << endl;
//		else
//			cout << " bool m_abTriggers[" << i << "] : Error" << endl;
//	}
//
//	cout << " float m_fDistanceFromPlayer: " << m_fDistanceFromPlayer << endl << endl;
//	cout << "Sprite ID's " << endl;
//	cout << " BG:" << Background.GetSpriteID() << endl;
//	cout << " LongBG(Scrolling Level): " << LongBackground.GetSpriteID() << endl;
//	cout << " Sidebars: " ;
//	for(int i = 0 ; i < 4 ; i ++)
//		cout << Sidebars[i].GetSpriteID() << " ";
//	cout << endl;
//
//}
#include "Player.h"

Vector2D a_playerPos(640, 390);
Vector2D a_playerSpd(0,0);
const int c_iPlayerWidth = 50;
const int c_iPlayerHeight = 50;
int iPlayerSpriteID = -1;

//int iCircleCountThingy = 0;
//float X = 0.0f;
//float Y = 0.0f;

Player::Player()
{
	SetPosition(a_playerPos);
	SetSpeed(a_playerSpd);
	SetWidth(c_iPlayerWidth);
	SetHeight( c_iPlayerHeight );
	SetSpriteID(iPlayerSpriteID);
	Create("./images/PlayerShip.png");
	m_iMaxAmmo = 9;
	m_iAmmo = m_iMaxAmmo;
	SetAlive(true);
	m_bShot = false;
	m_iTimer = 0;
	m_iHp = 10;
	CreateBullets(m_iMaxAmmo);		
}

Player::~Player()
{
	//delete [] Bullets;
}

void Player::CreateBullets(int a_iArraySize)
{
	Bullets = new Projectile[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Bullets[i] = Projectile();
	}
}

void Player::UpdatePlayer()
{
	UpdateAlive();

	m_iTimer++;

	for(int i = 0; i < m_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();

	Move();
	Draw();
	Control();
}

void Player::Draw()
{
	if(GetAlive())
		Sprite::Draw();
}

void Player::Move()
{
	if(GetAlive())
		Sprite::Move();

	RestrictMovement();
}

void Player::RestrictMovement()
{
	if(GetPositionX() < 0 + (GetWidth() / 2))
		SetPositionX(GetPositionX() - GetSpeedX());
	if(GetPositionX() > 1280 - (GetWidth() / 2))
		SetPositionX(GetPositionX() - GetSpeedX());
	if(GetPositionY() < 0 + (GetHeight() / 2))
		SetPositionY(GetPositionY() - GetSpeedY());
	if(GetPositionY() > 780 - (GetHeight() / 2))
		SetPositionY(GetPositionY() - GetSpeedY());
}

void Player::Control()
{
	SetSpeed(0,0);
	
	if(IsKeyDown('A'))
		SetSpeedX(-1.0f);
	if(IsKeyDown('D'))
		SetSpeedX(1.0f);
	if(IsKeyDown('W'))
		SetSpeedY(-1.0f);
	if(IsKeyDown('S'))
		SetSpeedY(1.0f);

	if(GetMouseButtonDown(0))
		Shoot();
	if(GetMouseButtonDown(1))
		SpreadShot();

	/*if(IsKeyDown('G'))
	{
		if(iCircleCountThingy == 360)
			iCircleCountThingy = 0;
		
		iCircleCountThingy++;
		X = (float)cos((iCircleCountThingy*0.0174532925));
		Y = (float)sin((iCircleCountThingy*0.0174532925));
		SetSpeedX(X);
		SetSpeedY(Y);	
	}*/
}



void Player::Shoot()
{
	Reload();

	if(m_iTimer > 40)
	{
		Bullets[m_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
		Bullets[m_iMaxAmmo - m_iAmmo].SetAlive(true);
		Bullets[m_iMaxAmmo - m_iAmmo].SetSpeedY(-2);
		m_iAmmo--;
		m_iTimer = 0;
	}
}

void Player::SpreadShot()
{
	Reload();

	Vector2D newSpeed(-2, -2);
	if(m_iTimer > 160)
	{
		for(int i = 0 ; i < 3; i++)
		{
			newSpeed.SetX(newSpeed.GetX() + 1);
			Bullets[m_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
			Bullets[m_iMaxAmmo - m_iAmmo].SetAlive(true);
			Bullets[m_iMaxAmmo - m_iAmmo].SetSpeed(newSpeed);
			
			m_iAmmo--;
		}
		m_iTimer = 0;
	}
}


void Player::Reload()
{
	if(m_iAmmo <= 0)
		m_iAmmo = m_iMaxAmmo;
}

void Player::UpdateAlive()
{
	if(m_iHp <= 0)
		SetAlive(false);
}


//void Player::DebugPlayer()
//{
//	cout << endl;
//	cout << "Player's Private Variables" << endl << endl;
//	cout << " POSITION: " << GetPositionX() << " , " << GetPositionY() << endl;
//	cout << " SPEED: " << GetSpeedX() << " , " << GetSpeedY() << endl;
//	cout << " DIMENSIONS " << GetWidth() << " x " << GetHeight() << endl;
//	cout << " SPRITE ID: " << GetSpriteID() << endl << endl;
//
//	cout << " int m_iAmmo: " << m_iAmmo << endl;
//	cout << " int m_iMaxAmmo: " << m_iMaxAmmo << endl;
//	cout << " int m_iTimer: " << m_iTimer << endl;
//	cout << " int m_iHp: " << m_iHp << endl;
//	if(m_bShot)
//		cout << " bool m_bShot: True" << endl;
//	else if(!m_bShot)
//		cout << " bool m_bShot: False" << endl;
//	else
//		cout << " bool m_bShot: Error" << endl;
//
//	cout << endl;
//	cout << "Order - Pos, Spd, Dimensions, SpriteID" << endl;
//	for(int i = 0 ; i < m_iMaxAmmo; i++)
//	{
//		cout << " Bullets[" << i << "] : (" << Bullets[i].GetPositionX() << " , " << Bullets[i].GetPositionY() << ") , (" << Bullets[i].GetSpeedX() << " , " << Bullets[i].GetSpeedY() << ") , (" ;
//		cout << Bullets[i].GetWidth() << " x " << Bullets[i].GetHeight() << ") , " << Bullets[i].GetSpriteID() << endl;
//	}
//
////	cout << iCircleCountThingy << endl;
//	cout << endl;
//}
//



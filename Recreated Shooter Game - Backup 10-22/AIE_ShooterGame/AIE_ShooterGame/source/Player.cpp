#include "Player.h"

Vector2D a_playerPos(640, 390);
Vector2D a_playerSpd(0,0);
const int c_iPlayerWidth = 50;
const int c_iPlayerHeight = 50;
int iPlayerSpriteID = -1;

Player::Player()
{
	SetPosition(a_playerPos);
	SetSpeed(a_playerSpd);
	SetWidth(c_iPlayerWidth);
	SetHeight( c_iPlayerHeight );
	SetSpriteID(iPlayerSpriteID);
	Create("./images/GrayBox.png");
	m_iMaxAmmo = 9;
	m_iAmmo = m_iMaxAmmo;
	m_bShot = false;
	m_iTimer = 0;
	m_iHp = 10;
	CreateBullets(m_iMaxAmmo);		
}

Player::~Player()
{

}

Projectile * Player::GetBullets()
{
	return Bullets;
}

void Player::CreateBullets(int a_iArraySize)
{
	Bullets = new Projectile[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Bullets[i] = Projectile();
		Bullets[i].Create("./images/Projectile.png");
	}
}

void Player::UpdatePlayer()
{
	if(m_iHp <= 0)
		m_bAlive = false;

	m_iTimer++;


	for(int i = 0; i < m_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();

	Control();
	Move();
	Draw();

	

}

void Player::Draw()
{
	if(m_bAlive)
		Sprite::Draw();
}

void Player::Move()
{
	if(m_bAlive)
		Sprite::Move();
}

int i = 0;
void Player::Control()
{
	SetSpeed(0,0);
	
	float X = cos(i*0.0174532925);		// 0.0174532925 = 1 radian
	float Y = sin(i*0.0174532925);

	if(IsKeyDown('A'))
		SetSpeedX(-2.0f);
	if(IsKeyDown('D'))
		SetSpeedX(2.0f);
	if(IsKeyDown('W'))
		SetSpeedY(-1.5f);
	if(IsKeyDown('S'))
		SetSpeedY(1.5f);

	if(IsKeyDown('G'))
	{
		SetSpeedX(X);
		SetSpeedY(Y);
		i++;
	}
	


	if(IsKeyDown('T'))
		Shoot();
	if(IsKeyDown('R'))
		SpreadShot();
}


void Player::Shoot()
{
	Reload();

	if(!Bullets[m_iMaxAmmo - m_iAmmo].GetAlive() && m_iTimer > 40)
	{
		Bullets[m_iMaxAmmo - m_iAmmo].SetAlive(true);
		Bullets[m_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
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
			if(!Bullets[m_iMaxAmmo - m_iAmmo].GetAlive())
			{
				newSpeed.SetX(newSpeed.GetX() + 1);
				Bullets[m_iMaxAmmo - m_iAmmo].SetAlive(true);
				Bullets[m_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
				Bullets[m_iMaxAmmo - m_iAmmo].SetSpeed(newSpeed);
			
				m_iAmmo --;
			}
			m_iTimer = 0;
		}
	}
}


void Player::Reload()
{
	if(m_iAmmo <= 0)
		m_iAmmo = m_iMaxAmmo;
}

void Player::DebugPlayer()
{
	cout << endl;
	cout << "Player's Private Variables" << endl << endl;
	cout << " POSITION: " << GetPositionX() << " , " << GetPositionY() << endl;
	cout << " SPEED: " << GetSpeedX() << " , " << GetSpeedY() << endl;
	cout << " DIMENSIONS " << GetWidth() << " x " << GetHeight() << endl;
	cout << " SPRITE ID: " << GetSpriteID() << endl << endl;

	cout << " int m_iAmmo: " << m_iAmmo << endl;
	cout << " int m_iMaxAmmo: " << m_iMaxAmmo << endl;
	cout << " int m_iTimer: " << m_iTimer << endl;
	cout << " int m_iHp: " << m_iHp << endl;
	if(m_bShot)
		cout << " bool m_bShot: True" << endl;
	else if(!m_bShot)
		cout << " bool m_bShot: False" << endl;
	else
		cout << " bool m_bShot: Error" << endl;

	cout << endl;
	cout << "Order - Pos, Spd, Dimensions, SpriteID" << endl;
	for(int i = 0 ; i < m_iMaxAmmo; i++)
	{
		cout << " Bullets[" << i << "] : (" << Bullets[i].GetPositionX() << " , " << Bullets[i].GetPositionY() << ") , (" << Bullets[i].GetSpeedX() << " , " << Bullets[i].GetSpeedY() << ") , (" ;
		cout << Bullets[i].GetWidth() << " x " << Bullets[i].GetHeight() << ") , " << Bullets[i].GetSpriteID() << endl;
	}

	cout << endl;
}




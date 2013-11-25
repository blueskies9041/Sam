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
	m_iMaxAmmo = 5;
	m_iAmmo = m_iMaxAmmo;
	m_bShot = false;
	m_iTimer = 0;
	m_iHp = 3;
	Bullets = CreateBullets(m_iMaxAmmo);		
}

Player::~Player()
{

}

Projectile * Player::CreateBullets(int a_iArraySize)
{
	Bullets = new Projectile[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Bullets[i] = Projectile();
		Bullets[i].Create("./images/Projectile.png");
	}

	return Bullets;
}

void Player::UpdatePlayer()
{
	m_iTimer++;

	Control();
	Move();
	Draw();

	for(int i = 0; i < m_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();

}

void Player::Draw()
{
	Sprite::Draw();
}

void Player::Move()
{
	Sprite::Move();
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

	if(IsKeyDown('T'))
		Shoot();
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

}


void Player::Reload()
{
	if(m_iAmmo <= 0)
		m_iAmmo = m_iMaxAmmo;
}







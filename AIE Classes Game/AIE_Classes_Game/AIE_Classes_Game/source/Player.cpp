#include "Player.h"

Vector2D a_playerPos(640, 390);
Vector2D a_playerSpd(0,0);
const int c_iPlayerWidth = 50;
const int c_iPlayerHeight = 50;
int iPlayerSpriteID = -1;
const int c_iMaxAmmo = 5;

Player::Player() : Sprite(a_playerPos, a_playerSpd, c_iPlayerWidth, c_iPlayerHeight, iPlayerSpriteID)
{
	Create("./images/GrayBox.png");
	m_iAmmo = c_iMaxAmmo;
	m_bShot = false;
	m_iTimer = 0;
	Bullets = CreateBullets(c_iMaxAmmo);		
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

	for(int i = 0; i < c_iMaxAmmo; i++)
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

	if(!Bullets[c_iMaxAmmo - m_iAmmo].GetAlive() && m_iTimer > 40)
	{
		Bullets[c_iMaxAmmo - m_iAmmo].SetAlive(true);
		Bullets[c_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
		Bullets[c_iMaxAmmo - m_iAmmo].SetSpeedY(-2);
		m_iAmmo--;
		m_iTimer = 0;
	}



}

void Player::Reload()
{
	if(m_iAmmo <= 0)
		m_iAmmo = 5;
}







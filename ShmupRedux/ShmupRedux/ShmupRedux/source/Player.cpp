#include "Player.h"
#include "Bullet.h"
#include "Missile.h"
#include "Laser.h"
#include "Aie.h"

typedef std::vector<Projectile*>::iterator ProjectileIterator;

//0,0 Vector
Vector2D c_v2DStill(0.0f, 0.0f);

// Anti-Magic Numbers
const int c_iPlayerWidth = 50;
const int c_iPlayerHeight = 50;
bool c_bPlayerAlive = true;
const int c_iPlayerMaxBullets = 8;
const int c_iPlayerMaxMissiles = 3;
const int c_iPlayerMaxLasers = 10;
const int c_iPlayerHp = 10;
Vector2D c_v2DInitPlayerPos(512, 384);

static char * scpCurrentWeapon = " Bullet ";

void Player::Init()
{
	SetTag("Player");
	SetHp(c_iPlayerHp);
	SetWidth(c_iPlayerWidth);
	SetHeight(c_iPlayerHeight);
	SetAlive(c_bPlayerAlive);
	SetPosition(c_v2DInitPlayerPos);
	SetSpriteID( CreateSprite( "./images/PlayerShip.png" , GetWidth(), GetHeight(), true));

	eCurrentWeapon = BULLET; //Start with standard Bullets

	m_iBulletTimer = 0;
	m_iMissileTimer = 0;
	m_iLaserTimer = 0;
	m_iBulletArrayPosition = c_iPlayerMaxBullets; // Currently Bullets should be [0] - [7]
	m_iMissileArrayPosition = m_iBulletArrayPosition + c_iPlayerMaxMissiles; // should be [8] - [10]
	m_iLaserArrayPosition = m_iMissileArrayPosition + c_iPlayerMaxLasers; // should be [11] -[21]
	m_iBulletAmmo = c_iPlayerMaxBullets;
	m_iMissileAmmo = c_iPlayerMaxMissiles;
	m_iLaserAmmo = c_iPlayerMaxLasers;

	//Bullets go in list first
	for(int i = c_iPlayerMaxBullets; i > 0; i--)
		 GetProjectiles().push_back(new Bullet);

	//Missiles next
	for(int i = m_iMissileArrayPosition; i > m_iBulletArrayPosition; i--)
		 GetProjectiles().push_back(new Missile);

	//Laser last
	for(int i = m_iLaserArrayPosition; i > m_iMissileArrayPosition; i--)
		 GetProjectiles().push_back(new Laser);

	//Init all owned Projectiles
	for(size_t i = 0; i < GetProjectiles().size(); i++ )
	{
		 GetProjectiles()[i]->Init();
	}
}

void Player::Update()
{
	if(GetAlive())
	{
		if(GetHp() <= 0)
			this->Die();

		m_iBulletTimer++;
		m_iMissileTimer++;
		m_iLaserTimer++;
		Entity::Move();
		Entity::Draw();
		Control();

		for(size_t i = 0; i < GetProjectiles().size(); i++  )
		{
			GetProjectiles()[i]->Update();
		}
	}
}

void Player::Fire(Projectile &ar_oActiveWeapon)
{
	ar_oActiveWeapon.Launch(*this);
}

void Player::WeaponManager()
{

	DrawString("Current Weapon:", 10, 50);
	DrawString(scpCurrentWeapon, 250, 50);

	if(GetMouseButtonDown(1))
	{
		if(eCurrentWeapon == BULLET)
		{
			
			if(m_iBulletTimer > 40)
			{
				Fire(* GetProjectiles()[m_iBulletArrayPosition - m_iBulletAmmo]);
				m_iBulletAmmo--;
				m_iBulletTimer = 0;
				if(m_iBulletAmmo == 0)
					m_iBulletAmmo = c_iPlayerMaxBullets;
			}
		}
		if(eCurrentWeapon == MISSILE)
		{
			if(m_iMissileTimer > 100)
			{
				Fire(* GetProjectiles()[m_iMissileArrayPosition - m_iMissileAmmo]);
				m_iMissileAmmo--;
				m_iMissileTimer = 0;
				if(m_iMissileAmmo == 0)
					m_iMissileAmmo = c_iPlayerMaxMissiles;
			}
		}
		if(eCurrentWeapon == LASER)
		{
			if(m_iLaserTimer > 100)
			{
				Fire(* GetProjectiles()[m_iLaserArrayPosition - m_iLaserAmmo]);
				m_iLaserAmmo--;
				m_iLaserTimer = 0;
				
				if(m_iLaserAmmo == 0)
					m_iLaserAmmo = c_iPlayerMaxLasers;
			}
		}
	}

	if(IsKeyDown('Z'))
	{
		eCurrentWeapon = BULLET;
		scpCurrentWeapon = " Bullet ";
	}
	if(IsKeyDown('X'))
	{
		eCurrentWeapon = MISSILE;
		scpCurrentWeapon = " Missile ";
	}
	if(IsKeyDown('C'))
	{
		eCurrentWeapon = LASER;
		scpCurrentWeapon = " Laser ";
	}

	
}

void Player::Control()
{
	WeaponManager();
	SetSpeed(c_v2DStill);

	if(IsKeyDown('A'))
		SetSpeedX(-1.0f);
	if(IsKeyDown('D'))
		SetSpeedX(1.0f);
	if(IsKeyDown('W'))
		SetSpeedY(-1.0f);
	if(IsKeyDown('S'))
		SetSpeedY(1.0f);

}

void Player::Die()
{
	SetAlive(false);
	SetPosition(-100, -100);
}

//void Player::HandleCollision(Projectile &a_roTarget)
//{
//	
//}
//
//
//void Player::HandleCollision(Entity &a_roTarget)
//{
//
//}
//

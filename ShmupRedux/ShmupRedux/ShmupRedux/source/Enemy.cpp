#include "Enemy.h"
#include "Bullet.h"
#include "Missile.h"
#include "Laser.h"
#include "Aie.h"

typedef std::vector<Projectile*>::iterator ProjectileIterator;
//0,0 Vector
//Vector2D c_v2DStill(0.0f, 0.0f);

// Anti-Magic Numbers
const int c_iEnemyWidth = 50;
const int c_iEnemyHeight = 50;
bool c_bEnemyAlive = true;
const int c_iEnemyMaxBullets = 8;
const int c_iEnemyMaxMissiles = 3;
const int c_iEnemyMaxLasers = 10;
const int c_iEnemyHp = 10;
Vector2D c_v2DInitEnemyPos(512, 50);


void Enemy::Init()
{
	SetTag("Enemy");
	SetHp(c_iEnemyHp);
	SetWidth(c_iEnemyWidth);
	SetHeight(c_iEnemyHeight);
	SetAlive(c_bEnemyAlive);
	SetPosition(c_v2DInitEnemyPos);
	SetSpriteID( CreateSprite( "./images/EnemyShip.png" , GetWidth(), GetHeight(), true));
	
	eCurrentWeapon = BULLET; //Start with standard Bullets

	m_iBulletTimer = 0;
	m_iBulletArrayPosition = c_iEnemyMaxBullets; // Currently Bullets should be [0] - [7]
	m_iBulletAmmo = c_iEnemyMaxBullets;

	//Bullets go in list first
	for(size_t i = c_iEnemyMaxBullets; i > 0; i--)
		 GetProjectiles().push_back(new Bullet);

	//Init all owned Projectiles
	for(size_t i = 0; i <  GetProjectiles().size(); ++i)
	{
		 GetProjectiles()[i]->Init();
	}
}

void Enemy::Update()
{
	if(GetAlive())
	{
		if(GetHp() <= 0)
			this->Die();

		Entity::Move();
		Entity::Draw();
		m_iBulletTimer++;
		AI();

		for(size_t i = 0; i < GetProjectiles().size(); ++i)
			 GetProjectiles()[i]->Update();
	}
}

void Enemy::Fire(Projectile &ar_oActiveWeapon)
{
	ar_oActiveWeapon.Launch(*this);
}



void Enemy::AI()
{

}

void Enemy::Die()
{
	SetAlive(false);
	SetPosition(-100, -100);
}

//void Enemy::HandleCollision(Projectile &a_roTarget)
//{
//	if(a_roTarget.GetTag() == "Bullet" || a_roTarget.GetTag() == "Missile" || a_roTarget.GetTag() == "Laser" )
//	{
//		if(CheckBoxCollision(a_roTarget))
//		{
//			this->Die();
//		}
//	}
//}
//
//
//void Enemy::HandleCollision(Entity &a_roTarget)
//{
//	
//}


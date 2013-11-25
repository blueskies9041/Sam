#include "Enemy.h"


Vector2D a_EnemyPos(840, 390);
Vector2D a_EnemySpd(0,0);
const int c_iEnemyWidth = 50;
const int c_iEnemyHeight = 50;
int iEnemySpriteID = -1;
const int c_iMaxAmmo = 2;

//== CONSTRUCTOR == //
Enemy::Enemy() : Sprite(a_EnemyPos, a_EnemySpd, c_iEnemyWidth, c_iEnemyHeight, iEnemySpriteID)
{
	Create("./images/GrayBox.png");
	m_iAmmo = c_iMaxAmmo;
	m_iTimer = 0;
	m_bShot = false;
	m_bSpawned = false;
	Bullets = CreateBullets(c_iMaxAmmo);		
}

//== DECON == //
Enemy::~Enemy()
{

}

//== MEMBER FUNCS == //

Projectile * Enemy::CreateBullets(int a_iArraySize)
{
	Bullets = new Projectile[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Bullets[i] = Projectile();
		Bullets[i].Create("./images/Projectile.png");
	}

	return Bullets;
}

void Enemy::Draw()
{
	Sprite::Draw();
}

void Enemy::Move()
{
	Sprite::Move();
}


void Enemy::Shoot()
{
	Reload();

	if(!Bullets[c_iMaxAmmo - m_iAmmo].GetAlive() && m_iTimer > 40)
	{
		Bullets[c_iMaxAmmo - m_iAmmo].SetAlive(true);
		Bullets[c_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
		Bullets[c_iMaxAmmo - m_iAmmo].SetSpeedY(2);
		m_iAmmo--;
		m_iTimer = 0;
	}	
}

void Enemy::Reload()
{
	if(m_iAmmo <= 0)
		m_iAmmo = c_iMaxAmmo;
}

void Enemy::AI(Sprite &a_PlayerOne)
{
	if(m_bSpawned)
	{
		//If Player is between left and right x boundaries of enemy sprite
		if(a_PlayerOne.GetPositionX() > GetPositionX() - GetWidth() / 2 && a_PlayerOne.GetPositionX() < GetPositionX() + GetWidth() / 2 
			&& a_PlayerOne.GetPositionY() > GetPositionY())
		Shoot();

		//SetSpeedX(cos(m_iMoveTimer));
		if(GetPositionX() < a_PlayerOne.GetPositionX())
			SetSpeedX(.2f);
		if(GetPositionX() > a_PlayerOne.GetPositionX())
			SetSpeedX(-.2f);
	}
}
	
void Enemy::UpdateEnemy(Sprite &a_PlayerOne)
{
	m_iTimer++;
	m_iMoveTimer += 1.0f;

	AI(a_PlayerOne);
	Move();
	Draw();

	for(int i = 0; i < c_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();

}




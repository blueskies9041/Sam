#include "Enemy.h"

Vector2D a_EnemyPos(-100, -100);
Vector2D a_EnemySpd(0,0);
const int c_iEnemyWidth = 50;
const int c_iEnemyHeight = 50;
int iEnemySpriteID = -1;

//== CONSTRUCTOR == //
Enemy::Enemy()
{
	SetPosition(a_EnemyPos);
	SetSpeed(a_EnemySpd);
	SetWidth(c_iEnemyWidth);
	SetHeight(c_iEnemyHeight);
	SetSpriteID(iEnemySpriteID);

	Create("./images/GrayBox.png");
	m_iMaxAmmo = 2;
	m_iAmmo = m_iMaxAmmo;
	m_iMoveTimer = 0.0f;
	m_iTimer = 0;
	m_bShot = false;
	m_bSpawned = false;
	m_iHp = 1;
	Bullets = CreateBullets(m_iMaxAmmo);		
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

	if(!Bullets[m_iMaxAmmo - m_iAmmo].GetAlive() && m_iTimer > 40)
	{
		Bullets[m_iMaxAmmo - m_iAmmo].SetAlive(true);
		Bullets[m_iMaxAmmo - m_iAmmo].SetPosition(GetPosition());
		Bullets[m_iMaxAmmo - m_iAmmo].SetSpeedY(2);
		m_iAmmo--;
		m_iTimer = 0;
	}	
}

void Enemy::Reload()
{
	if(m_iAmmo <= 0)
		m_iAmmo = m_iMaxAmmo;
}

void Enemy::AI(Sprite &a_PlayerOne)
{
	if(m_bSpawned)
	{
		//If Player is between left and right x boundaries of enemy sprite
		if(a_PlayerOne.GetPositionX() > GetPositionX() - GetWidth() / 2 && a_PlayerOne.GetPositionX() < GetPositionX() + GetWidth() / 2 
			&& a_PlayerOne.GetPositionY() > GetPositionY())
		Shoot();

		SetSpeedX(cos(m_iMoveTimer));
		SetSpeedY(.2f);
		
	}
	else
	{
		SetPosition(a_EnemyPos);
		SetSpeed(a_EnemySpd);
	}

}
	
void Enemy::UpdateEnemy(Sprite &a_PlayerOne)
{
	m_iTimer++;
	m_iMoveTimer += .01f;

	AI(a_PlayerOne);
	Move();
	Draw();

	for(int i = 0; i < m_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();

	if(m_iHp <= 0)
		SetSpawned(false);

}




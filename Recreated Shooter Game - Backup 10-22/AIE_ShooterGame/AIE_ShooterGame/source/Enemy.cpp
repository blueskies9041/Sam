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
	m_bDead = false;
	m_bSpawned = false;
	m_iHp = 1;
	CreateBullets(m_iMaxAmmo);		
}

//== DECON == //
Enemy::~Enemy()
{

}

//== MEMBER FUNCS == //

void Enemy::CreateBullets(int a_iArraySize)
{
	Bullets = new Projectile[a_iArraySize];

	for(int i = 0; i < a_iArraySize; i++)
	{
		Bullets[i] = Projectile();
		Bullets[i].Create("./images/Projectile.png");
	}
}

void Enemy::Draw()
{
	if(GetSpawned())
		Sprite::Draw();
}

void Enemy::Move()
{
	if(GetSpawned())
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

}
	
void Enemy::UpdateEnemy(Sprite &a_PlayerOne)
{
	if(m_iHp <= 0)
	{
		SetSpawned(false);
		SetDead(true);
		m_iHp = 1;
	}

	if(GetPositionY() > 820 || GetPositionX() < 0)
		SetSpawned(false);

	if(GetPositionY() > 820)
		SetDead(true);
	
	if(!m_bSpawned)
	{
		SetPosition(a_EnemyPos);
		SetSpeed(a_EnemySpd);
	}

	m_iTimer++;
	m_iMoveTimer += .01f;
	AI(a_PlayerOne);
	Move();
	Draw();


	for(int i = 0; i < m_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();
}



void Enemy::DebugEnemy()
{
	
}
		
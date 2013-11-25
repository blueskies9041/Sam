#include "Enemy.h"

Vector2D a_EnemyPos(-100, 390);
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

	Create("./images/EnemyShip.png");
	m_iMaxAmmo = 2;
	m_iAmmo = m_iMaxAmmo;
	m_iMoveTimer = 0.0f;
	m_iTimer = 0;
	m_bSpawned = false;
	SetAlive(false);
	m_iHp = 2;
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
	}
}

void Enemy::Draw()
{
	if(GetAlive())
		Sprite::Draw();
}

void Enemy::Move()
{	
	if(GetAlive())
		Sprite::Move();
}


void Enemy::Shoot()
{
	Reload();

	if(m_iTimer > 40)
	{
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
	if(GetAlive())
	{
		//If Player is between left and right x boundaries of enemy sprite
		if(a_PlayerOne.GetPositionX() > GetPositionX() - GetWidth() / 2 && a_PlayerOne.GetPositionX() < GetPositionX() + GetWidth() / 2 
			&& a_PlayerOne.GetPositionY() > GetPositionY())
		Shoot();

		

		SetSpeedX(0);
		SetSpeedY(1.0f);

	}

}
	
void Enemy::UpdateEnemy(Sprite &a_PlayerOne)
{

	m_iMoveTimer += .01f;
	m_iTimer++;

	UpdateAlive();
	
	if(!GetAlive())
	{
		SetPosition(a_EnemyPos);
		SetSpeed(a_EnemySpd);
	}

	AI(a_PlayerOne);
	Move();
	Draw();

	for(int i = 0; i < m_iMaxAmmo; i++)
		Bullets[i].UpdateProjectile();
}

void Enemy::UpdateAlive()
{
	if(GetPositionX() > 0 && !OffScreenY() )
		SetAlive(true);
	if(m_iHp <= 0)
		SetAlive(false);
	if(GetPositionX() < 0 || GetPositionY() > 750)
		SetAlive(false);
	
}

void Enemy::DebugEnemy()
{

}
		
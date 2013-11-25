#include "Projectile.h"

Vector2D a_initialPos( 5, 5);
Vector2D a_initialSpeed(0,0);
const int a_iWidth = 15;
const int a_iHeight = 15;
unsigned int a_uiSpriteID = -1;

Projectile::Projectile() 
{
	SetPosition(a_initialPos);
	SetSpeed(a_initialSpeed);
	SetWidth(a_iWidth);
	SetHeight(a_iHeight);
	SetSpriteID(a_uiSpriteID);
	m_bAlive = false;
}

Projectile::~Projectile()
{

}

void Projectile::Draw()
{
	if(GetAlive())
		Sprite::Draw();
}

void Projectile::Move()
{
	if(GetAlive())
		Sprite::Move();	
}
	
void Projectile::UpdateProjectile()
{
	Move();
	Draw();

	if(GetPositionY() < 0 || GetPositionY() > 780)
	{
		SetAlive(false);
		SetPosition(a_initialPos);
		SetSpeed(a_initialSpeed);
	}

}


#include "Projectile.h"

Vector2D a_initialPos( 5, 5);
Vector2D a_initialSpeed(0,0);
const int a_iWidth = 15;
const int a_iHeight = 15;
unsigned int a_uiSpriteID = -1;

//Using an initializer list for the sake of understanding one.
Projectile::Projectile() : Sprite(a_initialPos, a_initialSpeed, a_iWidth, a_iHeight, a_uiSpriteID)
{
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


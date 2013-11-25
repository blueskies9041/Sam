#include "Projectile.h"

Vector2D a_initialPos( -100, 200 );
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
	SetAlive(false);
	Create("./images/NewProjectile.png");
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
	
	UpdateAlive();

	if(!GetAlive())
	{
		SetPosition(a_initialPos);
		SetSpeed(a_initialSpeed);
	}

	Move();
	Draw();
}

void Projectile::UpdateAlive()
{
	if(GetPositionX() > 0 || !OffScreenY() )
		SetAlive(true);
	if(GetPositionX() < 0 || OffScreenY())
		SetAlive(false);
	
}

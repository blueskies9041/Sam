#include "Bullet.h"
#include "Aie.h"

Vector2D c_v2DBulletSpeed(0, -2);
Vector2D c_v2DBulletDimensions(30, 30);

const int c_iBulletDamage = 1;


void Bullet::Init()
{
	SetTag("Bullet");
	SetDamage(c_iBulletDamage);
	SetAlive(true);
	SetWidth(c_v2DBulletDimensions.GetX());
	SetHeight(c_v2DBulletDimensions.GetY());
	SetSpriteID( CreateSprite("./images/Bullet.png", c_v2DBulletDimensions.GetX(), c_v2DBulletDimensions.GetY(), true));
}

void Bullet::Launch(Entity &ar_oSource)
{
	SetAlive(true);
	SetPosition(ar_oSource.GetPosition());
	SetSpeed(c_v2DBulletSpeed);
}

void Bullet::Update()
{
	if(GetAlive())
	{
		Entity::Move();
		Entity::Draw();
	}
}

void Bullet::Move()
{
}

void Bullet::Draw()
{
}

void Bullet::Die()
{
	SetAlive(false);
	SetPosition(-100, -100);
}

//void Bullet::HandleCollision(Entity &a_roTarget)
//{
//
//}


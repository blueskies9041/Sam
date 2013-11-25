#include "Missile.h"
#include "Aie.h"

Vector2D c_v2DMissileSpeed(0, -1);
Vector2D c_v2DMissileDimensions(27, 37);

void Missile::Init()
{
	SetAlive(true);
	SetSpriteID( CreateSprite("./images/Missile.png", c_v2DMissileDimensions.GetX(), c_v2DMissileDimensions.GetY(), true));
}

void Missile::Launch(Entity &ar_oSource)
{
	SetPosition(ar_oSource.GetPosition());
	SetSpeed(c_v2DMissileSpeed);
}

void Missile::Update()
{
	if(GetAlive())
	{
		Entity::Move();
		Entity::Draw();
	}
}

void Missile::Move()
{
}

void Missile::Draw()
{
}

void Missile::Die()
{
}

void Missile::Launch()
{
}

void Missile::HandleCollision(Entity &a_roTarget)
{

}
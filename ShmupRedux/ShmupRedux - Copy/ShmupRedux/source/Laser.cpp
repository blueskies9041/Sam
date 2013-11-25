#include "Laser.h"
#include "Aie.h"

Vector2D c_v2DLaserSpeed(0, -5);
Vector2D c_v2DLaserDimensions(30, 30);

void Laser::Init()
{
	SetAlive(true);
	SetSpriteID( CreateSprite("./images/Laser.png", c_v2DLaserDimensions.GetX(), c_v2DLaserDimensions.GetY(), true));
}

void Laser::Launch(Entity &ar_oSource)
{
	SetPosition(ar_oSource.GetPosition());
	SetSpeed(c_v2DLaserSpeed);
}

void Laser::Update()
{
	if(GetAlive())
	{
		Entity::Move();
		Entity::Draw();
	}
}

void Laser::Move()
{
}

void Laser::Draw()
{
}

void Laser::Die()
{
}

void Laser::Launch()
{
}

void Laser::HandleCollision(Entity &a_roTarget)
{
}
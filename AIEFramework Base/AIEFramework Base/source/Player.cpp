#include "Player.h"

Vector2D initPos = {840, 526};
Vector2D initSpd = {0,0};

Player::Player() : gameObject(initPos, initSpd, 100, 100, -1, "./images/Player.png")
{

}

Player::~Player()
{
}

void Player::HandleInput()
{
	//Allows player movement.

	Vector2D speed = getSpeed();

	speed.x = 0;
	speed.y = 0;

	if(IsKeyDown('A'))
	{
		speed.x = -1;
	}

	if(IsKeyDown('D'))
	{
		speed.x = 1;
	}

	if(IsKeyDown('W'))
	{
		speed.y = -1;
	}

	if(IsKeyDown('S'))
	{
		speed.y = 1;
	}

	setSpeed(speed);
}

void Player::Die()
{

}

bool Projectile::getFired()
{
	return fired;
}

void Projectile::setFired(bool itsFired)
{
	fired = itsFired;
}


void Player::Shoot(gameObject &newBullet)
{		
	/*Projectile * newBullet = createBullet();

	Vector2D newSpeed = {0,-1};
	Vector2D position = newBullet.getPosition();
	newBullet.setSpeed(newSpeed);	
	Move(newBullet);
	DrawSprite(newBullet.getSprite());	*/
}
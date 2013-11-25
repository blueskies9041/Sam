#define _CRT_SECURE_NO_WARNINGS // so sprintf won't flag a warning
#include "Prototypes.h"
#include <iostream>
#include <ctime>
#include <vector>

void fireBullets(Projectile * Bullets, int arraySize, gameObject source)
{
	
}

void Move(gameObject &objectToMove)
{
	int sprite = objectToMove.getSprite();
	Vector2D position = objectToMove.getPosition();
	Vector2D speed = objectToMove.getSpeed();

	position.x += speed.x;
	position.y += speed.y;

	objectToMove.setSpeed(speed);
	objectToMove.setPosition(position);

	MoveSprite(sprite, position.x, position.y);
}

#define _CRT_SECURE_NO_WARNINGS // so sprintf won't flag a warning
#include "Prototypes.h"
#include <iostream>
#include <ctime>
#include <vector>

gameObject::gameObject(float posX, float posY, float spdX, float spdY, int width, int height, int sprite, char * filepath)
{
	setPositionX(posX);
	setPositionY(posY);
	setSpeedX(spdX);
	setSpeedY(spdY);
	setWidth(width);
	setHeight(height);
	setSprite(sprite);
	Create(filepath);
}

gameObject::~gameObject()
{
	//DestroySprite(sprite);
}
	//getters
float gameObject::getSpeedX() { return speed.x; }
float gameObject::getSpeedY() { return speed.y; }
float gameObject::getPositionX() { return position.x; }
float gameObject::getPositionY() { return position.y; }
int gameObject::getWidth() { return width; }
int gameObject::getHeight() { return height; } 
int gameObject::getSprite() { return spriteID; }
		
	//setters
void gameObject::setSpeedX(float itsSpeedX) {speed.x = itsSpeedX;}
void gameObject::setSpeedY(float itsSpeedY) {speed.y = itsSpeedY;}
void gameObject::setPositionX(float itsPositionX) {position.x = itsPositionX;}
void gameObject::setPositionY(float itsPositionY) {position.y = itsPositionY;}
void gameObject::setWidth(int itsWidth) {width = itsWidth;}
void gameObject::setHeight(int itsHeight) {height = itsHeight;}
void gameObject::setSprite(int itsSprite) {spriteID = itsSprite;} 

//gameObject access

int gameObject::Create(char * fileName)
{
	int sprite = CreateSprite(fileName, getWidth(), getHeight(), true);
	setSprite(sprite);
	return getSprite();
}

void gameObject::Draw()
{	
	int SpriteID = getSprite();
	DrawSprite(SpriteID);
}

void gameObject::Move()
{
	int spriteID = getSprite();
	Vector2D speed = { getSpeedX(), getSpeedY() };
	Vector2D position = { getPositionX(), getPositionY() };

	position.x += speed.x;
	position.y += speed.y;

	MoveSprite(spriteID, position.x, position.y);
}

Player::Player() : gameObject( 840, 625, 0 , 0 , 100, 100, -1, "./images/Player.png")
{
}

Player::~Player()
{
}

void Player::Control()
{
	Vector2D speed = { getSpeedX(), getSpeedY() };

	speed.x = 0;
	speed.y = 0;

	if(IsKeyDown('A'))
		speed.x = -1;
	if(IsKeyDown('D'))
		speed.x = 1;
	if(IsKeyDown('W'))
		speed.y = -1;
	if(IsKeyDown('S'))
		speed.y = 1;

	setSpeedX(speed.x);
	setSpeedY(speed.y);
}

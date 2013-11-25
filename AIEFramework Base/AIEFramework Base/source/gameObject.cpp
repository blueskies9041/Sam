#include "gameObject.h"

Vector2D gameObject::getSpeed()
{
	return speed;
}

Vector2D gameObject::getPosition()
{
	return position;
}

int gameObject::getWidth()
{
	return width;
}

int gameObject::getHeight()
{
	return height;
}

int gameObject::getSprite()
{
	return spriteID;
}

void gameObject::setSpeed(Vector2D itsSpeed)
{
	speed = itsSpeed;
}

void gameObject::setPosition(Vector2D itsPosition)
{
	position = itsPosition;
}

void gameObject::setWidth(int itsWidth)
{
	width = itsWidth;
}

void gameObject::setHeight(int itsHeight)
{
	height = itsHeight;
}

void gameObject::setSprite(int itsSprite)
{
	spriteID = itsSprite;
} //ACCESS

gameObject::gameObject(Vector2D position, Vector2D speed, int width, int height, int spriteID, char * filepath)
{
	setPosition(position);
	setSpeed(speed);
	setWidth(width);
	setHeight(height);
	setSprite(spriteID);
	Create(filepath);
}

gameObject::~gameObject()
{

}


//gameObject cons/decons

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
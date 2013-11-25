#define _CRT_SECURE_NO_WARNINGS
#include "AIE.h"
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

struct Vector2D
{
	float x, y;
};

class gameObject : public Vector2D
{
	private:
		//members

		Vector2D speed;
		Vector2D position;
		int width;
		int height;
		int spriteID;

	public:
		//member functions

		gameObject(Vector2D position, Vector2D speed, int width, int height, int spriteID, char * filepath);
		~gameObject();
		int Create(char * fileName);
		void Draw();

		//getters
		Vector2D getSpeed();
		Vector2D getPosition();
		int getWidth();
		int getHeight();
		int getSprite();
		
		//setters
		void setSpeed(Vector2D itsSpeed);
		void setPosition(Vector2D itsPosition);
		void setWidth(int itsWidth);
		void setHeight(int itsHeight);
		void setSprite(int itsSprite);
		
};

#endif
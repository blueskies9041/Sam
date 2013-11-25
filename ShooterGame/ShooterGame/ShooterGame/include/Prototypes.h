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

		gameObject(float posX, float posY, float spdX, float spdY, int width, int height, int sprite, char * filepath);
		~gameObject();
		int Create(char * fileName);
		void Draw();
		void Move();

		//getters
		float getSpeedX();
		float getSpeedY();
		float getPositionX();
		float getPositionY();
		int getWidth();
		int getHeight();
		int getSprite();
		
		//setters
		void setSpeedX(float itsSpeedX);
		void setSpeedY(float itsSpeedY);
		void setPositionX(float itsPositionX);
		void setPositionY(float itsPositionY);
		void setWidth(int itsWidth);
		void setHeight(int itsHeight);
		void setSprite(int itsSprite);
		
};



class Player : public gameObject
{
private:

public:
	Player(); 
	~Player();

	void Control();
	  

};

#endif
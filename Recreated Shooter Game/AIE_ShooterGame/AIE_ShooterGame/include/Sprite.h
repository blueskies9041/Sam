//////////////////////////////////////////////////////////// 
// File: Sprite.h
// Author: Sam Legus	 
// Date Created: 10/1/2013
// Brief: Header for Sprite.cpp, which defines the Sprite class.
////////////////////////////////////////////////////////////

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "AIE.h"
#include "Vector2D.h"
#include <cmath>

class Sprite 
{
	private:

		//tracking 
		Vector2D m_position;
		Vector2D m_speed;
		
		//sprite dimensions
		int m_iWidth;
		int m_iHeight;
		//spriteID for openGL purposes
		int m_iSpriteID;

		//alive flag controls different types of sprite's abilities to be drawn or moved
		bool m_bAlive;

	public:

		//C & DC
		Sprite(Vector2D &a_pos, Vector2D &a_speed, int a_iWidth, int a_iHeight, int a_iSpriteID);
		Sprite();
		~Sprite();

		//Member Functions

	/*	FUNCTION: Create()
		ARGUMENTS: char * a_cpFilename
		BRIEF: Calls create sprite using the filepath provided as an argument and the member variables of the sprite class.
		RETURN: void */
		void Create(char * a_cpFilename);
		//void Create(char * a_cpFilename, bool a_bDrawFromCenter);
	/*	FUNCTION: Draw()
		BRIEF: Calls DrawSprite() using the member variables of the sprite class.
		RETURN: void */
		void Draw();
	/*	FUNCTION: Move()
		BRIEF: Calls MoveSprite() using the member variables of the sprite class.
		RETURN: void */
		void Move();
	/*	FUNCTION: CheckBoxCollision()
		ARGUMENTS: Sprite &a_Collidee
		BRIEF: Bounding box collision check. Returns true on collision, false otherwise.
		RETURN: bool */
		bool CheckBoxCollision(Sprite &a_Collidee);
	/*	FUNCTION: OffScreenX()
		BRIEF: Tests x boundaries. If sprite exceeds screen's x bounds return true, otherwise return false.
		RETURN: bool */
		bool OffScreenX();
	/*	FUNCTION: OffScrenY()
		BRIEF: Tests xyboundaries. If sprite exceeds screen's y bounds return true, otherwise return false.
		RETURN: bool */
		bool OffScreenY();
	/*	FUNCTION: *virtual* UpdateAlive()
		BRIEF: To be re-defined in Sprite, Enemy, and Projectile in their respective cpps.
		RETURN: void */
		virtual void UpdateAlive() { }
		
	/*	FUNCTIONS: INLINE ACCESS FUNCTIONS
		BRIEF: Getters and Setters for member variables of Sprite class. */
		Vector2D GetPosition() { return m_position; } 
		float GetPositionX() { return m_position.GetX();}
		float GetPositionY() { return m_position.GetY();}

		Vector2D GetSpeed() { return m_speed; }
		float GetSpeedX() { return m_speed.GetX(); }
		float GetSpeedY() { return m_speed.GetY(); }

		int GetWidth() { return m_iWidth; }
		int GetHeight() { return m_iHeight; }
		int GetSpriteID() { return m_iSpriteID; }
		
		void SetPosition(Vector2D &a_itsPosition) { m_position = a_itsPosition ;}
		void SetPosition(float a_fItsPositionX, float a_fItsPositionY) {m_position.SetX(a_fItsPositionX) ; m_position.SetY(a_fItsPositionY); }
		void SetPositionX(float a_fItsPositionX) { m_position.SetX(a_fItsPositionX) ;}
		void SetPositionY(float a_fItsPositionY) { m_position.SetY(a_fItsPositionY) ;}

		void SetSpeed(Vector2D &a_itsSpeed) { m_speed = a_itsSpeed; }
		void SetSpeed(float a_fItsSpeedX, float a_fItsSpeedY) {m_speed.SetX(a_fItsSpeedX) ; m_speed.SetY(a_fItsSpeedY); }
		void SetSpeedX(float a_fItsSpeedX) { m_speed.SetX(a_fItsSpeedX) ;}
		void SetSpeedY(float a_fItsSpeedY) { m_speed.SetY(a_fItsSpeedY) ;}

		void SetWidth(int a_iItsSpeed) { m_iWidth = a_iItsSpeed; }
		void SetHeight(int a_iItsHeight) { m_iHeight = a_iItsHeight; }
		void SetSpriteID(int a_iItsSpriteID) { m_iSpriteID = a_iItsSpriteID; }

		inline bool GetAlive() { return m_bAlive; }
		inline void SetAlive(bool a_bSetAliveStatus) { m_bAlive = a_bSetAliveStatus; }
};

#endif
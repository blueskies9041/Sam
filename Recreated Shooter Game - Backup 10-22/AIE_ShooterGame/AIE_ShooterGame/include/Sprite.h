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

	public:

		//C & DC
		Sprite(Vector2D &a_pos, Vector2D &a_speed, int a_iWidth, int a_iHeight, int a_iSpriteID);
		Sprite();
		~Sprite();

		//Member Functions
		void Create(char * a_cpFilename);
		void Create(char * a_cpFilename, bool a_bDrawFromCenter);
		void Draw();
		void Move();
		bool CheckBoxCollision(Sprite &a_Collidee);
		bool OffScreenX();
		bool OffScreenY();
		

		//Getters and Setters (inline definitions)
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

		
};

#endif
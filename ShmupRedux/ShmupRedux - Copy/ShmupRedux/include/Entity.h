#ifndef _ENTITY_H_
#define _ENTITY_H_

/* Abstract Class */

#include "AIE.h"
#include "Vector2D.h"
#include <math.h>


class Entity
{
public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Die() = 0;
	virtual void HandleCollision(Entity &a_roTarget) = 0;

	/*Getters and Setters*/
	inline void SetAlive(bool a_bAlive) { m_bAlive = a_bAlive; }
	inline void SetPosition(Vector2D a_v2DPosition) { m_v2DPosition = a_v2DPosition; }
	inline void SetPosition(float a_fPosX, float a_fPosY) { m_v2DPosition.SetX(a_fPosX) ; m_v2DPosition.SetY(a_fPosY) ; }
	inline void SetSpeed(Vector2D a_v2DSpeed) { m_v2DSpeed = a_v2DSpeed; }
	inline void SetSpeedX(float a_fSpeedX) { m_v2DSpeed.SetX(a_fSpeedX) ; }
	inline void SetSpeedY(float a_fSpeedY) { m_v2DSpeed.SetY(a_fSpeedY) ; }
	inline void SetTag(char * a_cpTag) { m_cpTag = a_cpTag; }

	inline bool GetAlive() { return m_bAlive; }
	inline Vector2D GetPosition() { return m_v2DPosition; }
	inline float GetPositionY() { return m_v2DPosition.GetY(); }
	inline float GetPositionX() { return m_v2DPosition.GetX(); }
	inline Vector2D GetSpeed() { return m_v2DSpeed; }

	inline void SetSpriteID(unsigned int a_uiSpriteID) { m_uiSpriteID = a_uiSpriteID; }
	inline void SetWidth(int a_iWidth) { m_iWidth = a_iWidth; }
	inline void SetHeight(int a_iHeight) { m_iHeight = a_iHeight; }
	inline unsigned int GetSpriteID() { return m_uiSpriteID; }
	inline int GetWidth() { return m_iWidth; }
	inline int GetHeight() { return m_iHeight; }
	inline char * GetTag() { return m_cpTag; }

private:

	bool m_bAlive;
	Vector2D m_v2DSpeed;
	Vector2D m_v2DPosition;
	unsigned int m_uiSpriteID;
	int m_iWidth;
	int m_iHeight;
	char *  m_cpTag;
	
};

#endif
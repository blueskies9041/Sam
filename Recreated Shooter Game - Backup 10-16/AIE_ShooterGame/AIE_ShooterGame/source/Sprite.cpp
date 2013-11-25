#include "Sprite.h"

// ***CONSTRUCTOR(S)*** //
Sprite::Sprite(Vector2D &a_pos, Vector2D &a_speed, int a_iWidth, int a_iHeight, int a_iSpriteID) :
	m_position(a_pos), 
	m_speed(a_speed), 
	m_iWidth(a_iWidth), 
	m_iHeight(a_iHeight), 
	m_iSpriteID(a_iSpriteID)
{ }

Sprite::Sprite()
{ }

// ***DECONSTRUCTOR*** //
Sprite::~Sprite()
{ }

// **MEMBER FUNCTIONS** //

void Sprite::Create(char * a_cpFilename)
{
	m_iSpriteID = CreateSprite(a_cpFilename, GetWidth(), GetHeight(), true);	
}

void Sprite::Draw()
{
	DrawSprite(m_iSpriteID);
}

void Sprite::Move()
{
	Vector2D oNewPosition(m_position.GetX() + m_speed.GetX(), m_position.GetY() + m_speed.GetY());
	SetPosition(oNewPosition);

	MoveSprite(m_iSpriteID, m_position.GetX(), m_position.GetY() );
}

bool Sprite::CheckBoxCollision(Sprite &a_Collidee)
{
	Vector2D BoxOnePos(m_position);
	Vector2D BoxTwoPos(a_Collidee.m_position);

	return (abs(BoxOnePos.GetX() - BoxTwoPos.GetX()) * 2) < (m_iWidth + a_Collidee.m_iWidth)
		&& (abs(BoxOnePos.GetY() - BoxTwoPos.GetY()) * 2) < (m_iHeight + a_Collidee.m_iHeight);
}
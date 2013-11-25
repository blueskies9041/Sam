#include "Entity.h"
#include "Aie.h"

void Entity::Move()
{
	SetPosition(m_v2DPosition + m_v2DSpeed);
	MoveSprite(GetSpriteID(), m_v2DPosition.GetX() + m_v2DSpeed.GetX(), m_v2DPosition.GetY() + m_v2DPosition.GetY() );
}

void Entity::Draw()
{
	DrawSprite(GetSpriteID());
}


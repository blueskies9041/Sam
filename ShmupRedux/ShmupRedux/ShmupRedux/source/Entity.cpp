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

bool Entity::CheckBoxCollision(Entity &a_roTarget)
{
	Vector2D BoxOnePos(m_v2DPosition);
	Vector2D BoxTwoPos(a_roTarget.m_v2DPosition);

	return (abs(BoxOnePos.GetX() - BoxTwoPos.GetX()) * 2) < (m_iWidth + a_roTarget.m_iWidth)
		&& (abs(BoxOnePos.GetY() - BoxTwoPos.GetY()) * 2) < (m_iHeight + a_roTarget.m_iHeight);
}
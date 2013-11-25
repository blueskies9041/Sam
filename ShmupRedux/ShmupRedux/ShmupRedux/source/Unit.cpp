#include "Unit.h"
#include "Aie.h"

void Unit::Move()
{
	SetPosition(GetPosition() + GetSpeed());
	MoveSprite(GetSpriteID(), GetPosition().GetX() + GetSpeed().GetX(), GetPosition().GetY() + GetSpeed().GetY() );
}

void Unit::Draw()
{
	DrawSprite(GetSpriteID());
}
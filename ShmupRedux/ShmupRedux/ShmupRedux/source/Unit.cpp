#include "Unit.h"
#include "Aie.h"
#include "Projectile.h"

void Unit::Move()
{
	SetPosition(GetPosition() + GetSpeed());
	MoveSprite(GetSpriteID(), GetPosition().GetX() + GetSpeed().GetX(), GetPosition().GetY() + GetSpeed().GetY() );
}

void Unit::Draw()
{
	DrawSprite(GetSpriteID());
}

void Unit::HandleCollision(Projectile &a_roTarget)
{
	if(CheckBoxCollision(a_roTarget))
	{
		SetHp( GetHp() - a_roTarget.GetDamage() );
		a_roTarget.Die();
	}
}
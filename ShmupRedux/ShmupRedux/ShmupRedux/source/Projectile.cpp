#include "Projectile.h"
#include "Aie.h"
#include "Unit.h"

// Might not need this
void Projectile::HandleCollision(Unit &a_roTarget)
{
	if(CheckBoxCollision(a_roTarget))
		this->Die();
}
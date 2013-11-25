#ifndef _ENEMY_H_
#define _ENEMY_H

#include "AIE.h"
#include "Unit.h"
#include <vector>

class Enemy : public Unit
{
public:

	void Init();
	void Fire(Projectile &ar_oActiveWeapon);
	void Update();
	void AI();
	void Die();
	void HandleCollision(Entity &a_roTarget);

private:

	WEAPON_TYPE eCurrentWeapon; //Current Active Weapon
	int m_iBulletTimer; //Delay manager for standard bullets
	int m_iBulletArrayPosition; //Standard ammo's position in Projectile Vector
	int m_iBulletAmmo; //Determines next bullet to be fired out of Projectile Array
};

#endif
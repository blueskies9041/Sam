#ifndef _PLAYER_H_
#define _PLAYER_H

#include "AIE.h"
#include "Unit.h"


class Projectile;



class Player : public Unit
{
public:

	void Init();
	void Fire(Projectile &ar_oActiveWeapon);
	void WeaponManager();
	void Update();
	void Control();
	void Die();
	//void HandleCollision(Projectile &a_roTarget);
	void HandleCollision(Entity &a_roTarget);
	

private:

	WEAPON_TYPE eCurrentWeapon; //Current Active Weapon
	int m_iBulletTimer; //Delay manager for standard bullets
	int m_iBulletArrayPosition; //Standard ammo's position in Projectile Vector
	int m_iBulletAmmo; //Determines next bullet to be fired out of Projectile Array
	
	int m_iMissileTimer;
	int m_iMissileArrayPosition;
	int m_iMissileAmmo;

	int m_iLaserTimer;
	int m_iLaserArrayPosition;
	int m_iLaserAmmo;

};

#endif
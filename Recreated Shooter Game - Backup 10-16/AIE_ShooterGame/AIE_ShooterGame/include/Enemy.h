#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "AIE.h"
#include "Sprite.h"
#include "Projectile.h"
#include <cmath>

class Enemy : public Sprite
{
private:

	int m_iAmmo;
	int m_iTimer;
	int m_iMaxAmmo;
	int m_iHp;
	float m_iMoveTimer;
	bool m_bShot;
	bool m_bSpawned;

	Projectile * Bullets;

public:

	Enemy();
	~Enemy();

	Projectile * CreateBullets(int a_iArraySize);

	void Draw();
	void Move();
	void Shoot();
	
	void Reload();
	void AI(Sprite &a_PlayerOne);
	void UpdateEnemy(Sprite &a_PlayerOne);

	//Getters and Setters, inline defs
	int GetAmmo() { return m_iAmmo; }
	int GetMaxAmmo() { return m_iMaxAmmo; }
	int GetTimer() { return m_iTimer; }
	int GetHp() { return m_iHp; }
	bool GetShot() { return m_bShot; }
	bool GetSpawned() { return m_bSpawned; }
	Projectile * GetBullets() { return Bullets; }


	void SetShot(bool a_bSetShotStatus) { m_bShot = a_bSetShotStatus; }
	void SetTimer( int a_iSetTimer ) { m_iTimer = a_iSetTimer; }
	void SetAmmo(int a_iNewAmmo) { m_iAmmo = a_iNewAmmo ; }
	void SetMaxAmmo(int a_iNewMaxAmmo) { m_iMaxAmmo = a_iNewMaxAmmo ; }
	void SetHp (int a_iSetHp) { m_iHp = a_iSetHp; }
	void SetSpawned(bool a_bSetSpawnedStatus) { m_bSpawned = a_bSetSpawnedStatus; }

};

#endif
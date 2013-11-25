//////////////////////////////////////////////////////////// 
// File: Enemy.h	 
// Author: Sam Legus	 
// Date Created: 10/1/2013
// Brief: Header for Enemy.cpp, which defines the Enemy class.
////////////////////////////////////////////////////////////

#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "AIE.h"
#include "Sprite.h"
#include "Projectile.h"
#include <cmath>


////******** READ ********
//Enemies are the same as player except for... AI() and UpdateAlive()
class Enemy : public Sprite
{
private:

	int m_iAmmo; 
	int m_iTimer;
	int m_iMaxAmmo;
	int m_iHp;

	float m_iMoveTimer;
	Projectile * Bullets;

	bool m_bSpawned;

public:

	Enemy();
	~Enemy();

	void CreateBullets(int a_iArraySize); /
	void Draw();
	void Move();
	void Shoot();
	
	void Reload();
/*	FUNCTION: AI()
	BRIEF: Causes enemy to fire at player when the player is in front of it.
	RETURN: void */
	void AI(Sprite &a_PlayerOne);
	void UpdateEnemy(Sprite &a_PlayerOne); 

	void DebugEnemy();
	
/*	FUNCTION: UpdateAlive()
	BRIEF: Re-defined UpdateAlive() function from sprite parent, enemy is not alive if its hp is less than zero or they are offscreen.
	RETURN: void */
	virtual void UpdateAlive(); //Inherited from sprite class

/*	FUNCTIONS: INLINE ACCESS FUNCTIONS
	BRIEF: Getters and Setters for member variables of Enemy class. */
	 int GetAmmo() { return m_iAmmo; }
	 int GetMaxAmmo() { return m_iMaxAmmo; }
	 int GetTimer() { return m_iTimer; }
	 int GetHp() { return m_iHp; }
	 bool GetSpawned() { return m_bSpawned; }
	
	 Projectile * GetBullets() { return Bullets; }

	 void SetTimer( int a_iSetTimer ) { m_iTimer = a_iSetTimer; }
	 void SetAmmo(int a_iNewAmmo) { m_iAmmo = a_iNewAmmo ; }
	 void SetMaxAmmo(int a_iNewMaxAmmo) { m_iMaxAmmo = a_iNewMaxAmmo ; }
	 void SetHp (int a_iSetHp) { m_iHp = a_iSetHp; }
	 void SetSpawned(bool a_bSetSpawnedStatus) { m_bSpawned = a_bSetSpawnedStatus; }


};

#endif
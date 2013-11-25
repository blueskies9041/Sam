#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AIE.h"
#include "Sprite.h"
#include "Projectile.h"

#include <cmath>

class Player : public Sprite
{
	private:
		

		int m_iAmmo;
		int m_iTimer;
		bool m_bShot;
		
		Projectile * Bullets;
	
	public:
		Player();
		~Player();

		Projectile * CreateBullets(int a_iArraySize);

		void UpdatePlayer();
		void Draw();
		void Move();
		void Control();
		void Shoot();
		void Reload();
		
		//Getters and Setters, inline definitions.
		int GetAmmo() { return m_iAmmo; }
		int GetTimer() { return m_iTimer; }
		bool GetShot() { return m_bShot; }
		
		void SetAmmo(int a_iNewAmmo) { m_iAmmo = a_iNewAmmo ; }
		void SetTimer( int a_iSetTimer ) { m_iTimer = a_iSetTimer; }
		void SetShot(bool a_bSetShotStatus) { m_bShot = a_bSetShotStatus; }
};

#endif
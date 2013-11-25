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
		int m_iMaxAmmo;
		int m_iTimer;
		int m_iHp;
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
		void SpreadShot(); //cont later
		void Reload();
		
		//Getters and Setters, inline definitions.
		int GetAmmo() { return m_iAmmo; }
		int GetMaxAmmo() { return m_iMaxAmmo; }
		int GetTimer() { return m_iTimer; }
		int GetHp() { return m_iHp; }
		bool GetShot() { return m_bShot; }
		Projectile * GetBullets() { return Bullets; }
		
		void SetAmmo(int a_iNewAmmo) { m_iAmmo = a_iNewAmmo ; }
		void SetMaxAmmo(int a_iNewMaxAmmo) { m_iMaxAmmo = a_iNewMaxAmmo ; }
		void SetTimer( int a_iSetTimer ) { m_iTimer = a_iSetTimer; }
		void SetHp (int a_iSetHp) { m_iHp = a_iSetHp; }
		void SetShot(bool a_bSetShotStatus) { m_bShot = a_bSetShotStatus; }
};

#endif
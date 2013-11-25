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
		bool m_bAlive;
		
		Projectile * Bullets;
	
	public:
		
		Player();
		~Player();

		void CreateBullets(int a_iArraySize);
		void UpdatePlayer();
		void Draw();
		void Move();
		void Control();
		void Shoot();
		void SpreadShot(); //cont later
		void Reload();

		void DebugPlayer();
		
		//Getters and Setters, inline definitions.
		inline int GetAmmo() { return m_iAmmo; }
		inline int GetMaxAmmo() { return m_iMaxAmmo; }
		inline int GetTimer() { return m_iTimer; }
		inline int GetHp() { return m_iHp; }
		inline bool GetShot() { return m_bShot; }
		inline bool GetAlive() { return m_bAlive; }
		//inline Projectile * GetBullets() { return Bullets; }
		Projectile * GetBullets() ;
		
		inline void SetAmmo(int a_iNewAmmo) { m_iAmmo = a_iNewAmmo ; }
		inline void SetMaxAmmo(int a_iNewMaxAmmo) { m_iMaxAmmo = a_iNewMaxAmmo ; }
		inline void SetTimer( int a_iSetTimer ) { m_iTimer = a_iSetTimer; }
		inline void SetHp (int a_iSetHp) { m_iHp = a_iSetHp; }
		inline void SetShot(bool a_bSetShotStatus) { m_bShot = a_bSetShotStatus; }
		inline void SetAlive(bool a_bSetAliveStatus) { m_bAlive = a_bSetAliveStatus; }
};

#endif
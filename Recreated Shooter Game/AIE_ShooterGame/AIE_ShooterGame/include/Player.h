//////////////////////////////////////////////////////////// 
// File: Player.h
// Author: Sam Legus	 
// Date Created: 10/1/2013
// Brief: Header for Player.cpp, which defines the Player class.
////////////////////////////////////////////////////////////

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

	/*	FUNCTION: CreateBullets()
		ARGUMENTS: int a_iArraySize
		BRIEF: Creates (initializes) a number of projectiles equal the the array size argument.
		RETURN: void */
		void CreateBullets(int a_iArraySize);
	
	/*	FUNCTION: UpdatePlayer()
		BRIEF: Updates member variables, Updates all contained Bullets, and calls Move, Draw, and Control() functions.
		RETURN: void */
		void UpdatePlayer();
	/*	FUNCTION: Draw()
		BRIEF: Draws player sprite to screen if the the Player's alive flag is true. Will not draw otherwise.
		RETURN: void */
		void Draw();
	/*	FUNCTION: Move()
		BRIEF: Moves player sprite on the screen if the the Player's alive flag is true. Will not move otherwise.
		RETURN: void */
		void Move();
	/*	FUNCTION: RestrictMovement()
		BRIEF: Restricts player from moving outside screen boundaries.
		RETURN: void */
		void RestrictMovement();
	/*	FUNCTION: Control()
		BRIEF: Detects Input from keyboard and mouse, WASD to move, R/L MBs to shoot.
		RETURN: void */
		void Control();
	/*	FUNCTION: Shoot()
		BRIEF: Uses the ammo counter to determine the bullet to fire, firing a bullet 1) Sets the Bullets Position to the Player
		2) Sets its alive flag to true(enables move and draw), and sets its forward velocity to 2. m_iTimer is used to implement
		a delay between shots. If a player has no ammo it will call reload() to .
		RETURN: void */
		void Shoot();
	/*	FUNCTION: SpreadShot()
		BRIEF: Same as Shoot() except: Fires three bullets at a time with the two on the left and right having 45 degree offsets. 
		Uses three bullets at a time.
		RETURN: void */
		void SpreadShot(); 
	/*	FUNCTION: Reload()
		BRIEF: Resets ammo counter to 0 after it reaches its maximum.
		RETURN: void */
		void Reload();
		//void DebugPlayer();
		
	/*	FUNCTION: UpdateAlive()
		BRIEF: Re-defined UpdateAlive() function from sprite parent, player is not alive if its hp is less than zero.
		RETURN: void */
		virtual void UpdateAlive();

	/*	FUNCTIONS: INLINE ACCESS FUNCTIONS
		BRIEF: Getters and Setters for member variables of Player class. */
		inline int GetAmmo() { return m_iAmmo; }
		inline int GetMaxAmmo() { return m_iMaxAmmo; } 
		inline int GetTimer() { return m_iTimer; }
		inline int GetHp() { return m_iHp; }
		inline bool GetShot() { return m_bShot; }
		
		inline Projectile * GetBullets() { return Bullets; }
		inline void SetAmmo(int a_iNewAmmo) { m_iAmmo = a_iNewAmmo ; }
		inline void SetMaxAmmo(int a_iNewMaxAmmo) { m_iMaxAmmo = a_iNewMaxAmmo ; }
		inline void SetTimer( int a_iSetTimer ) { m_iTimer = a_iSetTimer; }
		inline void SetHp (int a_iSetHp) { m_iHp = a_iSetHp; }
		inline void SetShot(bool a_bSetShotStatus) { m_bShot = a_bSetShotStatus; }
};

#endif
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Vector2D.h"
#include "Sprite.h"
#include "AIE.h"

class Projectile : public Sprite
{
	private:
		bool m_bAlive; //A Projectile is "alive" once a player or enemy shoots it until is exceeds the Y boundaries of the screen.
		bool m_bHit;
	public:
		Projectile();
		~Projectile();

		void Draw();
		void Move();
		void UpdateProjectile();

		//Getters and Setters, inline definitions
		bool GetAlive() { return m_bAlive; }
		bool GetHit() { return m_bHit;}

		void SetAlive(bool a_bSetAliveStatus) { m_bAlive = a_bSetAliveStatus; }
		void SetHit(bool a_bSetHitStatus) { m_bHit = a_bSetHitStatus; }
};

#endif
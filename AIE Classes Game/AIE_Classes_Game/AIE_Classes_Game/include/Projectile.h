#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Vector2D.h"
#include "Sprite.h"
#include "AIE.h"

class Projectile : public Sprite
{
	private:
		bool m_bAlive; //A Projectile is "alive" once it a player or enemy shoots it until is exceeds the Y boundaries of the screen.

	public:
		Projectile();
		~Projectile();

		void Draw();
		void Move();
		void UpdateProjectile();

		//bool CheckCollision(Enemy &a_Enemy);
		//bool CheckCollision(Player &a_Player);

		//Getters and Setters, inline definitions
		bool GetAlive() { return m_bAlive; }
		void SetAlive(bool a_bSetAliveStatus) { m_bAlive = a_bSetAliveStatus; }
};

#endif
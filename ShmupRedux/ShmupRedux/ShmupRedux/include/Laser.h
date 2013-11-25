#ifndef _LASER_H_
#define _LASER_H_

#include "projectile.h"
#include "AIE.h"

class Laser : public Projectile
{
	public:
	
		void Launch();
		void HandleCollision(Entity &a_roTarget);
		void Init();
		void Update();
		void Launch(Entity &ar_oSource);

		//For now

		void Move();
		void Draw();
		void Die();
};

#endif

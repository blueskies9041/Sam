#define _CRT_SECURE_NO_WARNINGS
#include "AIE.h"
#include "gameObject.h"
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

class Player : public gameObject
{
	private:

	public:
		Player();
		~Player();
		void HandleInput();
		void Die();
		void Shoot(gameObject &newBullet);
};

#endif
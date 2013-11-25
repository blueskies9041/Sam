#define _CRT_SECURE_NO_WARNINGS
#include "AIE.h"
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

class Projectile : public gameObject
{
	private:
		bool fired;
	public:

		//access
		bool getFired();
		void setFired(bool itsFired);

		//member functions
		
		void handleCollision(Player collided);
};

#endif
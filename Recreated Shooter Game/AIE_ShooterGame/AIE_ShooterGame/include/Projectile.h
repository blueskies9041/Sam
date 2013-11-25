//////////////////////////////////////////////////////////// 
// File: Projectile.h
// Author: Sam Legus	 
// Date Created: 10/1/2013
// Brief: Header for Projectile.cpp, which defines the Projectile class.
////////////////////////////////////////////////////////////

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Vector2D.h"
#include "Sprite.h"
#include "AIE.h"

class Projectile : public Sprite
{
	private:
		
	public:
		Projectile();
		~Projectile();

		void Draw();
		void Move();
	/*	FUNCTION: UpdateProjectile()
		BRIEF: Calls UpdateAlive() moves sprite offscreen (disabling move and draw) if it's alive is false.
		RETURN: void */
		void UpdateProjectile();
	/*	FUNCTION: UpdateAlive()
		BRIEF:  Re-defined UpdateAlive() function from sprite parent, projectile is not alive if it's offscreen.
		RETURN: void */
		virtual void UpdateAlive();	
};

#endif
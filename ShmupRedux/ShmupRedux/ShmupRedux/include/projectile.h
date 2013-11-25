#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

/* Abstract Class */
#include "AIE.h"
#include "Entity.h"

class Unit;

class Projectile : public Entity
{
public:
	virtual void Launch(Entity &ar_oSource) = 0;
	inline void SetDamage(int a_iDamage){ m_iDamage = a_iDamage; }
	inline int GetDamage() { return m_iDamage; }

	void HandleCollision(Unit &ar_oTarget);

private:
	int m_iDamage;
	
};

#endif
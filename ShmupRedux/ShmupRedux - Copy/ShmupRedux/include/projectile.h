#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

/* Abstract Class */
#include "AIE.h"
#include "Entity.h"

class Projectile : public Entity
{
public:
	virtual void Launch(Entity &ar_oSource) = 0;
	int GetDamage() { return m_iDamage; }

private:
	int m_iDamage;
	
};

#endif
#ifndef _UNIT_H_
#define _UNIT_H_

#include "AIE.h"
#include "Entity.h"
#include <vector>
/* Abstract Class */

class Projectile;

typedef std::vector<Projectile*> ProjectileVector;

class Unit : public Entity
{
public:

	void Move();
	void Draw();
	inline ProjectileVector &GetProjectiles() { return m_aoProjectiles; }
	enum WEAPON_TYPE
	{
		BULLET,
		MISSILE,
		LASER
	};

	inline int GetHp() { return m_iHp; } 
	inline void SetHp(int a_iHp) { m_iHp = a_iHp; }
	
	void HandleCollision(Projectile &a_roTarget);

protected:
		
private:
	ProjectileVector m_aoProjectiles;
	int m_iHp;

};

#endif
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
	inline ProjectileVector& GetProjectiles() { return m_aoProjectiles; }
	enum WEAPON_TYPE
	{
		BULLET,
		MISSILE,
		LASER
	};

	//virtual void Fire();
	//inline int GetHp() { return m_iHp; } 
	//inline void SetHp(int a_iHp) { m_iHp = a_iHp; }
	
	//const std::vector<Projectile *> & GetProjectiles()
	//{
	//	return m_aoProjectiles;


	//}
private:
	
	ProjectileVector m_aoProjectiles;
	//int m_iHp;
	//std::vector<Projectile *> m_aoProjectiles;
};

#endif
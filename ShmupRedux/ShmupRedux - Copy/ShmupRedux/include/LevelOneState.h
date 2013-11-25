#ifndef _LEVELONESTATE_H_
#define _LEVELONESTATE_H_

#include "GameState.h"
#include <vector>

class Unit;
class Entity;

class LevelOneState : public GameState
{
	public:
		void Init();
		void Update(Engine * a_opGame);
		void Cleanup();
		void HandleCollisions();
		bool CheckBoxCollision(Entity &a_roSource, Entity &a_roTarget);

		static LevelOneState * Instance()
		{
			return &sm_oLevelOneState;
		}

	protected:
		LevelOneState() { }
	private:

		std::vector<Unit*>m_aUnits;
		std::vector<unsigned int> m_aBackgroundElements;
		float m_fDistanceFromPlayer;
		static LevelOneState sm_oLevelOneState;
};

#endif
#ifndef _LEVELONESTATE_H_
#define _LEVELONESTATE_H_

#include "GameState.h"
#include <vector>

class Unit;
class Entity;

typedef std::vector<Unit*> UnitVector;

class LevelOneState : public GameState
{
	public:
		void Init();
		void Update(Engine * a_opGame);
		void Cleanup();
		void HandleCollisions();

		static LevelOneState * Instance()
		{
			return &sm_oLevelOneState;
		}

	protected:
		LevelOneState() { }
	private:

		UnitVector m_aUnits;
		std::vector<unsigned int> m_aBackgroundElements;
		float m_fDistanceFromPlayer;
		static LevelOneState sm_oLevelOneState;
};

#endif
#ifndef _MENU_H_
#define _MENU_H_

#include "AIE.h"
#include "UIButton.h"
#include <vector>
#include <list>

class Menu
{
	public:

		Menu();
		Menu(char * cpFilepath, int a_iNumButtons);
		~Menu();

		void Update();

		inline int GetBackgroundID() { return m_iBackgroundID; }
		
	private:

		std::list<UIButton> ButtonList;
		int m_iBackgroundID;
		

};

#endif
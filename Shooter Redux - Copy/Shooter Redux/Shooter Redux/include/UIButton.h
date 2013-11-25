#ifndef _UIBUTTON_H
#define _UIBUTTON_H

#include "AIE.h"
#include "Vector2D.h"
#include <vector>

class UIButton
{

	public:

		UIButton();
		UIButton(const UIButton &a_other);
		UIButton(Vector2D a_vPosition, int a_iWidth, int a_iHeight, char * a_cpText);
		~UIButton();
		void Update();
		
		bool IsClickable();

		bool GetClicked() { return m_bClicked; }

	private:

		char * m_cpText;
		int m_iWidth;
		int m_iHeight;
		bool m_bClicked;
		Vector2D m_vStart;
		Vector2D m_vEnd;
		Vector2D m_vPosition; //center
};


#endif
#include "UIButton.h"

int iMouseX = 0.0f;
int iMouseY = 0.0f;

UIButton::UIButton()
{
	
}

UIButton::UIButton(const UIButton &a_other)
{
	m_cpText = a_other.m_cpText;
	m_iWidth = a_other.m_iWidth;
	m_iHeight = a_other.m_iHeight;
	m_vStart = a_other.m_vStart;
	m_vEnd = a_other.m_vEnd;
	m_vPosition = a_other.m_vPosition;
}

UIButton::UIButton(Vector2D a_vPosition, int a_iWidth, int a_iHeight, char * a_cpText) :
	m_vPosition(a_vPosition), 
	m_iWidth(a_iWidth), 
	m_iHeight(a_iHeight),
	m_vStart(a_vPosition.GetX() , a_vPosition.GetY() - a_iHeight ),
	m_vEnd( a_vPosition.GetX() + a_iWidth , a_vPosition.GetY() + a_iHeight ),
	m_cpText(a_cpText)
{ }

UIButton::~UIButton()
{

}

bool UIButton::IsClickable()
{
	if( (iMouseX > m_vStart.GetX() && iMouseX < m_vEnd.GetX()) && (iMouseY < m_vEnd.GetY() && iMouseY > m_vStart.GetY()))
		return true;
	else
		return false;
}

void UIButton::Update()
{
	GetMouseLocation(iMouseX, iMouseY);

	if(IsClickable() && GetMouseButtonDown(0))
	{
		m_bClicked = true;
		DrawString("Active!" , m_vPosition.GetX() - 100, m_vPosition.GetY());	
	}
		
	DrawLine(m_vStart.GetX(), m_vEnd.GetY(), m_vEnd.GetX(), m_vEnd.GetY());
	DrawString(m_cpText, m_vPosition.GetX(), m_vPosition.GetY());	
}


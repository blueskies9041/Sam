#include "Vector2D.h"

// *** CONSTRUCTORS *** //

//Sets x and y members to zero if no parameters are passed
Vector2D::Vector2D(void) :
	m_fX(0.0f), 
	m_fY(0.0f) 
{ }

//Primary constructor
Vector2D::Vector2D(float a_fX, float a_fY) :
	m_fX(a_fX), 
	m_fY(a_fY) 
{ }

//Copy constructor, NOTE: Elizabeth says to pass objects by reference to avoid " unnecessary copying " .
Vector2D::Vector2D(Vector2D &a_vec) :
	m_fX(a_vec.m_fX),
	m_fY(a_vec.m_fY)
{ }

// *** DECONSTRUCTOR *** //
Vector2D::~Vector2D(void)
{ }






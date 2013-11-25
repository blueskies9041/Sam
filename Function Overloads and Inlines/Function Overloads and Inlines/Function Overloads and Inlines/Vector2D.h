#ifndef _VEC2D_H_
#define _VEC2D_H_

#include "stdafx.h"

class Vector2D
{
	private:

		//Two floats, for storing X and Y values
		float x;
		float y;

	public:

		//Constructors and deconstructor
		Vector2D(void); //sets both x and y to zero
		Vector2D(float a_fX, float a_fY); //sets x and y to passed floating point arguments
		Vector2D(Vector2D &a_vec); //copy constructor

		~Vector2D(void);

		//Data access
		float GetX() {return x;}
		float GetY() {return y;}
		void SetX(float a_x) {x = a_x;}
		void SetY(float a_y) {y = a_y;}

		Vector2D operator +(Vector2D & a_AddedVector) { return Vector2D(x + a_AddedVector.x, y + a_AddedVector.y); }
		Vector2D operator -(Vector2D & a_SubtractedVector) { return Vector2D(x - a_SubtractedVector.x, y - a_SubtractedVector.y); 

};

#endif
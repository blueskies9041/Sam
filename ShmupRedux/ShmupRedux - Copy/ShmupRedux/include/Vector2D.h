#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

/* TO DO 11/19 : Implement constant compatability for functions, implement already completed
Vector3D functions */

class Vector2D
{
	private:

		//Two floats, for storing X and Y values
		float m_fX;
		float m_fY;

	public:

		//Constructors and deconstructor
		Vector2D(void); //sets both x and y to zero
		Vector2D(float a_fX, float a_fY); //sets x and y to passed floating point arguments
		Vector2D(Vector2D &a_vec); //copy constructor

		~Vector2D(void);

		//Data access
		inline float GetX() {return m_fX;}
		inline float GetY() {return m_fY;}
		inline void SetX(float a_fX) {m_fX = a_fX;}
		inline void SetY(float a_fY) {m_fY = a_fY;}

		Vector2D operator +(Vector2D &a_AddedVector) { return Vector2D(m_fX + a_AddedVector.m_fX, m_fY + a_AddedVector.m_fY); }
		Vector2D operator -(Vector2D &a_SubtractedVector) { return Vector2D(m_fX - a_SubtractedVector.m_fX, m_fY - a_SubtractedVector.m_fY); }
	
};

#endif
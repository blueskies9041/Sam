#ifndef _VECTOR3D_H
#define _VECTOR3D_H

#include <math.h>
class Vector3D
{
	public:

		float m_fX;
		float m_fY;
		float m_fZ;

		Vector3D(float a_fX, float a_fY, float a_fZ); //Standard ctor, inits xyz to args
		Vector3D(const Vector3D &ac_v3DCopy);//Copy constructor, inits xyz to copy vector xyz
		Vector3D(); //Empty ctor, inits xyz to 0
		~Vector3D();

		float Magnitude();
		void Normalize();
		Vector3D GetNormal();
		float Dot(Vector3D a_v3Other);
		Vector3D Cross(Vector3D a_v3Other);
		float Euler(Vector3D a_v3Other);
	

		Vector3D operator + (Vector3D &a_v3Added);
		void operator += (Vector3D a_v3Added);
		Vector3D operator - (Vector3D &a_v3Subtracted);
		void operator -= (Vector3D a_vSubtracted);
		Vector3D operator * (float a_fScalar);
		void operator *= (float a_fScalar);
		Vector3D operator / (float a_fScalar);
		void operator /= (float a_fScalar);
		

};

#endif
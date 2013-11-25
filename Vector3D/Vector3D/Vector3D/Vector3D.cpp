#include "Vector3D.h"

Vector3D::Vector3D(float a_fX, float a_fY, float a_fZ)
{
	m_fX = a_fX;
	m_fY = a_fY;
	m_fZ = a_fZ;
}

Vector3D::Vector3D(const Vector3D &ac_v3DCopy)
{
	m_fX = ac_v3DCopy.m_fX;
	m_fY = ac_v3DCopy.m_fY;
	m_fZ = ac_v3DCopy.m_fZ;
}

Vector3D::Vector3D()
{
	m_fX = 0.0f;
	m_fY = 0.0f;
	m_fZ = 0.0f;
}

Vector3D::~Vector3D()
{

}

Vector3D Vector3D::operator + (Vector3D &a_v3Added)
{
	Vector3D v3Sum(m_fX + a_v3Added.m_fX, (m_fY + a_v3Added.m_fY) , (m_fZ + a_v3Added.m_fZ));
	return v3Sum;
}

void Vector3D::operator += (Vector3D a_v3Added)
{
	m_fX += a_v3Added.m_fX;
	m_fY += a_v3Added.m_fY;
	m_fZ += a_v3Added.m_fZ;
}

Vector3D Vector3D::operator - (Vector3D& a_v3Subtracted)
{
	a_v3Subtracted.m_fX *= -1;
	a_v3Subtracted.m_fY *= -1;
	a_v3Subtracted.m_fZ *= -1;

	Vector3D v3Difference(m_fX + a_v3Subtracted.m_fX, (m_fY + a_v3Subtracted.m_fY) , (m_fZ + a_v3Subtracted.m_fZ));

	return v3Difference;
}

void Vector3D::operator -= (Vector3D a_v3Subtracted)
{
	a_v3Subtracted.m_fX *= -1;
	a_v3Subtracted.m_fY *= -1;
	a_v3Subtracted.m_fZ *= -1;	

	m_fX += a_v3Subtracted.m_fX;
	m_fY += a_v3Subtracted.m_fY;
	m_fZ += a_v3Subtracted.m_fZ;
}

Vector3D Vector3D::operator * (float a_fScalar)
{
	Vector3D v3DScaledVector(m_fX * a_fScalar, m_fY * a_fScalar, m_fZ * a_fScalar);
	return v3DScaledVector;
}

void Vector3D::operator *= (float a_fScalar)
{
	m_fX *= a_fScalar;
	m_fY *= a_fScalar;
	m_fZ *= a_fScalar;
}

Vector3D Vector3D::operator / (float a_fScalar)
{
	Vector3D v3DScaledVector(m_fX / a_fScalar, m_fY / a_fScalar, m_fZ / a_fScalar);
	return v3DScaledVector;
}

void Vector3D::operator /= (float a_fScalar)
{
	m_fX /= a_fScalar;
	m_fY /= a_fScalar;
	m_fZ /= a_fScalar;
}

float Vector3D::Magnitude()
{
	return sqrt( pow(m_fX, 2) + pow(m_fY, 2) + pow(m_fZ, 2));
}

void Vector3D::Normalize()
{
	Vector3D v3DNormalized( m_fX / Magnitude(), m_fY / Magnitude(), m_fZ / Magnitude() );

	m_fX = v3DNormalized.m_fX;
	m_fY = v3DNormalized.m_fY;
	m_fZ = v3DNormalized.m_fZ;
}

Vector3D Vector3D::GetNormal()
{
	Vector3D v3DNormalized( m_fX / Magnitude(), m_fY / Magnitude(), m_fZ / Magnitude() );
	return v3DNormalized;
}

float Vector3D::Dot(Vector3D a_v3Other)
{
	return (m_fX * a_v3Other.m_fX) + (m_fY * a_v3Other.m_fY) + (m_fZ * a_v3Other.m_fZ);
}

Vector3D Vector3D::Cross(Vector3D a_v3Other)
{
	Vector3D v3DCrossProduct(
		(m_fY * a_v3Other.m_fZ) - (m_fZ * a_v3Other.m_fY) ,
		(m_fZ * a_v3Other.m_fX) - (m_fX * a_v3Other.m_fZ) ,
		(m_fX * a_v3Other.m_fY) - (m_fY * a_v3Other.m_fX));
	return v3DCrossProduct;
}

float Vector3D::Euler(Vector3D a_v3Other)
{
	return acosf(Dot(a_v3Other) / ( Magnitude() * a_v3Other.Magnitude()));
}


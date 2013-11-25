#include <cmath>

enum COLLISION_STATE
{
	CS_SEPARATE,
	CS_OVERLAP,
	CS_TOUCH,
};

struct Vec2D
{
	float x, y;
};

struct Circle
{
	Vec2D vCenter;
	float fRadius;
};



Vec2D VectorSubtract(Vec2D vOne, Vec2D vTwo)
{
	Vec2D vReturn;
	vReturn.x = vOne.x - vTwo.x;
	vReturn.y = vTwo.x - vTwo.y;

	return vReturn;
}

float VectorMagnitude(Vec2D vVector)
{
	return sqrt(vVector.x * vVector.x + vVector.y * vVector.y);
}

float GetDistance(Vec2D centerOne, Vec2D centerTwo)
{
	Vec2D vDistance = VectorSubtract(centerOne, centerTwo);
	return VectorMagnitude(vDistance);
}

COLLISION_STATE CheckCircleCollision(Circle cOne, Circle cTwo)
{
	float fSafeDistance = cOne.fRadius + cTwo.fRadius;
	float fDistance = GetDistance(cOne.vCenter, cTwo.vCenter);

	if(fDistance > fSafeDistance)
		return CS_SEPARATE;

	if(fDistance == fSafeDistance)
		return CS_TOUCH;

	if(fDistance < fSafeDistance)
		return CS_OVERLAP;

	else
		;;
}


#define _CRT_SECURE_NO_WARNINGS
#include "AIE.h"
#include "gameObject.h"
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

Projectile * createBullet();
void fireBullets(Projectile * Bullets, int arraySize);
void Move(gameObject &objectToMove);
	
#endif


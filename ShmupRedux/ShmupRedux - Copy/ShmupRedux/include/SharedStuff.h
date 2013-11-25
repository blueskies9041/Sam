#ifndef _SHAREDSTUFF_H_
#define _SHAREDSTUFF_H_

#include "Vector2D.h"

/* Miscelaneous variables and constants for the elimination of magic
numbers according to AIE coding standards, also includes things like
enumerations for weapon types... blah blah blah */

//UNIVERSAL CONSTANTS
Vector2D c_v2DStill(0.0f, 0.0f);

// CONSTANTS & INIT VARIABLE VALUES FOR PLAYER
const int c_iPlayerWidth = 50;
const int c_iPlayerHeight = 50;
bool c_bPlayerAlive = true;
const int c_iPlayerMaxBullets = 8;

Vector2D c_v2DInitPlayerPos(512, 384);

//CONSTANTS FOR BULLETS
Vector2D c_v2DBulletSpeed(0, -2);
Vector2D c_v2DBulletDimensions(30, 30);

// Weapon types, useable by enemy and player
enum WEAPON_TYPE
{
	BULLET,
	MISSILE,
	LASER
};

#endif
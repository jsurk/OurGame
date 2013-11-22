/*
 * Projectile.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include "Projectiles.h"

float dmg = 5;
float pArrowSpeed = 5;

float Projectiles::playerArrowSpeed()
{
	return pArrowSpeed;
}

float Projectiles::playerArrowDmg()
{
	return dmg;
}

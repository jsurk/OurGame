/*
 * EnemyKnight.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */
#include "EnemyKnight.h"

float speed = 10;
float attack = 5;

bool EnemyKnight::init()
{
	if (!Sprite::init()) {
		return false;
	}

	return true;
}

EnemyKnight* EnemyKnight::spriteWithFile(const char *fileName)
{
    EnemyKnight *p = new EnemyKnight();
    if (p && p->initWithFile(fileName))
    {
    	p->health = 10;
        return p;
    }
    CC_SAFE_DELETE(p);
        return NULL;
}

// Grabs health
float EnemyKnight::getHealth()
{
	return this->health;
}

// Reduces health by given amount
void EnemyKnight::takeDmg(float dmg)
{
	this->health -= dmg;
}

// Grabs the speed of this enemy
float EnemyKnight::getSpeed()
{
	return speed;
}

// Grabs the enemy's attack
float EnemyKnight::getAttack()
{
	return attack;
}

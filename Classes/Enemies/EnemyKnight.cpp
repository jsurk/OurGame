/*
 * EnemyKnight.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */
#include "EnemyKnight.h"
#include "Utils.h"
#include "Constants.h"
#include "HUD.h"

float EnemyKnight::maxHealth = 10;
float EnemyKnight::speed = 10;
float EnemyKnight::atk = 3;
float EnemyKnight::atkTimer = 3;


bool EnemyKnight::init()
{
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

// Creates an EnemyKnight with the given file
Enemy* EnemyKnight::createKnight()
{
    EnemyKnight *p = new EnemyKnight();
    if (p && p->initWithFile("enemy.png"))
    {
    	p->setTag(KNIGHT);
    	p->health = maxHealth;
    	p->lastAtk = 0;
        return p;
    }
    CC_SAFE_DELETE(p);
        return NULL;
}

void EnemyKnight::died()
{
	Utils::hudLayer()->addScore(100);
}

// Called when an enemy attacks
void EnemyKnight::attack(float t)
{
	if(t - lastAtk >= atkTimer) {
		Utils::hudLayer()->subScore(atk);
		lastAtk = t;
	}
}

// Grabs the speed of this enemy
float EnemyKnight::getSpeed()
{
	return speed;
}

// Grabs the enemy's attack
float EnemyKnight::getAttack()
{
	return atk;
}

/*
 * Enemy.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: Mark
 */
#include "Enemy.h"
#include "Constants.h"
#include "EnemyKnight.h"

// Initialized the Enemy
bool Enemy::init()
{
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

// Returns the health of the enemy
float Enemy::getHealth()
{
	return health;
}

// Reduces the enemy's health by the given amount
void Enemy::takeDmg(float dmg)
{
	health -= dmg;
}

// Returns true if the enemy is dead
bool Enemy::isDead()
{
	return health <= 0;
}

Sprite* Enemy::createEnemy(int tag)
{
	if (tag == KNIGHT) {
		return EnemyKnight::createKnight();
	}
	return NULL;
}

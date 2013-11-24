/*
 * TestEnemy.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: Mark
 */
#include "TestEnemy.h"

float speed = 5;
float attack = 3;
float maxHealth = 5;
float atkTimer = 3;

bool TestEnemy::init()
{
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

float TestEnemy::getSpeed()
{
	return speed;
}

float getAttack()
{
	return attack;
}

Enemy* TestEnemy::createTestEnmy()
{
    TestEnemy *p = new TestEnemy();
    if (p && p->initWithFile("enemy.png"))
    {
    	p->setTag(TESTENEMY);
    	p->health = maxHealth;
    	p->lastAtk = 0;
        return p;
    }
    CC_SAFE_DELETE(p);
        return NULL;
}

void TestEnemy::attack(float t)
{
	if(t - lastAtk >= atkTimer) {
		Utils::hudLayer()->subHP(atk);
		lastAtk = t;
	}
}

void TestEnemy::died()
{
	Utils::hudLayer()->addScore(50);
}

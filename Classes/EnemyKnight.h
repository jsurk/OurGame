/*
 * EnemyKnight.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef ENEMYKNIGHT_H_
#define ENEMYKNIGHT_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "Constants.h"
using namespace cocos2d;

class EnemyKnight : public Enemy
{
private:
	static float atk, speed, maxHealth, atkTimer;

public:
	virtual bool init();
	// Grabs the speed
	float getSpeed();
	// Gets attack
	float getAttack();
	// Creates an EnemyKnight
	static Enemy* createKnight();
	// Called when an enemy attacks
	void attack(float t);
	// Called when an enemy dies
	void died();

	CREATE_FUNC(EnemyKnight);
};

#endif /* ENEMYKNIGHT_H_ */

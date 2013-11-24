/*
 * TestEnemy.h
 *
 *  Created on: Nov 23, 2013
 *      Author: Mark
 */

#ifndef TESTENEMY_H_
#define TESTENEMY_H_

#include "Enemy.h"

class TestEnemy : public Enemy
{
private:
	static float atk, speed, maxHealth, atkTimer;

public:
	bool init();
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

	CREATE_FUNC(TestEnemy);
};


#endif /* TESTENEMY_H_ */

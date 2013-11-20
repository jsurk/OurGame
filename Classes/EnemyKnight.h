/*
 * EnemyKnight.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef ENEMYKNIGHT_H_
#define ENEMYKNIGHT_H_

#include "cocos2d.h"
using namespace cocos2d;


class EnemyKnight : public Sprite
{
private:
	float health;
	float attack;
public:
	virtual bool init();

	static EnemyKnight* spriteWithFile(const char *fileName);
	// Returns the health
	float getHealth();
	// Reduces health by given amount
	void takeDmg(float dmg);
	// Grabs the speed
	float getSpeed();
	// Gets attack
	float getAttack();

	CREATE_FUNC(EnemyKnight);
};


#endif /* ENEMYKNIGHT_H_ */

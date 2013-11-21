/*
 * Enemy.h
 *  Created on: Nov 20, 2013
 *      Author: Mark
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "cocos2d.h"


// Parent class of all enemies. No instance of this
// class should ever be made
class Enemy : public cocos2d::Sprite
{
protected:
	float health, lastAtk;

public:
	virtual bool init();
	// Creates an enemy with a file
	static Sprite* createEnemy(int tag);
	// Gets the speed of the enemy
	virtual float getSpeed() =0;
	// Sets the speed of the enemy
	//virtual void setSpeed() =0;
	// Gets the attack of the enemy
	virtual float getAttack() =0;
	// Sets the max health of an enemy
	//virtual void setMaxHealth() =0;
	// Called when an enemy attacks
	virtual void attack(float t) =0;
	// Returns the health of this enemy
	float getHealth();
	// Makes the enemy take damage
	void takeDmg(float dmg);
	// Returns true if the enemy is dead
	bool isDead();
	// Called when an enemy dies
	virtual void died() =0;
};

#endif /* ENEMY_H_ */

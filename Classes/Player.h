/*
 * Player.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "cocos2d.h"
#include "Constants.h"
using namespace cocos2d;

class Player : public Sprite
{
private:

public:
	int column, maxArrows;
	virtual bool init();

	Player* spriteWithFile(const char *pszFileName);

	// Called when the player is tapped
	void wasTapped();
	// Moves the player left
	void moveLeft();
	// Moves the player right
	void moveRight();

	CREATE_FUNC(Player);
};

#endif /* PLAYER_H_ */

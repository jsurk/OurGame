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

class Player::Sprite
{
private:
	// Area at the bottom of the screen where the plaer is contained
	Rect* playerArea;

public:
	int column, maxArrows;
	virtual bool init();

	// Called when the player is tapped
	void wasTapped();
	// Moves the player left
	void moveLeft();
	// Moves the player right
	void moveRight();
	// Returns the player area
	Rect* getPlayerArea;

	CREATE_FUNC(Player);
};

#endif /* PLAYER_H_ */

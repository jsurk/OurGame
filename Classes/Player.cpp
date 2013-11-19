/*
 * Player.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */
#include "Player.h"

bool Player::init()
{
	if (!Sprite::init()) {
		return false;
	}
	this->setDisplayFram("player.png");
	column = TOTAL_COLUMNS / 2 + 1;
	playerArea = Rect::create(Utils::convertX(column), this->getDisplayFrame->height);
	return true;
}

// Handles what happens when the Player sprite is tapped
void Player::wasTapped()
{
	// TBD
}

// Moves the player left
void Player::moveLeft()
{
	if (column > 0) {
		column--;
		this->setPositionX(Utils::convertX(column));
	}
}

// Moves the player right
void Player::moveRight()
{
	if (column < 9) {
		column++;
		this->setPositionX(Utils::convertX(column));
	}
}

// Returns the playerArea
Rect* Player::getPlayerArea()
{
	return playerArea;
}

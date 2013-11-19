/*
 * Player.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */
#include "Player.h"
#include "Utils.h"

bool Player::init()
{
	if (!Sprite::init()) {
		return false;
	}

	return true;
}

Player* Player::spriteWithFile(const char *pszFileName)
{
    Player *p = new Player();
    if (p && p->initWithFile(pszFileName))
    {
    	p->column = TOTAL_COLUMNS / 2 + 1;
    	auto bb = this->getBoundingBox();

        p->autorelease();
        return p;
    }
    CC_SAFE_DELETE(p);
        return NULL;
}



// Handles what happens when the Player sprite is tapped
void Player::wasTapped()
{

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

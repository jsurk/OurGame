/*
 * Player.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */
#include "Player.h"
#include "Utils.h"
#include "Projectiles.h"

USING_NS_CC;
int INIT_MAX_ARROWS = 3;

bool Player::init()
{
	if (!Sprite::init()) {
		return false;
	}

	return true;
}

Player* Player::spriteWithFile(const char *fileName)
{
    Player *p = new Player();
    if (p && p->initWithFile(fileName))
    {
    	p->column = TOTAL_COLUMNS / 2 + 1;
    	p->maxArrows = INIT_MAX_ARROWS;
    	p->arrows = Array::create();
        p->autorelease();
        return p;
    }
    CC_SAFE_DELETE(p);
        return NULL;
}



// Handles what happens when the Player sprite is tapped
void Player::wasTapped()
{
	log("tapped");
	if (this->arrows->count() < this->maxArrows) {
		auto arr = Sprite::create("arrow.png");
//		a->setPosition(this->getPosition());
//		Utils::layerWithTag(TAG_GAME_LAYER)->addChild(a, 0);
//		this->arrows->addObject(a);
//		auto act = MoveTo::create(Projectiles::playerArrowSpeed(), Point(a->getPositionX(), 980));
	}
}

// Moves the player left
void Player::moveLeft()
{
	if (column > 2) {
		column--;
		this->setPositionX(Utils::convertX(column));
	}
}

// Moves the player right
void Player::moveRight()
{
	if (column < 8) {
		column++;
		this->setPositionX(Utils::convertX(column));
	}
}

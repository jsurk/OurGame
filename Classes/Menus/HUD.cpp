/*
 * HUD.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include "HUD.h"
#include "Constants.h"
#include "Utils.h"
#include "GameOver.h"

bool HUD::init()
{
    if (!Layer::init() )
    {
        return false;
    }



    // Initializes the score
    score = 0;
    scoreLabel = LabelTTF::create("0", String::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 50);
    scoreLabel->setAnchorPoint(Point(0, 1));
    Point scoreLoc = Point(10, DESIGN_HEIGHT - 10);
    scoreLabel->setPosition(scoreLoc);
    this->addChild(scoreLabel, 1);

    // Initializes the health bar
    maxHealth = 100;
    currentHealth = 100;

    hpBar = Sprite::create("hp_bar.png");
    hpBar->setAnchorPoint(Point(1, .5));
    Point hpBarLoc = Point(DESIGN_WIDTH - 10, hpBar->getContentSize().height / 2 + 10);
    hpBar->setPosition(hpBarLoc);
    this->addChild(hpBar, 1);

    return true;
}

// Subtracts from the score and updates the label
void HUD::subScore(int i)
{
	score -= i;
	if (score < 0) {
		score = 0;
	}
	scoreLabel->setString(String::createWithFormat("%d", score)->getCString());
}

// Adds to the score
void HUD::addScore(int i)
{
	score += i;
	scoreLabel->setString(String::createWithFormat("%d", score)->getCString());
}

// Subtracts from the player hp
void HUD::subHP(float f)
{
	currentHealth -= f;
	if (currentHealth <= 0) {
		((GameOver*) Utils::layerWithTag(TAG_GAMEOVER))->show(true);
		currentHealth = 0;
	}
	hpBar->setScaleX(currentHealth / maxHealth);
}

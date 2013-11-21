/*
 * HUD.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include "HUD.h"
#include "Constants.h"
#include "Utils.h"

bool HUD::init()
{
    if (!Layer::init() )
    {
        return false;
    }

    // Initializes the score
    score = 0;
    float scoreX = 10;
    float scoreY = Utils::getSize().height - 10;
    scoreLabel = LabelTTF::create("0", "fonts/Marker Felt.ttf", 50);
    scoreLabel->setAnchorPoint(Point(0, 1));
    scoreLabel->setPosition(Point(scoreX, scoreY));
    this->addChild(scoreLabel, 1);
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

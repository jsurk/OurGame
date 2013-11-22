/*
 * GameOver.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: Mark
 */

#ifndef GAMEOVER_CPP_
#define GAMEOVER_CPP_

#include "GameOver.h"
#include "Constants.h"
#include "Utils.h"

// Initializes the GameOver
bool GameOver::init()
{
	if (!Layer::init()) {
		return false;
	}

	LabelTTF* gameOverText = LabelTTF::create("Game Over",
			String::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 50);
	float goX = DESIGN_WIDTH / 2;
	float goY = DESIGN_HEIGHT * .8;
	gameOverText->setPosition(Point(goX, goY));
	this->setVisible(false);
	this->addChild(gameOverText, 1);

    auto replayButton = MenuItemImage::create("replay.png", "replay.png", CC_CALLBACK_0(GameOver::replay, this));
    Menu* menu = Menu::create(replayButton, NULL);
    this->addChild(menu, 1);
}

void GameOver::show(bool shouldShow)
{
    Game *g = Utils::gameLayer();
    if (shouldShow) {
        g->pauseSchedulerAndActions();
        g->setTouchEnabled(false);
    }
    else {
        g->resumeSchedulerAndActions();
    	g->setTouchEnabled(true);
    }

    for (int i = 0; i < g->getChildrenCount(); i++) {
        Node *n = (Node*) g->getChildren()->getObjectAtIndex(i);
        if (shouldShow) {
            n->pauseSchedulerAndActions();
        }
        else {
            n->resumeSchedulerAndActions();
        }
    }

    this->setVisible(shouldShow);
}

// Handles the replay button call
void GameOver::replay()
{
	Director::getInstance()->replaceScene(Game::createScene());
}

#endif /* GAMEOVER_CPP_ */

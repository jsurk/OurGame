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
#include "MainMenu.h"

// Initializes the GameOver
bool GameOver::init()
{
	if (!Layer::init()) {
		return false;
	}

	// Creates the GameOver text
	LabelTTF* gameOverText = LabelTTF::create("Game Over",
			String::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 50);
	gameOverText->setPosition(Point(DESIGN_WIDTH / 2, DESIGN_HEIGHT * .8));
	this->addChild(gameOverText, 1);

	// Creates the buttons for the menu
    auto replayButton = MenuItemImage::create("replay.png", "replay.png", CC_CALLBACK_0(GameOver::replay, this));
    auto menuButton = MenuItemImage::create("replay.png", "replay.png", CC_CALLBACK_0(GameOver::mainMenu, this));

    // Creates the menu and adds the buttons
    Menu* menu = Menu::create(replayButton, menuButton, NULL);
    menu->alignItemsVerticallyWithPadding(30);
    this->addChild(menu, 1);

    this->setVisible(false);

    return true;
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

// Opens the MainMenu
void GameOver::mainMenu()
{
	MainMenu::mainMenu();
}


#endif /* GAMEOVER_CPP_ */

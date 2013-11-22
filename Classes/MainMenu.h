/*
 * MainMenu.h
 *
 *  Created on: Nov 21, 2013
 *      Author: Mark
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "cocos2d.h"
using namespace cocos2d;

class MainMenu : public Layer
{
public:
	bool init();
	// Creates the scene of the game
	static Scene* createScene();
	// Plays the game
	void play();
	// Brings up the MainMenu
	static void mainMenu();

	CREATE_FUNC(MainMenu);
};

#endif /* MAINMENU_H_ */

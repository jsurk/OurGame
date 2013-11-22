/*
 * MainMenu.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: Mark
 */
#include "MainMenu.h"
#include "Constants.h"
#include "Game.h"

// Initializes the MainMenu
bool MainMenu::init()
{
	if (!Layer::init()) {
		return false;
	}

	auto menuBG = Sprite::create("bg.png");
	menuBG->setPosition(Point(DESIGN_WIDTH / 2, DESIGN_HEIGHT / 2));
	this->addChild(menuBG, -1);

	auto playButton = MenuItemImage::create("replay.png", NULL, CC_CALLBACK_0(MainMenu::play, this));
	auto menu = Menu::create(playButton, NULL);
	this->addChild(menu, 1);

	return true;
}

// Creates the MainMenu scene
Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto mainMenu = MainMenu::create();
	scene->addChild(mainMenu, 0);
	return scene;
}

// Plays the game
void MainMenu::play()
{
	Director::getInstance()->replaceScene(Game::createScene());
}

// Opens the MainMenu
void MainMenu::mainMenu()
{
	Director::getInstance()->replaceScene(MainMenu::createScene());
}

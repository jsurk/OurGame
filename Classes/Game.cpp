/*
 * Game.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include "Game.h"
#include "Utils.h"
#include "Constants.h"
#include "HUD.h"

USING_NS_CC;


bool Game::init()
{
    if (!Layer::init() )
    {
        return false;
    }

	// Creates and adds the background
	auto bg = Sprite::create("bg.png");
	bg->setPosition(Point(Utils::getSize().width / 2, Utils::getSize().height / 2));
	int w = bg->getContentSize().width;
	this->addChild(bg, -1);

	// Creates and adds the player sprite
	player = (new Player())->spriteWithFile("player.png");
	player->setAnchorPoint(Point(.5, 0));
	player->setPosition(Point(Utils::convertX(player->column), 0));

	this->addChild(player, 1);

	// Sets touch enabled
	this->setTouchEnabled(true);
    this->addTouchListener();

	// Allows the tick function to be called every frame
	this->schedule(schedule_selector(Game::tick));
}



// Creates the scene and all the layers
Scene* Game::createScene()
{
	auto scene = Scene::create();
	scene->setTag(TAG_GAME_SCENE);
	auto g = Game::create();
	scene->addChild(g, 0, TAG_GAME_LAYER);
	//auto h = HUD::create();
	//scene->addChild(h, 1, TAG_HUD);
	return scene;
}

// Initializes the entire game
void Game::initializeGame()
{

}

// Is called every frame
void Game::tick(float dt)
{
	totalTime += dt;
}

// Handles touches
void Game::onTouchesBegan(const std::vector<Touch*> &touches, Event * pEvent)
{
	auto location = touches.front()->getLocation();

	// Checks if the tap was within the player area, then determines where in the area it was
	if (location.y <= 240) {
		if (player->getBoundingBox().containsPoint(location)) {
			player->wasTapped();
		}
		else if (player->getBoundingBox().getMaxX() < location.x) {
			player->moveRight();
		}
		else {
			player->moveLeft();
		}
	}
}

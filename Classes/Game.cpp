/*
 * Game.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include "Game.h"
#include "Player.h"
#include "Utils.h"
#include "Constants.h"

USING_NS_CC;


bool Game::init()
{
    if (!Layer::init() )
    {
        return false;
    }
}

// Creates the scene and all the layers
Scene* Game::createScene()
{
	auto scene = Scene::create();
	scene->setTag(TAG_GAME_SCENE);
	auto g = Game::create();
	scene->addChild(0, g, TAG_GAME_LAYER);
	auto h = HUD::create();
	scene->addChild(1, h, TAG_HUD_LAYER);
	return scene;
}

// Initializes the entire game
void Game::initializeGame()
{
	// Creates and adds the background
	auto bg = Sprite::create("bg.png");
	bg->setPosition(Point(Utils::size()->width / 2, Utils::size()->height / 2));
	Utils::scaleSprite(bg);
	this->addChild(-1, bg);

	// Creates and adds the player sprite
	auto player = Player::create();
	player->setAnchorPoint(.5, 0);
	player->setPosition(Point(0, Utils::convertX(player->column)));
	this->addChild(player, 1);

	// Sets touch enabled
	this->setTouchEnabled(true);

	// Allows the tick function to be called every frame
	this->schedule(schedule_selector(Game::tick));
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
	// Currently slightly inefficient. If more checks within the playerArea are not added I
	// will alter.
	if (player->getPlayerArea()->containsPoint(location)) {
		if (player->getBoundingBox()->containsPoint(location)) {
			player->wasTapped();
		}
		else if (location->x > player->getPlayerArea()->getMaxX()) {
			player->moveRight();
		}
		else {
			player->moveLeft();
		}
	}
}

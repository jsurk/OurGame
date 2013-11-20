/*
 * Game.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include <cstdlib>
#include "Game.h"
#include "Utils.h"
#include "Constants.h"
#include "HUD.h"
#include "Units.h"
#include "EnemyKnight.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>


USING_NS_CC;

float INITIAL_ENEMY_TIMER = 5;
int INITIAL_MAX_ENEMIES = 5;

bool Game::init()
{
    if (!Layer::init() )
    {
        return false;
    }
    // Sets enemy spawn timer
    this->enemyTimer = INITIAL_ENEMY_TIMER;
    this->maxEnemies = INITIAL_MAX_ENEMIES;


	// Creates and adds the background
	auto bg = Sprite::create("bg.png");
	bg->setPosition(Point(Utils::getSize().width / 2, Utils::getSize().height / 2));
	this->addChild(bg, -1);
	auto bg_castle = Sprite::create("bg_castle.png");
	bg_castle->setPosition(Point(Utils::getSize().width / 2, Utils::getSize().height / 2));
	this->addChild(bg_castle, 1);



	// Creates and adds the player sprite
	player = (new Player())->spriteWithFile("player.png");
	player->setAnchorPoint(Point(.5, 0));
	player->setPosition(Point(Utils::convertX(player->column), 0));
	this->addChild(player, 3);

	// Initializes the arrays
	playerArrows = Array::create();
	playerArrows->retain();
	enemies = Array::create();
	enemies->retain();

	// Sets touch enabled
	this->setTouchEnabled(true);
    this->addTouchListener();

	// Allows the tick function to be called every frame
	//this->schedule(schedule_selector(Game::update));
    this->scheduleUpdate();
    this->totalTime = 0;
    this->timeElapsed = 0;
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
void Game::update(float dt)
{
	totalTime += dt;
	timeElapsed += dt;
	this->cleanUp();
	this->checkProjectileCollisions();
	this->deleteDeadEnemies();
	this->checkEnemyAttacks();

	if (enemies->count() < maxEnemies && timeElapsed >= enemyTimer) {
		this->spawnEnemy();
		timeElapsed = 0;
	}
}

// Handles touches
void Game::onTouchesBegan(const std::vector<Touch*> &touches, Event * pEvent)
{
	auto location = touches.front()->getLocation();
	// Checks if the tap was within the player area, then determines where in the area it was
	if (location.y <= 240) {
		if (player->getBoundingBox().containsPoint(location)) {
			if (this->playerArrows->count() < player->maxArrows) {
				this->fireArrow();
			}
		}
		else if (player->getBoundingBox().getMaxX() < location.x) {
			player->moveRight();
		}
		else {
			player->moveLeft();
		}
	}
}

// Checks for projectile colliwions
void Game::checkProjectileCollisions()
{
    Object* it = NULL;
    Object* jt = NULL;
    Array* arrowsToDelete = Array::create();

	CCARRAY_FOREACH(playerArrows, it) {
		Sprite *ar = dynamic_cast<Sprite*>(it);
		CCARRAY_FOREACH(enemies, jt) {
			EnemyKnight *e = dynamic_cast<EnemyKnight*>(jt);
			if (ar->getBoundingBox().intersectsRect(e->getBoundingBox())) {
				e->takeDmg(Projectiles::playerArrowDmg());
				arrowsToDelete->addObject(ar);
			}
		}
	}

	CCARRAY_FOREACH(arrowsToDelete, jt)
	{
		Sprite *ar = dynamic_cast<Sprite*>(jt);
		playerArrows->removeObject(ar);
		this->removeChild(ar, true);
	}

	arrowsToDelete->release();
}

// Cleans up off screen projectiles
void Game::cleanUp()
{
    Object* it = NULL;
    Array* arrowsToDelete = Array::create();

    CCARRAY_FOREACH(playerArrows, it) {
		Sprite *ar = dynamic_cast<Sprite*>(it);
		if (ar->getPositionY() > Utils::getSize().height + ar->getContentSize().height / 2) {
			arrowsToDelete->addObject(ar);
		}
    }

    CCARRAY_FOREACH(arrowsToDelete, it) {
		Sprite *ar = dynamic_cast<Sprite*>(it);
		playerArrows->removeObject(ar);
		this->removeChild(ar, true);
    }

    arrowsToDelete->release();
}

// Spawns an enemy at a random location
void Game::spawnEnemy()
{
	auto e = EnemyKnight::spriteWithFile("enemy.png");
	e->setTag(2);
	int x = rand() % 7 + 2;
	e->setPosition(Point(Utils::convertX(x), Utils::getSize().height + e->getContentSize().height / 2));
	auto act = MoveTo::create(e->getSpeed(), Point(e->getPositionX(), 180));
	this->addChild(e, 0);
	enemies->addObject(e);
	e->runAction(act);
}

// Maybe fires an arrow
void Game::fireArrow()
{
	auto a = Sprite::create("arrow.png");
	a->setPosition(player->getPosition());
	playerArrows->addObject(a);
	this->addChild(a, 1);
	a->setTag(1);
	auto act = MoveTo::create(Projectiles::playerArrowSpeed(), Point(a->getPositionX(), 1100));
	a->runAction(act);
}

// Deletes all enemies with 0 or less health
void Game::deleteDeadEnemies()
{
    Object* it = NULL;
    Array* enemiesToDelete = Array::create();

    CCARRAY_FOREACH(enemies, it) {
		EnemyKnight *e = dynamic_cast<EnemyKnight*>(it);
		if (e->getHealth() <= 0) {
			enemiesToDelete->addObject(e);
		}
    }

    CCARRAY_FOREACH(enemiesToDelete, it) {
		EnemyKnight *e = dynamic_cast<EnemyKnight*>(it);
		enemies->removeObject(e);
		this->removeChild(e, true);
    }

    enemiesToDelete->release();
}

// Checks if an enemy is attacking
void Game::checkEnemyAttacks()
{
	Object* it = NULL;
	CCARRAY_FOREACH(enemies, it) {
		EnemyKnight *e = dynamic_cast<EnemyKnight*>(it);
		if(e->getPositionY() == 180) {
			// Does something
		}
	}
}

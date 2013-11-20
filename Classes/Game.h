/*
 * Game.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef GAME_H_
#define GAME_H_

#include "cocos2d.h"
#include "Player.h"
#include "Projectiles.h"
using namespace cocos2d;

class Game : public cocos2d::Layer
{
private:
	Array *playerArrows, *enemies;
	int maxEnemies;
	float totalTime, timeElapsed, enemyTimer;
	Player* player;

public:
    // Creates the scene
    static cocos2d::Scene* createScene();
    virtual bool init();
    // Initialized the game
    void initializeGame();
    // Ticks for every frame of the game. Default is 60/s
    virtual void update(float dt);
    // Handles touches
    virtual void onTouchesBegan(const std::vector<Touch*> &touches, Event * pEvent);
    // Maybe fires an arrow
    void fireArrow();
    // Cleans up off-screen projectiles
    void cleanUp();
    // Spawns an enemy
    void spawnEnemy();
    // Checks if the projectiles collided with any enemies
    void checkProjectileCollisions();
    // Deletes dead enemies
    void deleteDeadEnemies();
    // Checks for attacking enemies
    void checkEnemyAttacks();

    CREATE_FUNC(Game);
};


#endif /* GAME_H_ */

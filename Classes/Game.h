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
using namespace cocos2d;

class Game : public cocos2d::Layer
{
private:
	float totalTime;
	Player* player;

public:
    // Creates the scene
    static cocos2d::Scene* createScene();
    virtual bool init();
    // Initialized the game
    void initializeGame();
    // Ticks for every frame of the game. Default is 60/s
    void tick(float dt);
    // Handles touches
    virtual void onTouchesBegan(const std::vector<Touch*> &touches, Event * pEvent);

    CREATE_FUNC(Game);
};


#endif /* GAME_H_ */

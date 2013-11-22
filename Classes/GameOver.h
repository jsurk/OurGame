/*
 * GameOver.h
 *
 *  Created on: Nov 21, 2013
 *      Author: Mark
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "cocos2d.h"
using namespace cocos2d;

class GameOver : public Layer
{
public:
	bool init();
	// Determines if this should be shown or not
	void show(bool shouldShow);
	// Called when the replay button is hit
	void replay();

	CREATE_FUNC(GameOver);
};


#endif /* GAMEOVER_H_ */

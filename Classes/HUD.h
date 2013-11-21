/*
 * HUD.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef HUD_H_
#define HUD_H_

#include "cocos2d.h"
using namespace cocos2d;

class HUD : public Layer
{
private:
	// There are plans to implement a better resource system than
	// just "score", but this is it for now
	int score;
	LabelTTF* scoreLabel;
public:
    virtual bool init();
    // Adds to the score;
    void addScore(int i);
    // Subtracts from the score
    void subScore(int i);
    // Gets the score
    int getScore();

    CREATE_FUNC(HUD);
};

#endif /* HUD_H_ */

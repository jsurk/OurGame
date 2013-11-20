/*
 * Utils.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "cocos2d.h"
#include "HUD.h"
#include "Game.h"

using namespace cocos2d;

class Utils
{
public:
	// Returns the current Game layer
	static Game* gameLayer();
	// Returns the current HUD layer
	static HUD* hudLayer();
	// Returns the layer with the given tag. Useful so the layers
	// don't need to be stored anywhere and can be pulled from the
	// currently active scene
	static Layer* layerWithTag(int tag);
	// Returns the screen size
	static Size getSize();
	// Converts the given X column to a GL X coordinate based on screen size
	static int convertX(int x);
	// Returns the playerArea
	static Rect* playerArea();
};


#endif /* UTILS_H_ */

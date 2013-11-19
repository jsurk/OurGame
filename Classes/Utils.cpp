/*
 * Utils.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#include "Utils.h"

// Returns the current Game layer
Game* Utils::gameLayer()
{
	return (Game*) Utils::layerWithTag(TAG_GAME_LAYER);
}

// Returns the current HUD layer
HUD* Utils::hudLayer()
{
	return (HUD*) Utils::layerWithTag(TAG_HUD_LAYER);
}

// Returns the layer with the given tag
Layer* Utils::layerWithTag(int tag)
{
	auto sc = Director::getInstance()->getRunningScene();
	if (sc->getTag() == TAG_GAME_SCENE) {
		auto *layer = (Layer *) sc->getChildByTag(tag);
		return layer;
	}
	return null;
}

// Returns the screen size
Size Utils::getSize()
{
	return Director::getInstance()->getVisibleSize();
}

// Scales a sprite based on the size of the screen
void Utils::scaleSprite(Sprite* sprite)
{
    float rX = Utils::getSize().width / sprite->getContentSize().width;
	float rY = Utils::getSize().height / sprite->getContentSize().height;
	sprite->setScaleX(rX);
	sprite->setScaleY(rY);
}

// Converts the given X column to a GL X coordinate based on screen size
int Utils::convertX(int x)
{
	int rX = Utils::getSize().width / 9;
	return x * rX;
}

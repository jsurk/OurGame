/*
 * Constants.h
 *
 *  Created on: Nov 19, 2013
 *      Author: Mark
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define FONT_MAIN "fonts/Marker Felt"
static const int TOTAL_COLUMNS = 9;
static const int DESIGN_WIDTH = 540;
static const int DESIGN_HEIGHT = 960;

typedef enum {
    TAG_GAME_LAYER,
    TAG_HUD,
    TAG_GAME_SCENE,
    TAG_PAUSE,
    TAG_GAMEOVER,
    KNIGHT,
} tags;

#endif /* CONSTANTS_H_ */

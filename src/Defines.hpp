#pragma once

#include "gfx/gfx.h"
#include <tice.h>

#define PLAYER_SPEED 2
#define PLAYER_HEIGHT Paddle_height
#define PLAYER_WIDTH Paddle_width
#define PLAYER_MIDDLE_Y_OFFSET (PLAYER_HEIGHT / 2)
#define PLAYER_MIDDLE_X_OFFSET (PLAYER_WIDTH / 2)
#define PLAYER_Y ((LCD_HEIGHT / 2) - (PLAYER_HEIGHT / 2))
#define MAX_PLAYER_Y (LCD_HEIGHT - PLAYER_HEIGHT)
#define PLAYER_WIDTH_OFFSET 16

#define LCD_MIDDLE_X (LCD_WIDTH / 2)
#define LCD_MIDDLE_Y (LCD_HEIGHT / 2)

#define BALL_WIDTH Ballimg_width
#define BALL_HEIGHT Ballimg_height
#define BALL_MIDDLE_Y_OFFSET (BALL_HEIGHT / 2)
#define BALL_MIDDLE_X_OFFSET (BALL_HEIGHT / 2)
#define BALL_SPEED 30.0f
#define BALL_RESPAWN_TIME_SEC 2

#define LINE_WIDTH Line_width

#define NONE 0
#define WALL_RIGHT 1
#define WALL_LEFT 2
#define WALL_DOWN 3
#define WALL_UP 4
#define PLAYER_COLLISION 5
#define PLAYER_TWO_COLLISION 6

#define PLAYER_ONE_INDEX 1
#define PLAYER_TWO_INDEX 2

#define UP 0
#define DOWN 1

#define SINGLEPLAYER 1
#define MULTIPLAYER 2
#define QUIT 3

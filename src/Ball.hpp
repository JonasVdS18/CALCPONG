#pragma once

#include "Defines.hpp"
#include "Player.hpp"
#include "gfx/gfx.h"
#include <graphx.h>
#include <keypadc.h>
#include <tice.h>

class Ball
{
  public:
    float x, y;     // the x and y coordinate of the ball
    float vx, vy;   // the x and y velocity of the ball
    char collision; // a variable that stores what the ball just collided with

    gfx_sprite_t* sprite; // the ball sprite

    Player* player;    // pointer to the player
    Player* playerTwo; // pointer to the second player

    Ball(gfx_sprite_t* sprite, Player* player, Player* playerTwo); // constructor

    void reset(void);

    char CheckBallCollisions(void);

    void move(void);
};

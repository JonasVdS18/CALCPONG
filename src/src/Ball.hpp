#pragma once

#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"
#include "Player.hpp"
#include "Defines.hpp"

class Ball
{
public:
    float x, y;//the x and y coordinate of the ball
    float vx, vy;//the x and y velocity of the ball
    char collision;//a variable that stores what the ball just collided with
    gfx_sprite_t* sprite;//the ball sprite

    Player* player;//reference to the player
    Player* playerTwo;//reference to the second player

    Ball(gfx_sprite_t* sprite, Player* player, Player* playerTwo);//constructor

    void Reset();

    char CheckBallCollisions();

    void Move();
};
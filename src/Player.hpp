#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "gfx/gfx.h"
#include <graphx.h>
#include <keypadc.h>

class Ball;

class Player
{
  private:
    int sx, sy;       // start x and y coordinates
    char playerIndex; // which player (right player or left player)
  public:
    int x, y;             // x and y coordinates of the player
    gfx_sprite_t* sprite; // the player sprite

    Ball* ball;

    Player(gfx_sprite_t* sprite, int x, int y, char playerIndex, Ball* ball); // constructor

    void move(void);
    void move(char direction); // move function for 1 player opponent
};

#endif

#pragma once

#include "gfx/gfx.h"
#include <graphx.h>
#include <keypadc.h>
#include <tice.h>

class Player
{
  private:
    int sx, sy;       // start x and y coordinates
    char playerIndex; // which player (right player or left player)
  public:
    int x, y;             // x and y coordinates of the player
    gfx_sprite_t* sprite; // the player sprite

    /*Definitions*/
    Player(gfx_sprite_t* sprite, int x, int y, char playerIndex); // constructor

    void reset(void);

    void move(void);
    void move(char direction); // move function for 1 player opponent
};

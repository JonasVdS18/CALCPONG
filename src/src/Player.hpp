#pragma once

#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"

class Player
{
private:
    int sx, sy;//start x and y coordinates
    char playerIndex;//which player (right player or left player)
public:
    int x, y;//x and y coordinates of the player
    gfx_sprite_t* sprite;//the player sprite

    /*Definitions*/
    Player(gfx_sprite_t* sprite, int x, int y, char playerIndex);//constructor

    void Reset();

    void Move();
};
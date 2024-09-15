#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"
#include "Player.hpp"
#include "Defines.hpp"

Player::Player(gfx_sprite_t* sprite, int x, int y, char playerIndex)//constructor definition
{
    /*assign values to all the variables*/
    this->x = x;
    this->y = y;
    this->sx = x;
    this->sy = y;
    this->playerIndex = playerIndex;
    this->sprite = sprite;
}

void Player::Reset()//function definition
{
    x = sx;//sets the x coordinate to the x start coordinate
    y = sy;//sets the y coordinate to the y start coordinate
}
void Player::Move()//function definition
{
    if (playerIndex == PLAYER_TWO_INDEX)//if the player is the second player
    {
        /*check the input from the arrowkeys*/
        kb_Scan();
        kb_key_t key = kb_Data[7];
        switch(key)
        {
            case kb_Up://if the up(arrow) key is pressed
            if(y > 0)
            {
                y -= PLAYER_SPEED;//subtract the player speed from the player y position to move up
                break;
            }
            break;
            case kb_Down://if the Down(arrow) key is pressed
            if(y <= MAX_PLAYER_Y)
            {
                y += PLAYER_SPEED;//adds the player speed to the player y position to move down
            break;
            }
            break;
        default:
            break;
        }
    }else//if the player is the second player
    {
        /*check the input from the 2nd and alpha key*/
        kb_Scan();
        if (kb_Data[1] == kb_2nd && y > 0)//if the 2nd key is pressed
        {
            y -= PLAYER_SPEED;//subtract the player speed from the player y position to move up
            return;
        }
        if (kb_Data[2] == kb_Alpha && y <= MAX_PLAYER_Y)//if the Alpha key is pressed
        {
            y += PLAYER_SPEED;//adds the player speed to the player y position to move down
            return;
        }
    }
}
#include <tice.h>
#include <graphx.h>
#include <keypadc.h>

#include "gfx/gfx.h"
#include "Defines.hpp"
#include "Ball.hpp"
#include "Player.hpp"

Player* player;//declares the Player
Player* playerTwo;//declares the second Player
Ball* ball;//declares the Ball

unsigned int scoreLeftPlayer;//the score of the player on the left side of the screen
unsigned int scoreRightPlayer;//the score of the player on the right side of the screen


void Setup()
{
    /*sets up the screen correctly*/
    os_ClrHome();

    gfx_Begin();

    gfx_SetDrawBuffer();

    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    gfx_SetTextFGColor(3);
    gfx_SetTextBGColor(1);
    gfx_SetMonospaceFont(0);
    gfx_SetTextScale(2, 2);

    gfx_SetTransparentColor(0);

    /*sets up the score count*/
    scoreLeftPlayer = 0;
    scoreRightPlayer = 0;
}

void Restart()
{
    /*resets the game*/
    player->Reset();
    playerTwo->Reset();
    ball->Reset();
}

void Draw()
{    
    gfx_FillScreen(1);//makes the screen totaly white
    if (ball->collision == WALL_RIGHT)
    {
        //gfx_PrintStringXY("THE PLAYER ON THE LEFT SCORED!", 55, LCD_MIDDLE_Y);
        delay(250);//waits two seconds
        gfx_SwapDraw();//swaps the buffer so the stuff we just drew to it will be displayed on the screen
        Restart();
        scoreLeftPlayer++;
        return;
    }else if(ball->collision == WALL_LEFT)
    {
        //gfx_PrintStringXY("THE PLAYER ON THE RIGHT SCORED!", 55, LCD_MIDDLE_Y);
        delay(250);//waits two seconds
        gfx_SwapDraw();//swaps the buffer so the stuff we just drew to it will be displayed on the screen
        Restart();
        scoreRightPlayer++;
        return;
    }
    gfx_TransparentSprite_NoClip(Line, LCD_MIDDLE_X - LINE_WIDTH/2, 0);
    gfx_Sprite_NoClip(player->sprite, player->x, player->y);
    gfx_Sprite_NoClip(playerTwo->sprite, playerTwo->x, playerTwo->y);
    gfx_Sprite(ball->sprite, ball->x, ball->y);
    gfx_SetTextXY(50, 5);
    gfx_PrintUInt(scoreLeftPlayer, 4);
    gfx_SetTextXY(205, 5);
    gfx_PrintUInt(scoreRightPlayer, 4);

    gfx_SwapDraw();//swaps the buffer so the stuff we just drew to it will be displayed on the screen
}

int main(void)
{
    Setup();

    player = new Player(Paddle, PLAYER_WIDTH_OFFSET, PLAYER_Y, PLAYER_ONE_INDEX);//creates the player
    playerTwo = new Player(Paddle, LCD_WIDTH - PLAYER_WIDTH - PLAYER_WIDTH_OFFSET, PLAYER_Y, PLAYER_TWO_INDEX);//creates the second player
    ball = new Ball(Ballimg, player, playerTwo);//creates an instance of the ball

    while (kb_Data[1] != kb_Del)//run this code when the delete key isn't pressed
    {
        player->Move();
        playerTwo->Move();
        ball->Move();
        Draw();
    }

    /*run this code when the delete key is pressed*/
    gfx_End();

    delete player;
    delete playerTwo;
    delete ball;

    return 0;
}

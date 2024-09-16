#include <graphx.h>
#include <keypadc.h>
#include <tice.h>

#include "Ball.hpp"
#include "Defines.hpp"
#include "Player.hpp"
#include "gfx/gfx.h"

Player* player;    // declares the Player
Player* playerTwo; // declares the second Player
Ball* ball;        // declares the Ball

unsigned int scoreLeftPlayer;  // the score of the player on the left side of the screen
unsigned int scoreRightPlayer; // the score of the player on the right side of
                               // the screen

void setup()
{
    /*sets up the screen correctly*/
    os_ClrHome();

    gfx_Begin();

    gfx_SetDrawBuffer();

    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    gfx_SetTextFGColor(3);
    gfx_SetTextBGColor(0);
    gfx_SetMonospaceFont(0);
    gfx_SetTextScale(2, 2);

    gfx_SetTransparentColor(1);

    /*sets up the score count*/
    scoreLeftPlayer = 0;
    scoreRightPlayer = 0;
}

void restart()
{
    /*resets the game*/
    player->reset();
    playerTwo->reset();
    ball->reset();
}

void draw()
{
    gfx_ZeroScreen(); // makes the screen totaly white
    if (ball->collision == WALL_RIGHT)
    {
        delay(250);     // waits two seconds
        gfx_SwapDraw(); // swaps the buffer so the stuff we just drew to
                        // it will be displayed on the screen
        restart();
        scoreLeftPlayer++;
        return;
    }
    else if (ball->collision == WALL_LEFT)
    {
        delay(250);     // waits two seconds
        gfx_SwapDraw(); // swaps the buffer so the stuff we just drew to
                        // it will be displayed on the screen
        restart();
        scoreRightPlayer++;
        return;
    }
    gfx_TransparentSprite_NoClip(Line, LCD_MIDDLE_X - LINE_WIDTH / 2, 0);
    gfx_Sprite_NoClip(player->sprite, player->x, player->y);
    gfx_Sprite_NoClip(playerTwo->sprite, playerTwo->x, playerTwo->y);
    gfx_Sprite(ball->sprite, ball->x, ball->y);
    gfx_SetTextXY(50, 5);
    gfx_PrintUInt(scoreLeftPlayer, 4);
    gfx_SetTextXY(205, 5);
    gfx_PrintUInt(scoreRightPlayer, 4);

    gfx_SwapDraw(); // swaps the buffer so the stuff we just drew to it will
                    // be displayed on the screen
}

char modeSelect()
{
    gfx_ZeroScreen(); // makes the screen totaly white
    gfx_PrintStringXY("SELECT 1", 100,
                      LCD_MIDDLE_Y - 20); // prints the string to the screen
    gfx_PrintStringXY("OR 2 PLAYERS", 70,
                      LCD_MIDDLE_Y + 20); // prints the string to the screen
    gfx_SwapDraw();
    while (kb_Data[1] != kb_Del)
    {
        kb_Scan();                  // scans the keyboard
        kb_key_t key1 = kb_Data[3]; // part of the keyboard data that
                                    // stores if 1 is pressed (look at
                                    // table in defenition if kb_Data)
        kb_key_t key2 = kb_Data[4]; // part of the keyboard data that
                                    // stores if 2 is pressed (look at
                                    // table in defenition if kb_Data)
        if (key1 == kb_1)
        {
            return SINGLEPLAYER; // return 1 if the player types 1
        }
        if (key2 == kb_2)
        {
            return MULTIPLAYER; // return 2 if the player types 2
        }
    }
    return QUIT;
}

int main(void)
{
    setup();
    char mode = 0;

    while (true) // run this code when the delete key isn't pressed
    {
        mode = modeSelect();
        if (mode == QUIT)
        {
            break;
        }

        delay(1000); // wait a second
        player = new Player(Paddle, PLAYER_WIDTH_OFFSET, PLAYER_Y,
                            PLAYER_ONE_INDEX); // creates the player
        playerTwo = new Player(Paddle, LCD_WIDTH - PLAYER_WIDTH - PLAYER_WIDTH_OFFSET, PLAYER_Y,
                               PLAYER_TWO_INDEX); // creates the second player
        ball = new Ball(Ballimg, player,
                        playerTwo); // creates an instance of the ball

        while (kb_Data[1] != kb_Del) // run this code when the delete key isn't pressed
        {
            if (mode == SINGLEPLAYER)
            {
                if ((ball->y + BALL_HEIGHT / 2) > (player->y + PLAYER_HEIGHT / 2)) // the ball is lower
                                                                                   // than the opponent
                {
                    player->move(DOWN);
                }
                else if ((ball->y + BALL_HEIGHT / 2) < (player->y + PLAYER_HEIGHT / 2)) // the ball is higher than
                                                                                        // the opponent
                {
                    player->move(UP);
                }
            }
            else // if in Multiplayer mode
            {
                playerTwo->move();
            }
            playerTwo->move();
            ball->move();
            draw();
        }
        delay(500);
        kb_Scan();

        delete player;
        delete playerTwo;
        delete ball;
    }

    /*run this code when the delete key is pressed*/
    gfx_End();

    return 0;
}

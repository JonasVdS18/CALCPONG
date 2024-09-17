#include "Ball.hpp"
#include "Defines.hpp"
#include "Player.hpp"
#include "gfx/gfx.h"
#include <graphx.h>
#include <keypadc.h>
#include <sys/util.h>
#include <tice.h>

Ball::Ball(gfx_sprite_t* sprite, Player* player, Player* playerTwo)
{
    /*generates a random direction for the ball to go in by generating a random x and y coordinate for the velocity
     * vector*/
    int x = randInt(7, 10);
    int y = randInt(1, 10);
    float length = x * x + y * y; // used for normalizing the generated vector
    float vx = ((float)x / length) * BALL_SPEED;
    float vy = ((float)y / length) * BALL_SPEED;
    if (random() % 2 == 1)
    {
        vx = -vx;
    }
    if (random() % 2 == 1)
    {
        vy = -vy;
    }

    this->x = LCD_MIDDLE_X - BALL_HEIGHT / 2;
    this->y = LCD_MIDDLE_Y - BALL_WIDTH / 2;
    this->vx = vx;
    this->vy = vy;
    this->sprite = sprite;
    this->player = player;
    this->playerTwo = playerTwo;
    this->collision = NONE;
}

void Ball::reset()
{
    x = LCD_MIDDLE_X - BALL_HEIGHT / 2;
    y = LCD_MIDDLE_Y - BALL_WIDTH / 2;
    /*generates a random direction for the ball to go in by generating a random x and y coordinate for the velocity
     * vector*/
    int x = randInt(7, 10);
    int y = randInt(1, 10);
    float length = x * x + y * y; // used for normalizing the generated vector
    vx = ((float)x / length) * BALL_SPEED;
    vy = ((float)y / length) * BALL_SPEED;
    if (random() % 2 == 1)
    {
        vx = -vx;
    }
    if (random() % 2 == 1)
    {
        vy = -vy;
    }

    collision = NONE;
}

/*check for collisions and return a char to indicate what we collided with*/
char Ball::CheckBallCollisions()
{
    if (x >= LCD_WIDTH - BALL_WIDTH)
    {
        return WALL_RIGHT;
    }
    else if (x <= 0)
    {
        return WALL_LEFT;
    }
    else if (y >= LCD_HEIGHT - BALL_HEIGHT)
    {
        return WALL_DOWN;
    }
    else if (y <= 0)
    {
        return WALL_UP;
    }
    else if (((player->y - BALL_HEIGHT) <= y && y <= (player->y + PLAYER_HEIGHT)) &&
             ((player->x - BALL_WIDTH) <= x && x <= (player->x + PLAYER_WIDTH)))
    {
        return PLAYER_COLLISION;
    }
    else if (((playerTwo->y - BALL_HEIGHT) <= y && y <= (playerTwo->y + PLAYER_HEIGHT)) &&
             ((playerTwo->x - BALL_WIDTH) <= x && x <= (playerTwo->x + PLAYER_WIDTH)))
    {
        return PLAYER_TWO_COLLISION;
    }
    else
    {
        return NONE;
    }
}

void Ball::move()
{
    collision = CheckBallCollisions();
    if (collision == WALL_DOWN || collision == WALL_UP)
    {
        vy = -vy; // makes it bounce
    }
    if (collision == PLAYER_COLLISION)
    {
        if ((player->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y) < 0) // Ball hits Player below the middle
        {
            vy = ((player->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y)) /
                 8.0f; // sets a new y velocity for the ball depending on where the Ball hits the player
        }
        else if ((player->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y) > 0) // Ball hits Player above the middle
        {
            vy = ((player->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y)) /
                 8.0f; // sets a new y velocity for the ball depending on where the Ball hits the player
        }

        vx = -vx; // makes it bounce
        vy = -vy; // makes it bounce
    }
    if (collision == PLAYER_TWO_COLLISION)
    {
        if ((playerTwo->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y) < 0) // Ball hits Player below the middle
        {
            vy = ((playerTwo->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y)) /
                 8.0f; // sets a new y velocity for the ball depending on where the Ball hits the player
        }
        else if ((playerTwo->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y) > 0) // Ball hits Player above the middle
        {
            vy = ((playerTwo->y + PLAYER_MIDDLE_Y) - (y + BALL_MIDDLE_Y)) /
                 8.0f; // sets a new y velocity for the ball depending on where the Ball hits the player
        }

        vx = -vx; // makes it bounce
        vy = -vy; // makes it bounce
    }

    x += vx; // adds the x velocity of the Ball to the x coordinate of the Ball to make it move on the x axis
    y += vy; // adds the y velocity of the Ball to the y coordinate of the Ball to make it move on the y axis
}

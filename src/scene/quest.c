/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quest menu
*/

#include "rpg.h"

const char str[1][3][39] =
    {{
    "Welcome stranger !\0",
    "I've some quests for you,\0",
    "Press this Complete button !\0"
    }
    };

void draw_quest(win_t *win)
{
    sfVector2f pos = {534, 371};

    sfSprite_setPosition(win->game->hud->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->hud->sprite, 0);
}

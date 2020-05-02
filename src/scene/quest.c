/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quest menu
*/

#include "rpg.h"

const char *str[3][5] =
    {{
    "Welcome stranger !\0",
    "I've some quests for you,\0",
    "Press this Complete button !\0",
    "And I'll give you a sword !\0",
    0
    }, {
    "Hey you !\0",
    "Your sword is in your inventory,\0",
    "Try to switch it in your toolbar.\0",
    "And I'll give you a pickaxe !\0",
    0
    }, {
    "I've nothing to tell you ...\0",
    "Go away !!\0",
    0
    }
    };

void draw_quest(win_t *win)
{
    sfVector2f pos = {534, 371};

    sfSprite_setPosition(win->game->hud->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->hud->sprite, 0);
    sfText_setCharacterSize(win->txt->text, 20);
    pos.y += 38;
    pos.x += 30;
    for (int y = 0; str[win->game->quest][y]; y++) {
        sfText_setString(win->txt->text, str[win->game->quest][y]);
        sfText_setPosition(win->txt->text , pos);
        sfRenderWindow_drawText(win->win, win->txt->text, 0);
        pos.y += 25;
    }
}

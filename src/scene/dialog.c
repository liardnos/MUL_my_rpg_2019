/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Dialog
*/

#include "rpg.h"

void draw_dialog(win_t *win)
{
    sfVector2f pos = {534, 435};

    sfSprite_setPosition(win->game->choose->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->choose->sprite, 0);
}

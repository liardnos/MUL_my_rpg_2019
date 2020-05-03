/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Home scene
*/

#include "rpg.h"

void draw_home(win_t *win)
{
    sfVector2f pos = {410, 80};
    world_t **world = main_cam(win->win);

    sfSprite_setPosition(win->logo->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->logo->sprite, 0);
}

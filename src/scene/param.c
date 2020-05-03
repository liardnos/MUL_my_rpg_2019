/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw options
*/

#include "rpg.h"

void draw_skin(win_t *win)
{
    sfVector2f pos = {1920.0 / 2.0 - 20, 1080 * 0.635};

    sfText_setCharacterSize(win->txt->text, 32);
    if (!win->config->type)
        sfText_setString(win->txt->text, "Male");
    else {
        sfText_setString(win->txt->text, "Female");
        pos.x -= 20;
    }
    sfText_setPosition(win->txt->text, pos);
    sfRenderWindow_drawText(win->win, win->txt->text, 0);
}

void draw_param(win_t *win)
{
    draw_skin(win);
}

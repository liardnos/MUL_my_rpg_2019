/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** GUI funcs
*/

#include "menu.h"

void replace_mouse(win_t *win)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)win->win);
    sfVector2f pos_f;

    pos_f.x = pos.x;
    pos_f.y = pos.y;
    sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
    sfSprite_setPosition(win->mouse->sprite, pos_f);
    sfRenderWindow_drawSprite(win->win, win->mouse->sprite, NULL);
}

void change_icon(sfRenderWindow *window)
{
    sfImage *img = sfImage_createFromFile("assets/cursor.png");
    sfVector2u size = sfImage_getSize(img);

    sfRenderWindow_setIcon(window, size.x, size.y, sfImage_getPixelsPtr(img));
    sfImage_destroy(img);
}

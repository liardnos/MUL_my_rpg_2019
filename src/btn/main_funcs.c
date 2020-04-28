/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main funcs of btns
*/

#include "menu.h"

void btn_quit(win_t *win)
{
    sfRenderWindow_close(win->win);
}

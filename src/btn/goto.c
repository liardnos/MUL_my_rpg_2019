/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Goto btn
*/

#include "rpg.h"

void btn_back(win_t *win)
{
    win->menu = 0;
}

void btn_opt(win_t *win)
{
    win->menu = 1;
}

void btn_help(win_t *win)
{
    win->menu = 2;
}

void btn_resume(win_t *win)
{
    win->menu = 3;
}

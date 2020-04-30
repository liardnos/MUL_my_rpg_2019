/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Btn quit menus
*/

#include "rpg.h"

void btn_return(win_t *win)
{
    free_game(win);
    win->menu = 0;
}

void btn_quit_game(win_t *win)
{
    free_game(win);
    btn_quit(win);
}

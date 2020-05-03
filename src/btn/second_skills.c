/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Second part of skills
*/

#include "rpg.h"

void btn_nofall(win_t *win, int *returned)
{
    if (win->game->skills >= 1 && win->game->nofall < 1) {
        win->game->nofall++;
        win->game->skills--;
        win->menu = 6;
    }
}

void btn_speed(win_t *win, int *returned)
{
    if (win->game->skills >= 1 && win->game->speed < 5) {
        win->game->speed++;
        win->game->skills--;
        win->menu = 6;
    }
}

void btn_attack(win_t *win, int *returned)
{
    if (win->game->skills >= 1 && win->game->attack < 5) {
        win->game->attack++;
        win->game->skills--;
        win->menu = 6;
    }
}

/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Left part of skills
*/

#include "rpg.h"

void btn_jumpb(win_t *win, int *returned)
{
    if (win->game->skills >= 1 && win->game->jumpb < 3) {
        win->game->jumpb++;
        win->game->skills--;
        win->menu = 6;
    }
}

void btn_health(win_t *win, int *returned)
{
    player_t *ply = win->game->players->next->data;

    if (win->game->skills >= 1 && ply->maxhp < 10) {
        ply->maxhp++;
        win->game->skills--;
        win->menu = 6;
    }
}

void btn_shield(win_t *win, int *returned)
{
    if (win->game->skills >= 1 && win->game->shield < 5) {
        win->game->shield++;
        win->game->skills--;
        win->menu = 6;
    }
}

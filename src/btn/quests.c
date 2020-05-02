/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quests Missions
*/

#include "rpg.h"

void btn_complete(win_t *win, int *returned)
{
    int (*funcs[])(win_t *) = { &quest_one, &quest_two, 0};

    if (win->game->quest + 1 <= 2 && (funcs[win->game->quest])(win))
        win->game->quest++;
}

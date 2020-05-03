/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quests Missions
*/

#include "rpg.h"

void btn_complete(win_t *win, int *returned)
{
    int (*funcs[])(win_t *) = { &quest_one, &quest_two, &quest_three,
    &quest_four, &quest_five, &quest_six, &quest_seven, &quest_eight,
    &quest_nine, &quest_ten, 0};
    int nb = 10;

    if (win->game->quest + 1 <= nb && (funcs[win->game->quest])(win)) {
        win->game->quest++;
        win->menu = 3;
    }
    if (win->game->quest + 1 > nb) {
        spawn_mobs(win, rand() % 25, rand() % 250);
    }
}

/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quest second part
*/

#include "rpg.h"

int quest_six(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (take_inv(ply->inventory, 1, ORE_IRON, 10) &&
    give_inv(ply->inventory, 2, ARROW, 32)) {
        return (1);
    }
    return (0);
}

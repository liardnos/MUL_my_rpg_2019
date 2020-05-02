/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quest one file
*/

#include "rpg.h"

int quest_one(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (give_inv(ply->inventory, 2, SWORD_WOOD, 1))
        return (1);
    return (1);
}

int quest_two(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    int ret = 0;

    for (int x = 0; x < 9; x++)
        if (ply->inventory[3][x])
            return (1);
    return (0);
}

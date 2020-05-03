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

    for (int x = 0; x < 9; x++)
        if (ply->inventory[3][x] == 24901 &&
        give_inv(ply->inventory, 2, PICKAXE_WOOD, 1))
                return (1);
    return (0);
}

int quest_three(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (take_inv(ply->inventory, 1, ORE_COAL, 5)) {
        win->game->skills++;
        return (1);
    }
    return (0);
}

int quest_four(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    
    if (!win->game->skills && give_inv(ply->inventory, 2, BOW, 1) &&
    give_inv(ply->inventory, 2, ARROW, 32))
        return (1);
    return (0);
}

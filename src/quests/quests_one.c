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

    if (give_inv(ply->inv, 2, STONE_SWORD, 1))
        return (1);
    return (1);
}

int quest_two(win_t *win)
{

}

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

int quest_seven(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (win->game->mob_kill >= 3) {
        replace_inv(ply->inventory, 250, 251);
        return (1);
    }
    return (0);
}

int quest_eight(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (take_inv(ply->inventory, 1, ORE_IRON, 32)) {
        replace_inv(ply->inventory, 237, 238);
        return (1);
    }
    return (0);
}

int quest_nine(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (win->game->mob_kill >= 10) {
        replace_inv(ply->inventory, 251, 252);
        return (1);
    }
    return (0);
}

int quest_ten(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (take_inv(ply->inventory, 1, ORE_DIAMOND, 32)) {
        replace_inv(ply->inventory, 238, 239);
        return (1);
    }
    return (0);
}

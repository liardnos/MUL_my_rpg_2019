/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "rpg.h"

int player_add_player(game_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (0);
    player->x = 10+1/3;
    player->y = 1/3+40;
    player->vx = 0;
    player->vy = 0;
    player->floor = 0;
    player->hp = 3;
    player->maxhp = 3;
    player->inventory = init_inventory();
    if (!player->inventory)
        return (0);
    lld_insert(game->players, 0, player);
    return (1);
}

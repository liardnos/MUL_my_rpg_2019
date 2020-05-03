/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "rpg.h"

const int backup[][10] =
{
    {0},
    {SWORD_WOOD, 0},
    {SWORD_WOOD, PICKAXE_WOOD, 0},
    {SWORD_WOOD, PICKAXE_WOOD, BOW, 0},
    {SWORD_WOOD, PICKAXE_WOOD, BOW, 0},
    {SWORD_STONE, PICKAXE_STONE, BOW, 0},
    {SWORD_STONE, PICKAXE_STONE, BOW, 0},
    {SWORD_IRON, PICKAXE_STONE, BOW, 0},
    {SWORD_IRON, PICKAXE_IRON, BOW, 0},
    {SWORD_DIAMOND, PICKAXE_IRON, BOW, 0},
    {SWORD_DIAMOND, PICKAXE_DIAMOND, BOW, 0},
    0
};

void player_quest_inv(game_t *game)
{
    const int *back = backup[game->quest];
    player_t *p = game->players->next->data;

    for (int i = 0; back[i]; i++)
        give_inv(p->inventory, 2, back[i], 1);
}


int player_add_player(game_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (0);
    player->x = HOME_X;
    player->y = HOME_Y;
    player->vx = -0.1;
    player->vy = -0.1;
    player->floor = 0;
    player->hp = 3;
    player->maxhp = 3;
    player->inventory = init_inventory();
    if (!player->inventory)
        return (0);
    lld_insert(game->players, 0, player);
    return (1);
}

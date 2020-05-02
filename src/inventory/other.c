/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Other funcs for utils
*/

#include "rpg.h"

void add_max(int *item, int *to_add)
{
    int tmp;

    if ((*to_add) % 100 <= 64 - ((*item) % 100)) {
        *item += (*to_add) % 100;
        *to_add = 0;
    } else {
        tmp = 64 - ((*item) % 100);
        *item += tmp;
        *to_add -= tmp;
    }
}

void clear_inventory(int **inventory)
{
    for (int y = 0; inventory[y]; y++)
        for (int x = 0; x < 9; x++)
            inventory[y][x] = 0;
}

void drop_inventory(game_t *game, int **inv)
{
    player_t *p = game->players->next->data;

    for (int y = 0; inv[y]; y++)
        for (int x = 0; x < 9; x++) {
            if (inv[y][x])
                engine_create_item(game, p->x, p->y, inv / 10000 % 10,
                inv[y][x] / 100 % 100, ITEM_DUR, inv[y][x] % 100);
        }
}

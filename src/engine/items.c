/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** engine items
*/

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"

int engine_create_item(game_t *game, float x, float y, ...)
{
    va_list va;
    item_t *item = malloc(sizeof(item_t));

    if (!item)
        return (0);
    item->x = x;
    item->y = y;
    item->vx = 0;
    item->vy = 0;
    va_start(va, y);
    item->type = va_arg(va, int);
    item->item = va_arg(va, int);
    item->life = va_arg(va, int);
    item->stack = va_arg(va, int);
    lld_insert(game->items, 0, item);
    return (1);
}

int engine_items(game_t *game)
{
    lld_t *lld = game->items;
    lld_t *lld_sup = lld_init();
    int i = 0;

    for (lld_t *mv = lld->next; mv; mv = mv->next, i++){
        item_t *item = mv->data;
        sfIntRect rect = {flr(item->x), flr(item->y+1), 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        (flr(item->y + item->vy/60.0) > flr(item->y)) && (block[0][0]->solid) ?
        item->vy = 0, item->y = flr(item->y)+0.99 : 0;
        free(block-1);
        item->life--;
        if (item->life <= 0)
            lld_insert(lld_sup, 0, (void *)(u64)i);
        engine_g(&(item->x), &(item->y), &(item->vx), &(item->vy));
        item->vx *= 0.8;
    }
    while (lld_sup->data)
        free(lld_pop(lld, (u64)lld_pop(lld_sup, 0)));
    lld_free(lld_sup);
}

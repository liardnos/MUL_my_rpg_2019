/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** engine main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"

//FIXME

int flr(float x)
{
    return (x >= 0 ? (int)x : (int)x-1);
}

void engine_g(float *x, float *y, float *vx, float *vy)
{
    *x += *vx/60.0;
    *y += *vy/60.0;
    *vx *= 0.9999;
    *vy *= 0.9999;
    *vy += GRAVITY/60.0;
    *y > 246 ? *vy = 0, *y = 246 : 0;
    *y < 10 ? *vy = 0, *y = 10 : 0;
}

void engine_get_items(game_t *game, player_t *player)
{
    lld_t *lld = game->items;
    lld_t *lld_sup = lld_init();
    int i = 0;

    for (lld_t *mv = lld->next; mv; mv = mv->next, i++){
        item_t *item = mv->data;
        if (fabsf(item->x - player->x) + fabs(item->y - player->y) < 2)
            if (give_inv(player->inventory, item->type, item->item, item->stack))
                lld_insert(lld_sup, 0, (void *)(u64)i);
    }
    while (lld_sup->data)
        free(lld_pop(lld, (u64)lld_pop(lld_sup, 0)));
    lld_free(lld_sup);
}

int engine(game_t *game, win_t *win)
{
    engine_player(game, win);
    engine_entities(game, win);
    engine_items(game);
    engine_proj(game);
}

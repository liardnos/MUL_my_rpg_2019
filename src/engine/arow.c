/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** engine projectiles
*/

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"

int engine_proj_colide_e(game_t *game, arrow_t *arow)
{
    lld_t *lld = game->entities;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *p = mv->data;
        float dx = fabsf(p->x -arow->x);
        float dy = fabsf(p->y -arow->y);
        if (dx < 0.33 && dy < 1){
            p->hp--;
            return (1);
        }
    }
    return (0);
}

int engine_proj_colide_p(game_t *game, arrow_t *arow)
{
    lld_t *lld = game->players;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        player_t *p = mv->data;
        float dx = fabsf(p->x -arow->x);
        float dy = fabsf(p->y -arow->y);
        if (dx < 0.33 && dy < 1){
            p->hp--;
            return (1);
        }
    }
    return (0);
}

int engine_proj(game_t *game)
{
    lld_t *lld = game->proj;
    lld_t *rm = lld_init();
    int i = 0;

    for (lld_t *mv = lld->next; mv; mv = mv->next, i++){
        arrow_t *arow = mv->data;
        sfIntRect rect = {flr(arow->x), flr(arow->y-0.5), 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        if (block[0][0]->solid){
            lld_insert(rm, 0, (void *)(u64)i);
            engine_create_item(game, arow->x, arow->y-0.5, 2, ARROW, 18000, 1);
            continue;
        }
        engine_g(&(arow->x), &(arow->y), &(arow->vx), &(arow->vy));
        free(block-1);
        arow->type == 0 ?
        engine_proj_colide_e(game, arow) ? lld_insert(rm, 0, (void *)(u64)i) : 0 :
        engine_proj_colide_p(game, arow) ? lld_insert(rm, 0, (void *)(u64)i) : 0;
    }
    while (rm->data)
        free(lld_pop(lld, (u64)lld_pop(rm, 0)));
    lld_free(rm);
}

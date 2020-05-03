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
    float h_head = 0;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *p = mv->data;
        float dx = fabsf(p->x -arow->x);
        float dy = fabsf(p->y -arow->y);
        if (dx < 0.33 && dy < 1){
            p->hp -= 1 * (1 + game->attack*0.2);
            animator_goto(p->anim, 5.0, ANIM_WALK1);
            return (1);
        }
    }
    return (0);
}

int engine_proj_colide_p(game_t *game, arrow_t *arow)
{
    lld_t *lld = game->players;
    float h_head = 0;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        player_t *p = mv->data;
        float dx = fabsf(p->x -arow->x);
        float dy = fabsf(p->y -arow->y);
        if (dx < 0.33 && dy < 1){
            p->hp--;
            animator_goto(p->anim, 5.0, ANIM_WALK1);
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
        arrow_t *p = mv->data;
        sfIntRect rect = {flr(p->x), flr(p->y-0.5), 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        if (block[0][0]->solid){
            lld_insert(rm, 0, (void *)(u64)i);
            engine_create_item(game, p->x, p->y-0.5, 2, ARROW, 18000, 1);
            continue;
        }
        engine_g(&(p->x), &(p->y), &(p->vx), &(p->vy));
        free(block-1);
        p->type == 0 ?
        engine_proj_colide_e(game, p) ? lld_insert(rm, 0, (void *)(u64)i) : 0 :
        engine_proj_colide_p(game, p) ? lld_insert(rm, 0, (void *)(u64)i) : 0;
    }
    while (rm->data) free(lld_pop(lld, (u64)lld_pop(rm, 0)));
    lld_free(rm);
}

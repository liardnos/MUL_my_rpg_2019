/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** engine entities
*/

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"

int engine_entities_b(game_t *game, win_t *win, entity_t *p, block_t ***b)
{
    flr(p->y + p->vy/60.0) < flr(p->y) && (b[1][0]->solid) ? p->vy = 0 : 0;
    b[1][2]->solid ? p->y-- : 0;
    (flr(p->y + p->vy/60.0 + 0.1) > flr(p->y)) && (b[1][3]->solid) ?
    p->y = flr(p->y)+0.99, p->floor = 1, p->vy >= JUMP_SPEED*1.5 ?
    p->hp -= p->vy/(JUMP_SPEED*2) : 0, p->vy = 0 : (p->floor = 0);
    engine_g(&(p->x), &(p->y), &(p->vx), &(p->vy));
    p->floor && fabsf(p->vx) > 1 ?
    particle_for_block(win, b[1][3]->type, p->x, p->y+0.5) :0;
    p->vx *= 0.8;
}

int engine_entities(game_t *game, win_t *win)
{
    lld_t *lld = game->entities;
    entity_t *p;
    block_t ***b;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        p = mv->data;
        sfIntRect rect = {flr(p->x) - 1, flr(p->y) - 2, 3, 5};
        b = generator_getmap(game->map, &rect);
        p->vx > 0 && (flr(p->x + p->vx/60.0 + 0.25) > flr(p->x)) &&
        (b[2][1]->solid || b[2][2]->solid) ?
        p->vx = 0, p->wall_r = 1 : (p->wall_r = 0);
        p->vx < 0 && (flr(p->x + p->vx/60.0 - 0.25) < flr(p->x)) &&
        (b[0][1]->solid || b[0][2]->solid) ?
        p->vx = 0, p->wall_l = 1 : (p->wall_l = 0);
        engine_entities_b(game, win, p, b);
        free(b-1);
    }
}

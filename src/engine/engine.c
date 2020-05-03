/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
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

int engine_player_b(game_t *game, win_t *win, player_t *p, block_t ***b)
{
    flr(p->y + p->vy/60.0 < flr(p->y)) && (b[1][0]->solid) ? p->vy = 0 : 0;
    b[1][2]->solid ? p->y-- : 0;
    (flr(p->y + p->vy/60.0+0.1) > flr(p->y)) && (b[1][3]->solid) ?
    p->y = flr(p->y)+0.99, p->floor = 1, p->vy >= JUMP_SPEED*1.5 ?
    p->hp -= p->vy/(JUMP_SPEED*2) : 0, p->vy = 0 : (p->floor = 0);
    engine_g(&(p->x), &(p->y), &(p->vx), &(p->vy));
    engine_get_items(game, p);
    p->floor && fabsf(p->vx) > 1 ?
    particle_for_block(win, b[1][3]->type, p->x, p->y+0.5) :0;
    p->vx *= 0.8;
}

int engine_player(game_t *game, win_t *win)
{
    lld_t *lld = game->players;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        player_t *p = mv->data;
        sfIntRect rect = {flr(p->x)-1, flr(p->y)-2, 3, 5};
        block_t ***b = generator_getmap(game->map, &rect);
        p->vx > 0 && (flr(p->x + p->vx/60.0 + 0.25) > flr(p->x)) &&
        (b[2][1]->solid || b[2][2]->solid) ? p->vx = 0 : 0;
        p->vx < 0 && (flr(p->x + p->vx/60.0 - 0.25) < flr(p->x)) &&
        (b[0][1]->solid || b[0][2]->solid) ? p->vx = 0 : 0;
        engine_player_b(game, win, p, b);
        free(b-1);
    }
}

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

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *p = mv->data;
        sfIntRect rect = {flr(p->x)-1, flr(p->y)-2, 3, 5};
        block_t ***b = generator_getmap(game->map, &rect);
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
        sfIntRect rect = {flr(arow->x), flr(arow->y), 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        if (block[0][0]->solid){
            lld_insert(rm, 0, (void *)(u64)i);
            engine_create_item(game, arow->x, arow->y-1, 2, ARROW, 18000, 1);
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

int engine(game_t *game, win_t *win)
{
    engine_player(game, win);
    engine_entities(game, win);
    engine_items(game);
    engine_proj(game);
}

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

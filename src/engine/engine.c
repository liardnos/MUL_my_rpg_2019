/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"


int flr(float x)
{
    return (x >= 0 ? (int)x : (int)x-1);
}

void engine_g(float *x, float *y, float *vx, float *vy)
{
    *x += *vx/60.0;
    *y += *vy/60.0;
    *vx *= 0.99;
    *vy *= 0.99;
    *vy += GRAVITY/60.0;
    *vx *= 0.8;
}

void engine_get_items(game_t *game, player_t *player)
{
    lld_t *lld = game->items;
    int i = 0;
    for (lld_t *mv = lld->next; mv; mv = mv->next, i++){
        item_t *item = mv->data;
        if (fabsf(item->x - player->x) + fabs(item->y - player->y) < 2)
            if (give_inv(player->inventory, item->type, item->item, item->stack))
                free(lld_pop(lld, i));

    }
}


int engine_player(game_t *game)
{
    lld_t *lld = game->players;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        player_t *player = mv->data;
        sfIntRect rect = {flr(player->x)-1, flr(player->y)-2, 3, 5};
        block_t ***block = generator_getmap(game->map, &rect);
        player->vx > 0 && (flr(player->x + player->vx/60.0 + 0.25) > flr(player->x)) && (block[2][1]->solid || block[2][2]->solid) ?
        player->vx = 0 : 0;
        player->vx < 0 && (flr(player->x + player->vx/60.0 - 0.25) < flr(player->x)) && (block[0][1]->solid || block[0][2]->solid) ?
        player->vx = 0 : 0;
        (flr(player->y + player->vy/60.0) < flr(player->y)) && (block[1][0]->solid) ?
        player->vy = 0 : 0 ;
        block[1][2]->solid ? player->y-- : 0;
        (flr(player->y + player->vy/60.0) > flr(player->y)) && (block[1][3]->solid) ?
        player->vy = 0, player->y = flr(player->y)+0.99, player->floor = 1 : (player->floor = 0);
        free(block-1);
        engine_g(&(player->x), &(player->y), &(player->vx), &(player->vy));
        engine_get_items(game, player);
    }
}

int engine_entities(game_t *game)
{
    lld_t *lld = game->entities;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *player = mv->data;
        sfIntRect rect = {flr(player->x)-1, flr(player->y)-2, 3, 5};
        block_t ***block = generator_getmap(game->map, &rect);
        player->vx > 0 && (flr(player->x + player->vx/60.0 + 0.25) > flr(player->x)) && (block[2][1]->solid || block[2][2]->solid) ?
        player->vx = 0 : 0;
        player->vx < 0 && (flr(player->x + player->vx/60.0 - 0.25) < flr(player->x)) && (block[0][1]->solid || block[0][2]->solid) ?
        player->vx = 0 : 0;
        (flr(player->y + player->vy/60.0) < flr(player->y)) && (block[1][0]->solid) ?
        player->vy = 0 : 0 ;
        block[1][2]->solid ? player->y-- : 0;
        (flr(player->y + player->vy/60.0) > flr(player->y)) && (block[1][3]->solid) ?
        player->vy = 0, player->y = flr(player->y)+0.99, player->floor = 1 : (player->floor = 0);
        free(block-1);
        engine_g(&(player->x), &(player->y), &(player->vx), &(player->vy));
    }
}

int engine_items(game_t *game)
{
    lld_t *lld = game->entities;
    int i = 0;

    for (lld_t *mv = lld->next; mv; mv = mv->next, i++){
        item_t *item = mv->data;
        engine_g(&(item->x), &(item->y), &(item->vx), &(item->vy));
        sfIntRect rect = {item->y, item->x, 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        if (block[0][0]->solid == 1){
            item->vy = 0;
            item->vx *= 0.9;
            item->y = (int)item->y + 1;
        }
        free(block-1);
        item->life--;
        if (item->life <= 0)
            lld_pop(lld, i), i--;
    }
}

int engine(game_t *game)
{
    engine_player(game);
    engine_entities(game);
    engine_items(game);
}

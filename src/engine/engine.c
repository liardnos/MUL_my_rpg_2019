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

void engine_g(float *x, float *y, float *vx, float *vy)
{
    *x += *vx;
    *y += *vy;
    *vx *= 0.99;
    *vy *= 0.99;
    *vy += GRAVITY/60;
}

int engine_player(game_t *game)
{
    lld_t *lld = game->players;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        player_t *player = mv->data;
        engine_g(&(player->x), &(player->y), &(player->vx), &(player->vy));
        sfIntRect rect = {player->y, player->x, 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        if (block[0][0]->solid == 1){
            player->vy > 10 ? player->hp -= 1 : 0;
            player->vy = 0;
            player->vx *= 0.9;
            player->y = (int)player->y + 1;
        }
        free(block);
    }
}

int engine_entities(game_t *game)
{
    lld_t *lld = game->entities;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *entity = mv->data;
        engine_g(&(entity->x), &(entity->y), &(entity->vx), &(entity->vy));
        sfIntRect rect = {entity->y, entity->x, 1, 1};
        block_t ***block = generator_getmap(game->map, &rect);
        if (block[0][0]->solid == 1){
            entity->vy = 0;
            entity->vx *= 0.9;
            entity->y = (int)entity->y + 1;
        }
        free(block);
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
        free(block);
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

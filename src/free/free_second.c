/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Second file for free
*/

#include "rpg.h"

void free_players(game_t *cpy)
{
    player_t *p;

    while (cpy->players->data){
        p = lld_pop(cpy->players, 0);
        animator_free(p->anim);
        free_inventory(p->inventory);
        free(p);
    }
    lld_free(cpy->players);
}

void free_entities(game_t *cpy)
{
    entity_t *p;

    while (cpy->entities->data){
        p = lld_pop(cpy->entities, 0);
        animator_free(p->anim);
        free(p);
    }
    lld_free(cpy->entities);
}

void free_game_b(game_t *cpy)
{
    free_players(cpy);
    free_entities(cpy);
    lld_free_r(cpy->items);
    lld_free_r(cpy->proj);
}

void free_body(body_t *body)
{
    free_texture(body->arm);
    free_texture(body->leg);
    free_texture(body->head);
    free_texture(body->body);
    sfSprite_destroy(body->arm_l);
    sfSprite_destroy(body->leg_l);
    free(body);
}

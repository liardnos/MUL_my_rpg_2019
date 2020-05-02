/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func for png
*/

#include <math.h>
#include "rpg.h"

int mob_pnj_add(game_t *game, sfVector2f pos)
{
    entity_t *pnj = malloc(sizeof(entity_t));
    if (!pnj) return (0);

    pnj->x = 10;
    pnj->y = HOME_X;
    pnj->hp = 200000000;
    pnj->floor = 0;
    pnj->vx = 0;
    pnj->vy = 0;
    pnj->type = 3;
    pnj->anim_sate = 0;
    pnj->anim = init_pnj_animator();
    lld_insert(game->entities, 0, pnj);
}

void mob_pnj(game_t *game, entity_t *pnj)
{
    player_t *p = game->players->next->data;
    float dx = pnj->x - p->x;

    if (dx < 0 && fabsf(dx) > 20.0){
        pnj->vx = 3;
        pnj->wall_r & 1 && pnj->floor ? pnj->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 20.0){
        pnj->vx = -3;
        pnj->wall_l & 1 && pnj->floor ? pnj->vy = -JUMP_SPEED : 0;
    }
}

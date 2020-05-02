/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func for zombie
*/

#include <math.h>
#include "rpg.h"

int mob_zombie_add(game_t *game, sfVector2f pos)
{
    entity_t *zomb = malloc(sizeof(entity_t));

    if (!zomb) return (0);
    zomb->x = pos.x;
    zomb->y = pos.y;
    zomb->vx = 0;
    zomb->vy = 0;
    zomb->floor = 0;
    zomb->anim = init_zombie_animator();
    zomb->anim_sate = 0;
    zomb->hp = 20;
    zomb->type = 1;
    lld_insert(game->entities, 0, zomb);
}

int mob_skeleton_add(game_t *game, sfVector2f pos)
{
    entity_t *zomb = malloc(sizeof(entity_t));

    if (!zomb) return (0);
    zomb->x = pos.x;
    zomb->y = pos.y;
    zomb->vx = 0;
    zomb->vy = 0;
    zomb->floor = 0;
    zomb->anim = init_skeleton_animator();
    zomb->anim_sate = 0;
    zomb->hp = 20;
    zomb->type = 2;
    lld_insert(game->entities, 0, zomb);
}

void mob_zombie(game_t *game, entity_t *zomb)
{
    player_t *p = game->players->next->data;
    float dx = zomb->x - p->x;

    if (dx < 0 && fabsf(dx) > 1.0){
        zomb->vx = 3;
        zomb->wall_r & 1 ? zomb->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 1.0){
        zomb->vx = -3;
        zomb->wall_l & 1 ? zomb->vy = -JUMP_SPEED : 0;
    }
}

void mob_skeleton(game_t *game, entity_t *skel)
{
    player_t *p = game->players->next->data;
    float dx = skel->x - p->x;

    if (dx < 0 && fabsf(dx) > 5.0){
        skel->vx = 3;
        skel->wall_r & 1 ? skel->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 5.0){
        skel->vx = -3;
        skel->wall_l & 1 ? skel->vy = -JUMP_SPEED : 0;
    }
}

void mob(win_t *win)
{
    lld_t *lld = win->game->entities;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *entity = mv->data;
        entity->type == 1 ? mob_zombie(win->game, entity) :
        entity->type == 2 ? mob_skeleton(win->game, entity) :
        0;

    }
}

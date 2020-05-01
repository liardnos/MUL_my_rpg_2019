/*
** EPITECH PROJECT, 2020
**
** File description:
** func for zombie
*/

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

void mob_zombie(game_t *game, entity_t *zomb)
{
    player_t *p = game->players->next->data;
    float dx = zomb->x - p->x;

    if (dx < 0){
        zomb->vx = 3;
        zomb->wall_r & 1 ? zomb->vy = -JUMP_SPEED : 0;
    } else {
        zomb->vx = -3;
        zomb->wall_l & 1 ? zomb->vy = -JUMP_SPEED : 0;
    }
}

void mob(win_t *win)
{
    lld_t *lld = win->game->entities;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *entity = mv->data;

        entity->type == 1 ? mob_zombie(win->game, entity) :
        0;

    }
}

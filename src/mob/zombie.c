/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func for zombie
*/

#include <math.h>
#include "rpg.h"

//FIXME

int mob_zombie_add(game_t *game, sfVector2f pos)
{
    entity_t *zomb = malloc(sizeof(entity_t));

    if (!zomb) return (0);
    zomb->x = pos.x;
    zomb->y = pos.y;
    zomb->vx = 0;
    zomb->vy = 0;
    zomb->floor = 0;
    zomb->anim = init_zombie_animator(game);
    zomb->anim_sate = 0;
    zomb->hp = 5;
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
    zomb->anim = init_skeleton_animator(game);
    zomb->anim_sate = 0;
    zomb->hp = 2;
    zomb->type = 2;
    lld_insert(game->entities, 0, zomb);
}

void mob_zombie(game_t *game, entity_t *zomb)
{
    player_t *p = game->players->next->data;
    float dx = zomb->x - p->x;
    float dy = zomb->y - p->y;
    static int dmg = 0;

    if (dx < 0 && fabsf(dx) > 0.5){
        zomb->vx = 3;
        zomb->wall_r & 1 && zomb->floor ? zomb->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 0.5){
        zomb->vx = -3;
        zomb->wall_l & 1 && zomb->floor ? zomb->vy = -JUMP_SPEED : 0;
    }
    if (fabsf(dx) < 0.5 && fabsf(dy) < 1)
        dmg < 60 ? dmg++ : (dmg = 0, p->hp--);

}

void mob_skeleton(game_t *game, entity_t *skel)
{
    player_t *p = game->players->next->data;
    float dx = skel->x - p->x;
    float dy = skel->y - p->y;
    static int dmg = 0;

    if (dx < 0 && fabsf(dx) > 7.5){
        skel->vx = 3;
        skel->wall_r & 1 && skel->floor ? skel->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 7.5){
        skel->vx = -3;
        skel->wall_l & 1 && skel->floor ? skel->vy = -JUMP_SPEED : 0;
    }
    if (fabsf(dx) < 10 && fabsf(dy) < 10 && dmg >= 199){
        arrow_t *arrow = malloc(sizeof(arrow_t));
        if (!arrow) return;
        arrow->x = skel->x;
        arrow->y = skel->y-0.10;
        arrow->vx = -dx * 2 + ((rand()%100)/100.0-0.5)*2;
        arrow->vy = -dy * 2 + ((rand()%100)/100.0-0.5)*2;
        arrow->type = 2;
        lld_insert(game->proj, 0, arrow);
        dmg = 0;
    }
    fabsf(dx) < 10 && fabsf(dy) < 10 ? dmg++ : 0;
}

void mob(win_t *win)
{
    lld_t *lld = win->game->entities;
    int i = 0;
    lld_t *rm = lld_init();
    entity_t *entity;

    for (lld_t *mv = lld->next; mv; mv = mv->next, i++){
        entity = mv->data;
        entity->type == 1 ? mob_zombie(win->game, entity) :
        entity->type == 2 ? mob_skeleton(win->game, entity) :
        entity->type == 3 ? mob_pnj(win, entity) :
        0;
        if (entity->hp <= 0)
            lld_insert(rm, 0, (void *)(u64)i);
    }
    while (rm->data){
        entity = lld_pop(lld, (u64)lld_pop(rm, 0));
        animator_free(entity->anim);
        free(entity);
    }
    lld_free(rm);
}

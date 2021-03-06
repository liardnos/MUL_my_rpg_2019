/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func for zombie
*/

#include <math.h>
#include "rpg.h"

void mob_zombie(game_t *game, entity_t *zomb)
{
    player_t *p = game->players->next->data;
    float dx = zomb->x - p->x;
    float dy = zomb->y - p->y;
    static int dmg = 0;

    if (dx < 0 && fabsf(dx) > 0.5){
        zomb->vx = 3 + rand() % 1000 / 1000.0;
        zomb->wall_r & 1 && zomb->floor ? zomb->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 0.5){
        zomb->vx = -3 - rand() % 1000 / 1000.0;
        zomb->wall_l & 1 && zomb->floor ? zomb->vy = -JUMP_SPEED : 0;
    }
    if (fabsf(dx) < 0.5 && fabsf(dy) < 1)
        dmg < 60 * (1 + 0.1 * game->shield) ? dmg++ : (dmg = 0, p->hp--);
}

void mob_skeleton(game_t *game, entity_t *skel)
{
    player_t *p = game->players->next->data;
    float dx = skel->x - p->x;
    float dy = skel->y - p->y;
    static int dmg = 0;
    if (dx < 0 && fabsf(dx) > 7.5){
        skel->vx = 3 + rand() % 1000 / 1000.0;
        skel->wall_r & 1 && skel->floor ? skel->vy = -JUMP_SPEED : 0;
    } else if (fabsf(dx) > 7.5){
        skel->vx = -3 - rand() % 1000 / 1000.0;
        skel->wall_l & 1 && skel->floor ? skel->vy = -JUMP_SPEED : 0;
    }
    if (fabsf(dx) < 15 && fabsf(dy) < 15 && dmg >= 199){
        arrow_t *arrow = malloc(sizeof(arrow_t));
        if (!arrow) return;
        arrow->x = skel->x, arrow->y = skel->y-0.50;
        arrow->vx = -dx * 2 + ((rand()%100)/100.0-0.5)*2;
        arrow->vy = -dy * 2 + ((rand()%100)/100.0-0.5)*2;
        arrow->type = 2, dmg = 0, lld_insert(game->proj, 0, arrow);
    }
    fabsf(dx) < 15 && fabsf(dy) < 15 ? dmg++ : 0;
}

void mob_delete(win_t *win, lld_t *rm)
{
    entity_t *en;
    lld_t *lld = win->game->entities;

    while (rm->data){
        en = lld_pop(lld, (u64)lld_pop(rm, 0));
        animator_free(en->anim);
        win->game->skills += 0.2, win->game->mob_kill++;
        en->type == 2 ? engine_create_item(win->game, en->x, en->y, 2,
        ARROW, 36000, rand()%5+1) : 0;
        free(en);
    }
    lld_free(rm);
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
        entity->type == 3 ? mob_pnj(win, entity) : 0;
        if (entity->hp <= 0)
            lld_insert(rm, 0, (void *)(u64)i);
    }
    mob_delete(win, rm);
}

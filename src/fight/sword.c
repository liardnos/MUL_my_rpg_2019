/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fighting mecanics
*/

#include <stdlib.h>
#include <math.h>
#include "rpg.h"

void fight_sword_wood(win_t *win, player_t *p)
{
    lld_t *lld = win->game->entities;
    static int cool = 0;
    float h_head = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) && cool >= 10){
        cool = 0;
        for (lld_t *mv = lld->next; mv; mv = mv->next){
            entity_t *ent = mv->data;
            float dx = ent->x - p->x;
            float dy = ent->y - p->y;
            if (fabsf(dx) < 2 && fabsf(dx) < 2){
                ent->hp -= 1 * (1+win->game->attack*0.2);
                animator_goto(p->anim, 5.0, ANIM_WALK1);
                animator_goto(ent->anim, 5.0, ANIM_WALK1);
            }
        }
    }
    cool++;
}

void fight_sword_stone(win_t *win, player_t *p)
{
    lld_t *lld = win->game->entities;
    static int cool = 0;
    float h_head = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) && cool >= 10){
        cool = 0;
        for (lld_t *mv = lld->next; mv; mv = mv->next){
            entity_t *ent = mv->data;
            float dx = ent->x - p->x;
            float dy = ent->y - p->y;
            if (fabsf(dx) < 2 && fabsf(dx) < 2){
                ent->hp -= 2 * (1+win->game->attack*0.2);
                animator_goto(p->anim, 5.0, ANIM_WALK1);
                animator_goto(ent->anim, 5.0, ANIM_WALK1);
            }
        }
    }
    cool++;
}

void fight_sword_iron(win_t *win, player_t *p)
{
    lld_t *lld = win->game->entities;
    static int cool = 0;
    float h_head = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) && cool >= 10){
        cool = 0;
        for (lld_t *mv = lld->next; mv; mv = mv->next){
            entity_t *ent = mv->data;
            float dx = ent->x - p->x;
            float dy = ent->y - p->y;
            if (fabsf(dx) < 2 && fabsf(dx) < 2){
                ent->hp -= 3 * (1+win->game->attack*0.2);
                animator_goto(p->anim, 5.0, ANIM_WALK1);
                animator_goto(ent->anim, 5.0, ANIM_WALK1);
            }
        }
    }
    cool++;
}

void fight_sword_diamond(win_t *win, player_t *p)
{
    lld_t *lld = win->game->entities;
    static int cool = 0;
    float h_head = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) && cool >= 10){
        cool = 0;
        for (lld_t *mv = lld->next; mv; mv = mv->next){
            entity_t *ent = mv->data;
            float dx = ent->x - p->x;
            float dy = ent->y - p->y;
            if (fabsf(dx) < 2 && fabsf(dx) < 2){
                ent->hp -= 4 * (1+win->game->attack*0.2);
                animator_goto(p->anim, 5.0, ANIM_WALK1);
                animator_goto(ent->anim, 5.0, ANIM_WALK1);
            }
        }
    }
    cool++;
}

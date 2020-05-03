/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"

int animator_setpos(animator_t *anim, pos_t *pos)
{
    free(anim->pos);
    anim->pos = pos;
}

int animator_draw(sfRenderWindow *window, animator_t *anim)
{
    for (lld_t *mv = anim->member->next; mv; mv = mv->next){
        member_t *member = mv->data;
        sfSprite *sprite = member->sprite;
        sfVector2f vec[] = {member->pos->x + anim->pos->x, member->pos->y
        + anim->pos->y};

        sfSprite_setPosition(sprite, *vec);
        sfSprite_setRotation(sprite, member->pos->a);
        sfRenderWindow_drawSprite(window, sprite, 0);
    }
}

void animator_free(animator_t *anim)
{
    for (lld_t *mv = anim->member->next; mv; mv = mv->next){
        member_t *member = mv->data;
        free(member->pos);
        free(member->pos2);
        free(member->pos3);
        free(member);
    }
    lld_free(anim->member);
    free(anim->pos);
    free(anim);
}

int animator_animate(animator_t *anim)
{
    for (lld_t *mv = anim->member->next; mv; mv = mv->next){
        member_t *mbr = mv->data;
        float v = anim->dtime * mbr->ag;
        if (anim->time/2 >   anim->dtime)
            mbr->pos->a = mbr->pos3->a + v * anim->dtime/2;
        else
            mbr->pos->a = mbr->pos3->a + v * anim->dtime/2 -
            pow((anim->dtime - anim->time/2), 2) * mbr->ag;
    }
    if (anim->time > anim->dtime){
        anim->dtime++;
        return (1);
    }
    return (0);
}

int animator_goto(animator_t *anim, ...)
{
    va_list va;

    va_start(va, anim);
    anim->time = va_arg(va, double);
    anim->dtime = 0;
    for (lld_t *mv = anim->member->next; mv; mv = mv->next){
        member_t *mbr = mv->data;
        mbr->pos3->a = mbr->pos->a;
        mbr->pos2->a = va_arg(va, double);
        float d = mbr->pos->a - mbr->pos2->a;
        mbr->ag = -d/pow(anim->time/2, 2);
    }
}

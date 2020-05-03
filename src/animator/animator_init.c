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

animator_t *animator_init(void)
{
    animator_t *anim = malloc(sizeof(animator_t));

    if (!anim)
        return (0);
    anim->member = lld_init();
    anim->time = 0;
    anim->dtime = 0;
    if (!anim->member)
        return (0);
    anim->pos = malloc(sizeof(pos_t));
    return (anim);
}

int animator_addmenber(animator_t *anim, pos_t *pos, sfSprite *sprite)
{
    member_t *m = malloc(sizeof(member_t));

    m->pos2 = malloc(sizeof(pos_t));
    m->pos3 = malloc(sizeof(pos_t));
    if (!m->pos2 || !m->pos3)
        return (0);
    m->pos2->x = pos->x, m->pos2->y = pos->y, m->pos2->a = pos->a;
    m->pos3->x = pos->x, m->pos3->y = pos->y, m->pos3->a = pos->a;
    if (!m)
        return (0);
    m->ag = 0;
    m->pos = pos;
    m->sprite = sprite;
    lld_insert(anim->member, (u64)anim->member->data, m);
    return (1);
}

pos_t *mpos(float x, float y, float a)
{
    pos_t *pos = malloc(sizeof(pos_t));

    if (!pos)
        return (0);
    pos->x = x;
    pos->y = y;
    pos->a = a;
    return (pos);
}

sfVector2f alloc_vector2f(float x, float y)
{
    static sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

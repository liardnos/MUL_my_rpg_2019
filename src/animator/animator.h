/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include <SFML/Graphics.h>
#include "my.h"

typedef struct pos
{
    float x;
    float y;
    float a;
} pos_t;

typedef struct member
{
    sfSprite *sprite;
    pos_t *pos;
    pos_t *pos2;
    pos_t *pos3;
    float ag;
} member_t;

typedef struct animator
{
    lld_t *member;
    pos_t *pos;
    float time;
    float dtime;
} animator_t;

animator_t *animator_init();
int animator_setpos(animator_t *anim, pos_t *coor);
int animator_addmenber(animator_t *anim, pos_t *pos, sfSprite *sprite);

pos_t *malloc_pos(float x, float y, float a);
sfVector2f malloc_vector2f(float x, float y);
int animator_draw(sfRenderWindow *window, animator_t *anim);
int animator_animate(animator_t *anim);
int animator_goto(animator_t *anim, ...);

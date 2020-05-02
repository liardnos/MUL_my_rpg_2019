/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle main
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "rpg.h"
#include <stdlib.h>
#include <stdarg.h>

lld_t *particle_array()
{
    return (lld_init());
}

void particle_for_block(win_t *win, int item, float x, float y)
{
    sfVector2f scale = {(rand()%100+1)/500.0, 0};
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {item*64, 0, 64, 64};

    scale.y = scale.x;
    if (!sprite) return;
    sfSprite_setTexture(sprite, win->game->bl->tex, 0);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, scale);
    particle_add(win->particles, (double)x, (double)y,
    (double)((rand()%100-50)/100.0), (double)((rand()%100-50)/100.0-1),
    (double)0, (double)0, (int)15, (void *)sprite);
}

void particle_add(lld_t *p_lld, ...)
{
    particle_t *p = malloc(sizeof(particle_t));
    va_list va;

    if (!p) return;
    va_start(va, p_lld);
    p->x = va_arg(va, double);
    p->y = va_arg(va, double);
    p->vx = va_arg(va, double);
    p->vy = va_arg(va, double);
    p->a = va_arg(va, double);
    p->va = va_arg(va, double);
    p->life = va_arg(va, int);
    p->sprite = va_arg(va, void *);
    lld_insert(p_lld, (u64)p_lld->data, p);
}

void particles_draw(win_t *win, lld_t *p_lld)
{
    lld_t *mov = p_lld->next;
    int i = 0;
    player_t *play = win->game->players->next->data;

    for (; mov; mov = mov->next, i++){
        particle_t *p = mov->data;
        sfVector2f v = {p->x*64 - play->x*64 + 1920/2, p->y*64 - play->y*64 + 1080/2};
        sfSprite_setPosition(p->sprite, v);
        sfSprite_setRotation(p->sprite, p->a);
        sfRenderWindow_drawSprite(win->win, p->sprite, 0);
        p->x += p->vx, p->y += p->vy, p->a += p->va;
        p->vy += GRAVITY/60.0;
        if (p->life == 0){
            mov = mov->prev ? mov->prev : p_lld;
            particle_t *par = lld_pop(p_lld, i);
            sfSprite_destroy(par->sprite);
            free(par);
            i--;
        } else
            p->life--;
    }
}

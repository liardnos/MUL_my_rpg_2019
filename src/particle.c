/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle main
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "particle.h"

lld_t *particle_array()
{
    return (lld_init());
}

void particle_add(lld_t *p_lld, particle_t *p)
{
    lld_insert(p_lld, p_lld->data, p);
}

void particles_draw(sfRenderWindow *win, lld_t *p_lld)
{
    lld_t *mov = p_lld->next;
    int i = 0;
    for (; mov; mov = mov->next, i++){
        particle_t *p = mov->data;
        sfVector2f v[] = {p->x, p->y};
        sfSprite_setPosition(p->sprite, *v);
        sfSprite_setRotation(p->sprite, p->a);
        sfRenderWindow_drawSprite(win, p->sprite, 0);
        p->x += p->vx;
        p->y += p->vy;
        p->a += p->va;
        if (p->life == 0){
            mov = mov->prev ? mov->prev : p_lld;
            lld_pop(p_lld, i);
            i--;
        }
        p->life--;
    }
}

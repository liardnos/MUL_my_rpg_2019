/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main for my_rpg
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "particle.h"

int main(int ac, char **av)
{
    sfVideoMode mode = {1024, 1024, 32};
    sfTexture *texture = sfTexture_create(mode.width, mode.height);
    sfRenderWindow *window = sfRenderWindow_create(mode, "hi", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);

    lld_t *ps = particle_array();
    sfTexture *swirl_blue = sfTexture_createFromFile("data/PNG/Particles/swirl_blue.png", 0);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, swirl_blue, sfTrue);
    sfVector2f v[] = {0.25, 0.25};
    sfSprite_setScale(sprite, *v);
    while (1){
        my_printf("FRAME\n");
        particle_t *p = malloc(sizeof(particle_t));
        sfVector2i vv = sfMouse_getPositionRenderWindow(window);
        p->x = vv.x;
        p->vx = (rand()%100-50)/100.0;
        p->y = vv.y;
        p->vy = (rand()%100-50)/100.0;
        p->a = (rand()%100-50);
        p->va = rand()%100/100.0;
        p->life = rand()%1000;
        p->sprite = sprite;
        particle_add(ps, p);
        sfRenderWindow_clear(window, sfBlack);
        particles_draw(window, ps);
        sfRenderWindow_display(window);
    }
    return (0);
}

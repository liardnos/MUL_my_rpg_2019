/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main for my_rpg
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "particle.h"
#include "rpg.h"

int main(int ac, char **av)
{
<<<<<<< HEAD
    int map_x = 129;
    int map_y = 64;

=======
    printf("%i %i\n", TORCH, ARROW);
>>>>>>> 3a47b6bc2f890f3297de34ed5fec5908061d1668
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

    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f rect_size[] = {8, 8};
    sfRectangleShape_setSize(rect, *rect_size);
    /*
    float **mesh = create_mesh(0, 0, map_x, map_y, 6);
    block_t ***map = malloc(sizeof(void **) * (map_x+1));
    map[map_x] = 0;
    for (int i = 0; i < map_x; i++){
        map[i] = malloc(sizeof(void *) * (map_y+1));
        map[i][map_y] = 0;
        for (int ii = 0; ii < map_y; ii++){
            map[i][ii] = (void *)(u64)calc_block(mesh[i][ii]);
            ((u64)map[i][ii]->type == 1 && rand() % 50 == 0) ? map[i][ii] = blocks[4] : 0;
            ((u64)map[i][ii]->type == 1 && rand() % 100 == 0) ? map[i][ii] = blocks[5] : 0;
            ((u64)map[i][ii]->type == 1 && rand() % 200 == 0) ? map[i][ii] = blocks[6] : 0;
        }
    }
    */
    lld_t *map = lld_init();
    float player_x = 0;
    lld_insert(map, 0, generate_line((u64)player_x, 6));
    lld_t *here = map->next;
    int frame = 0;
    while (1){
        my_printf("FRAME %i\n", frame++);
        /*
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
        */
        lld_t *here_mv = here;
        for (int i = 0; i < map_x; i++, here_mv = here_mv->next){
            if (here_mv->next == 0)
                lld_insert(map, (u64)map->data, generate_line((u64)player_x+i, 6));
            if (here_mv->prev == 0)
                lld_insert(map, 0, generate_line((u64)player_x+i, 6));
            block_t **line = here_mv->data;
            for (int ii = 0; ii < map_y; ii++){
                sfVector2f vect[] = {8*(i+(int)player_x-player_x), ii*8};
                sfRectangleShape_setPosition(rect, *vect);
                sfRectangleShape_setFillColor(rect, line[ii]->color);
                sfRenderWindow_drawRectangleShape(window, rect, 0);
            }
        }
        if ((int)player_x < (int)(player_x+0.1))
            here = here->next;
        player_x += 0.1;
        //particles_draw(window, ps);
        sfRenderWindow_display(window);
    }
    return (0);
}

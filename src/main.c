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
    sfVideoMode mode = {1024, 1024, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "hi", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);

    int map_x = 129;
    int map_y = 128;

    sfTexture *t_head = sfTexture_createFromFile("assets/Characters/Player male/male_head.png", 0);
    sfTexture *t_body = sfTexture_createFromFile("assets/Characters/Player male/male_body.png", 0);
    sfTexture *t_arm = sfTexture_createFromFile("assets/Characters/Player male/male_arm.png", 0);
    sfTexture *t_leg = sfTexture_createFromFile("assets/Characters/Player male/male_leg.png", 0);

    sfSprite *s_head = sfSprite_create();
    sfSprite *s_body = sfSprite_create();
    sfSprite *s_arm_l = sfSprite_create();
    sfSprite *s_arm_r = sfSprite_create();
    sfSprite *s_leg_l = sfSprite_create();
    sfSprite *s_leg_r = sfSprite_create();

    sfSprite_setTexture(s_head, t_head, sfTrue);
    sfSprite_setTexture(s_body, t_body, sfTrue);
    sfSprite_setTexture(s_arm_l, t_arm, sfTrue);
    sfSprite_setTexture(s_arm_r, t_arm, sfTrue);
    sfSprite_setTexture(s_leg_l, t_leg, sfTrue);
    sfSprite_setTexture(s_leg_r, t_leg, sfTrue);

    sfSprite_setOrigin(s_head, alloc_vector2f(32, 64));
    sfSprite_setOrigin(s_body, alloc_vector2f(22, 30));
    sfSprite_setOrigin(s_arm_l, alloc_vector2f(14, 0));
    sfSprite_setOrigin(s_arm_r, alloc_vector2f(14, 0));
    sfSprite_setOrigin(s_leg_l, alloc_vector2f(14, -14));
    sfSprite_setOrigin(s_leg_r, alloc_vector2f(14, -14));

    animator_t *me = animator_init();
    animator_addmenber(me, malloc_pos(0, -22, 45), s_arm_l);
    animator_addmenber(me, malloc_pos(0, 20, 45), s_leg_l);
    animator_addmenber(me, malloc_pos(0, -30, 10), s_head);
    animator_addmenber(me, malloc_pos(0, 0, 0), s_body);
    animator_addmenber(me, malloc_pos(0, 20, -45), s_leg_r);
    animator_addmenber(me, malloc_pos(0, -22, -45), s_arm_r);

    animator_setpos(me, malloc_pos(300, 300, 0));


    /*
    for (int j = 0; j < 10; j++){
        for (int i = 0; i < 15; i++){
            sfRenderWindow_clear(window, sfBlack);
            animator_animate(me);
            animator_draw(window, me);
            sfRenderWindow_display(window);
        }
        animator_goto(me, 15.0, 45.0, -45.0, 10.0, 0.0, 45.0, -45.0);
        for (int i = 0; i < 15; i++){
            sfRenderWindow_clear(window, sfBlack);
            animator_animate(me);
            animator_draw(window, me);
            sfRenderWindow_display(window);
        }
        animator_goto(me, 15.0, -45.0, 45.0, -10.0, 0.0, -45.0, 45.0);
    }
    */

    animator_free(me);
    //sfRenderWindow_destroy(window);
    sfTexture_destroy(t_head);
    sfTexture_destroy(t_body);
    sfTexture_destroy(t_arm);
    sfTexture_destroy(t_leg);
    //return (0);

    //printf("%i %i\n", TORCH, ARROW);

    lld_t *ps = particle_array();
    sfTexture *swirl_blue = sfTexture_createFromFile("data/PNG/Particles/swirl_blue.png", 0);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, swirl_blue, sfTrue);
    sfVector2f v[] = {0.25, 0.25};
    sfSprite_setScale(sprite, *v);

    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f rect_size[] = {7, 7};
    sfRectangleShape_setSize(rect, *rect_size);
    sfRectangleShape_setFillColor(rect, sfBlue);

    float player_x = 0;
    int frame = 0;
    map_t *map = generate_map();
    while (1){
        printf("FRAME %i\n", frame++);
        sfIntRect re = {-128+frame/5, 0, 128, 128};
        block_t ***block = generator_getmap(map, &re);

        for (int x = 0; x < 128; x++)
            for (int y = 0; y < 128; y++){
                sfVector2f vect[] = {8*x, 8*y};
                sfRectangleShape_setPosition(rect, *vect);
                sfRectangleShape_setFillColor(rect, block[x][y]->color);
                sfRenderWindow_drawRectangleShape(window, rect, 0);
            }
        free(block-1);
        sfRenderWindow_display(window);
    }
    return (0);
}

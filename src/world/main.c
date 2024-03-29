/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** hello
*/

#include <stdlib.h>
#include "my.h"
#include "screen.h"
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdio.h>
#include "world.h"

int min_i(int a, int b)
{
    return (a > b ? b : a);
}

void draw_window(sfRenderWindow *win, framebuffer_t *fb)
{
    static sfSprite *sprite = 0; !sprite ? sprite = sfSprite_create() : 0;
    static sfTexture *texture = 0;
    !texture ? texture = sfTexture_create(SCREEN_X, SCREEN_Y) : 0;

    static char first = 0;
    for (; !first; first = 1){
        sfRenderWindow_setFramerateLimit(win, 60);
        sfSprite_setTexture(sprite, texture, sfTrue);
    }
    sfTexture_updateFromPixels(texture, fb->pixels, SCREEN_X, SCREEN_Y, 0, 0);
    sfRenderWindow_drawSprite(win, sprite, 0);
    //sfRenderWindow_display(win);
}

world_t *create_world(int x, int y)
{
    world_t *world = malloc(sizeof(world_t));
    world->x = x;
    world->y = y;
    init_map(world);
    init_cam(world);
    return (world);
}

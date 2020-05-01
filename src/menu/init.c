/*
** EPITECH PROJECT, 2020
** win
** File description:
** all win func
*/

#include <stdlib.h>
#include "rpg.h"

int init_mouse(win_t *win)
{
    win->mouse = malloc(sizeof(texture_t));
    win->click = malloc(sizeof(texture_t));
    win->logo = malloc(sizeof(texture_t));
    if (!win->mouse || !win->click || !win->logo)
        return (0);
    win->mouse->tex = sfTexture_createFromFile("assets/cursor.png", NULL);
    win->click->tex = sfTexture_createFromFile("assets/btn/clicked", NULL);
    win->logo->tex = sfTexture_createFromFile("assets/hud/logo.png", NULL);
    win->mouse->sprite = sfSprite_create();
    win->logo->sprite = sfSprite_create();
    win->click->sprite = sfSprite_create();
    if (!win->mouse->tex || !win->mouse->sprite || !win->click->tex ||
        !win->click->sprite || !win->logo->sprite || !win->logo->tex)
        return (0);
    sfSprite_setTexture(win->click->sprite, win->click->tex, sfTrue);
    sfSprite_setTexture(win->mouse->sprite, win->mouse->tex, sfTrue);
    sfSprite_setTexture(win->logo->sprite, win->logo->tex, sfTrue);
    return (1);
}

int init_my_win(win_t *my_win, char *name)
{
    config_t *config = malloc(sizeof(config_t));

    if (!config)
        return (1);
    my_win->x = 1920;
    my_win->y = 1080;
    my_win->config = config;
    my_win->config->sound = 62;
    my_win->config->difficulty = 1;
    my_win->config->fps = 60;
    my_win->mode.width = my_win->x;
    my_win->mode.height = my_win->y;
    my_win->mode.bitsPerPixel = 32;
    my_win->win = sfRenderWindow_create(my_win->mode, name, sfClose | sfResize, 0);
    if (!my_win->win || !init_mouse(my_win))
        return (1);
    my_win->menu = 0;
    return (0);
}

win_t *create_window(int *returned, char *name)
{
    win_t *my_win = malloc(sizeof(win_t));
    int res;
    if (!my_win) {
        *returned = 84;
        return (NULL);
    } else
        res = init_my_win(my_win, name);
    if (res) {
        *returned = 84;
        return (NULL);
    }
    return (my_win);
}

att_t *set_attrib(float x, float y, int width, int depth)
{
    att_t *attrib = malloc(sizeof(att_t));
    sfVector2f pos = {x, y};
    sfVector2f size = {(float) width, (float) depth};

    if (!attrib)
        return (0);
    attrib->size = size;
    attrib->pos = pos;
    return (attrib);
}

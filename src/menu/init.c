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
    win->mouse = init_texture("assets/cursor.png");
    win->click = init_texture("assets/btn/clicked");
    win->logo = init_texture("assets/hud/logo.png");
    win->particles = lld_init();
    if (!win->mouse || !win->click || !win->logo)
        return (0);
    return (1);
}

int init_my_win(win_t *win, char *name)
{
    config_t *config = malloc(sizeof(config_t));

    if (!config || !(win->txt = malloc(sizeof(text_t))))
        return (1);
    win->x = 1920;
    win->y = 1080;
    win->config = config;
    win->config->sound = 62;
    win->config->type = 0;
    win->config->difficulty = 1;
    win->config->fps = 60;
    win->mode.width = win->x;
    win->mode.height = win->y;
    win->mode.bitsPerPixel = 32;
    win->win = sfRenderWindow_create(win->mode, name, sfClose | sfResize, 0);
    if (!win->win || !init_mouse(win) || !(win->txt->font =
    sfFont_createFromFile("assets/mc.ttf")) ||
    !(win->txt->text = sfText_create()))
        return (1);
    win->menu = 0;
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

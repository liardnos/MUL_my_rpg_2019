/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** End free of RPG
*/

#include <stdlib.h>
#include "menu.h"

void end_free(win_t *win, button_t **buttons)
{
    button_t **cpy = buttons;

    sfRenderWindow_destroy(win->win);
    for (; *cpy; cpy++) {
        free((*cpy)->attrib);
        sfTexture_destroy((*cpy)->tex);
        sfTexture_destroy((*cpy)->tex_h);
        sfSprite_destroy((*cpy)->sprite);
        sfSprite_destroy((*cpy)->sprite_h);
        free((*cpy));
    }
    free(buttons);
}

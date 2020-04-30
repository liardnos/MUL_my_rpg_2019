/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** End free of RPG
*/

#include <stdlib.h>
#include "menu.h"
#include "rpg.h"

void free_game(win_t *win)
{
    game_t *cpy = win->game;

    if (cpy) {
        sfTexture_destroy(cpy->it->tex);
        sfSprite_destroy(cpy->it->sprite);
        sfTexture_destroy(cpy->bl->tex);
        sfSprite_destroy(cpy->bl->sprite);
        free(cpy->bl);
        free(cpy->it);
        lld_free(cpy->map);
        lld_free(cpy->players);
        lld_free(cpy->entities);
        lld_free(cpy->items);
        free(cpy);
        win->game = 0;
    }
}

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

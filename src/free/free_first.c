/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** End free of RPG
*/

#include <stdlib.h>
#include "menu.h"
#include "rpg.h"

void free_texture(texture_t *texture)
{
    if (texture) {
        sfTexture_destroy(texture->tex);
        sfSprite_destroy(texture->sprite);
        free(texture);
    }
}

void free_text(text_t *text)
{
    if (text) {
        sfText_destroy(text->text);
        sfFont_destroy(text->font);
        free(text);
    }
}

void free_game(win_t *win)
{
    game_t *cpy = win->game;

    particle_free(win);
    if (cpy) {
        free_texture(cpy->bl);
        free_texture(cpy->ef);
        free_texture(cpy->it);
        free_texture(cpy->bar);
        free_texture(cpy->inv);
        free_texture(cpy->hud);
        free_texture(cpy->choose);
        free_map(win->game->map);
        lld_free_r(cpy->players);
        lld_free_r(cpy->entities);
        lld_free_r(cpy->items);
        free(cpy);
        win->game = 0;
    }
}

void end_free(win_t *win, button_t **buttons)
{
    button_t **cpy = buttons;

    sfRenderWindow_destroy(win->win);
    free_text(win->txt);
    free_texture(win->mouse);
    free_texture(win->click);
    free_texture(win->logo);
    free(win->config);
    for (; *cpy; cpy++) {
        free((*cpy)->attrib);
        sfTexture_destroy((*cpy)->tex);
        sfTexture_destroy((*cpy)->tex_h);
        sfSprite_destroy((*cpy)->sprite);
        sfSprite_destroy((*cpy)->sprite_h);
        free((*cpy));
    }
    free(buttons);
    free(win);
}

void free_map(map_t *map)
{
    for (lld_t *mv = map->map->next; mv; mv = mv->next)
        free(mv->data-sizeof(block_t *));
    lld_free(map->map);
    free(map);
}

/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main funcs of btns
*/

#include "menu.h"
#include "rpg.h"

void btn_quit(win_t *win)
{
    sfRenderWindow_close(win->win);
}

// FIXME EDIT THIS

void btn_play(win_t *win)
{
    game_t *cpy;

    win->game = malloc(sizeof(game_t));
    win->game->bl = malloc(sizeof(texture_t));
    win->game->it = malloc(sizeof(texture_t));
    cpy = win->game;
    cpy->map = generate_map();
    cpy->players = 0;
    cpy->entities = lld_init();
    cpy->items = lld_init();
    cpy->bl->tex = sfTexture_createFromFile("assets/tilesx64.png", 0);
    cpy->it->tex = sfTexture_createFromFile("assets/itemsx64.png", 0);
    cpy->bl->sprite = sfSprite_create();
    cpy->it->sprite = sfSprite_create();
    sfSprite_setTexture(cpy->bl->sprite, cpy->bl->tex, sfTrue);
    sfSprite_setTexture(cpy->it->sprite, cpy->it->tex, sfTrue);
    win->menu = 3;
}

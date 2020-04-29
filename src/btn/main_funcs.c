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

void btn_play(win_t *win)
{
    win->game = malloc(sizeof(game_t));
    win->game->map = generate_map();
    win->game->players = 0;
    win->game->entities = lld_init();
    win->game->items = lld_init();
    win->menu = 3;
}

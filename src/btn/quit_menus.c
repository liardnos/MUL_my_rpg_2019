/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Btn quit menus
*/

#include "rpg.h"

void btn_return(win_t *win, int *returned)
{
    my_printf("[RM] Return to title\n");
    save_game(win->game);
    free_game(win);
    win->menu = 0;
}

void btn_quit_game(win_t *win, int *returned)
{
    my_printf("[RM] Exiting game\n");
    save_game(win->game);
    free_game(win);
    btn_quit(win);
}

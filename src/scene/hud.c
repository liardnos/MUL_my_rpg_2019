/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw hud
*/

#include "rpg.h"

void draw_hud_bar(win_t *win, int **inv)
{
    sfVector2f pos = {657, 950};

    sfSprite_setPosition(win->game->bar->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->bar->sprite, 0);
}

void draw_hud(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    int hp = ply->hp;

    draw_hud_bar(win, ply->inventory);
}

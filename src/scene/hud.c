/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw hud
*/

#include "rpg.h"

void draw_hud_bar(win_t *win, int *inv)
{
    sfVector2f pos = {657, 980};
    sfIntRect rect = {0, 0, 64, 64};

    sfSprite_setPosition(win->game->bar->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->bar->sprite, 0);
    pos.x += 2;
    pos.y += 2;
    for (int x = 0; x < 9; x++) {
        rect.left = (inv[x] / 100 % 100) * 64;
        draw_item(win, rect, pos, inv[x]);
        draw_quantity(win, pos, inv[x] % 100);
        pos.x += 71;
    }
}

void draw_hud_void(win_t *win)
{
    sfVector2f pos = {657, 940};
    sfIntRect rect = {0, 0, 64, 64};

    for (int x = 0; x < 5; x++) {
        sfSprite_setTextureRect(win->game->ef->sprite, rect);
        sfSprite_setPosition(win->game->ef->sprite, pos);
        sfRenderWindow_drawSprite(win->win, win->game->ef->sprite, 0);
        pos.x += 40;
    }
}

void draw_hud_hp(win_t *win, int hp)
{
    sfIntRect rect = {0, 0, 64, 64};
    sfVector2f pos = {657, 940};

    draw_hud_void(win);
    for (int x = 0; x < hp - 5; x++) {
        rect.left = 3 * 64;
        sfSprite_setTextureRect(win->game->ef->sprite, rect);
        sfSprite_setPosition(win->game->ef->sprite, pos);
        sfRenderWindow_drawSprite(win->win, win->game->ef->sprite, 0);
        pos.x += 40;
    }
    pos.x = 657;
    for (int x = 0; x < hp && x < 5; x++) {
        rect.left = 1 * 64;
        sfSprite_setTextureRect(win->game->ef->sprite, rect);
        sfSprite_setPosition(win->game->ef->sprite, pos);
        sfRenderWindow_drawSprite(win->win, win->game->ef->sprite, 0);
        pos.x += 40;
    }
}

void draw_hud(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    sfVector2f scale = {0.53125, 0.53125};

    sfSprite_setScale(win->game->ef->sprite, scale);
    draw_hud_hp(win, ply->hp);
    draw_hud_bar(win, ply->inventory[3]);
}

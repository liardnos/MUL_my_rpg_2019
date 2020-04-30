/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw inventory
*/

#include "rpg.h"


void draw_background_img(win_t *win)
{
    sfTexture *tex = sfTexture_createFromFile("assets/hud/inventory.png", 0);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {630, 400};

    sfSprite_setTexture(sprite, tex, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(win->win, sprite, 0);
    sfTexture_destroy(tex);
    sfSprite_destroy(sprite);
}

// FIXME
void draw_inv(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    sfVector2f pos = {650, 412};
    sfIntRect rect = {0, 0, 64, 64};

    draw_background_img(win);
    for (int y = 0; ply->inventory[y]; y++) {
        for (int x = 0; x < 9; x++) {
            rect.left = ply->inventory[y][x] / 100 % 100;
            pos.x = 650 + 64 * x;
            if (ply->inventory[y][x] != 0 && ply->inventory[y][x] / 10000 == 1) {
                sfSprite_setTextureRect(win->game->bl->sprite, rect);
                sfSprite_setPosition(win->game->bl->sprite, pos);
                sfRenderWindow_drawSprite(win->win, win->game->bl->sprite, 0);
            }
            if (ply->inventory[y][x] != 0 && ply->inventory[y][x] / 10000 == 2) {
                sfSprite_setTextureRect(win->game->it->sprite, rect);
                sfSprite_setPosition(win->game->it->sprite, pos);
                sfRenderWindow_drawSprite(win->win, win->game->it->sprite, 0);
            }
        }
        pos.y = 412 + 64 * y;
    }
}

/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw game scene
*/

#include "rpg.h"

void draw_game(win_t *win)
{
    sfIntRect rect = {0, 40, 32, 18};
    sfVector2f pos = {0, 0};
    block_t ***to_draw = generator_getmap(win->game->map, &rect);

    rect.width = 64;
    rect.height = 64;
    rect.top = 0;
    for (int x = 0; x < 32; x++) {
        for (int y = 0; y < 18; y++) {
            if (to_draw[x][y]->type != -1) {
                rect.left = to_draw[x][y]->type * 64;
                sfSprite_setTextureRect(win->game->bl->sprite, rect);
                sfSprite_setPosition(win->game->bl->sprite, pos);
                sfRenderWindow_drawSprite(win->win, win->game->bl->sprite, 0);
            }
            pos.y = (y + 1) * 64;
        }
        pos.x = (x + 1) * 64;
        pos.y = 0;
    }
}

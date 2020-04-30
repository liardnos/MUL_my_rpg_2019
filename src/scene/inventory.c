/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw inventory
*/

#include "rpg.h"

//FIXME
void draw_background_img(win_t *win)
{
    sfTexture *tex = sfTexture_createFromFile("assets/hud/inventory.png", 0);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {600, 200};

    sfSprite_setTexture(sprite, tex, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(win->win, sprite, 0);
    sfTexture_destroy(tex);
    sfSprite_destroy(sprite);
}

void draw_item(win_t *win, sfIntRect rect, sfVector2f pos, int thing)
{
    sfVector2f scale = {0.53125, 0.53125};
    sfVector2f norm = {1 , 1};

    if (thing != 0 && thing / 10000 == 1) {
        sfSprite_setTextureRect(win->game->bl->sprite, rect);
        sfSprite_setPosition(win->game->bl->sprite, pos);
        sfSprite_setScale(win->game->bl->sprite, scale);
        sfRenderWindow_drawSprite(win->win, win->game->bl->sprite, 0);
        sfSprite_setScale(win->game->bl->sprite, norm);
    }
    if (thing != 0 && thing / 10000 == 2) {
        sfSprite_setTextureRect(win->game->it->sprite, rect);
        sfSprite_setPosition(win->game->it->sprite, pos);
        sfSprite_setScale(win->game->it->sprite, scale);
        sfRenderWindow_drawSprite(win->win, win->game->it->sprite, 0);
        sfSprite_setScale(win->game->it->sprite, norm);
    }
}

void draw_inv(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    sfVector2f pos;
    sfIntRect rect = {0, 0, 64, 64};

    draw_background_img(win);
    animator_setpos(ply->anim, malloc_pos(795, 375, 0));
    animate_player(win);
    animator_setpos(ply->anim, malloc_pos(1920 / 2, 1080 / 2, 0));
    for (int y = 0; ply->inventory[y]; y++) {
        pos.y = (int) (557 + 64 * y + (y == 3 ? 33 : 0));
        for (int x = 0; x < 9; x++) {
            rect.left = (ply->inventory[y][x] / 100 % 100) * 64;
            pos.x = (int) (648 + 71 * x);
            draw_item(win, rect, pos, ply->inventory[y][x]);
        }
    }
}

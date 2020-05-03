/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw game scene
*/

#include "rpg.h"
#include <math.h>

void draw_game_items(win_t *win, player_t *p)
{
    sfIntRect rect = {0, 0, 64, 64};
    sfVector2f pos = {0, 0};
    lld_t *lld = win->game->items;
    static float angle = 0;

    angle += 0.05;
    for (lld_t *mv = lld->next; mv; mv = mv->next){
        item_t *item = mv->data;

        pos.x = (item->x - p->x) * 64 + 1920/2;
        pos.y = (item->y - p->y) * 64 + 1080/2 + cos(angle)*10;
        rect.left = 64 * item->item;
        draw_item(win, rect, pos, item->type*10000);
    }
}

void draw_arrow(sfVector2f pos, sfVector2f ori, float angle, win_t *win)
{
    sfVector2f scale = {0.5, 0.5};

    sfSprite_setPosition(win->game->it->sprite, pos);
    sfSprite_setOrigin(win->game->it->sprite, ori);
    sfSprite_setScale(win->game->it->sprite, scale);
    sfSprite_setRotation(win->game->it->sprite, angle/PI*180 + 135);
    sfRenderWindow_drawSprite(win->win, win->game->it->sprite, 0);
}

void draw_game_proj(win_t *win, player_t *p)
{
    sfVector2f pos = {0, 0};
    sfVector2f ori = {32, 32};
    sfVector2f orio = {0, 0};
    lld_t *lld = win->game->proj;
    float angle = 0;
    sfIntRect rect = {64*ARROW, 0, 64, 64};

    sfSprite_setTextureRect(win->game->it->sprite, rect);
    for (lld_t *mv = lld->next; mv; mv = mv->next){
        item_t *item = mv->data;
        float d = pow(pow(item->vx, 2)+pow(item->vy, 2), 0.5);
        if (d != 0) angle = acos((float)item->vy / (float)d);
        item->vx > 0 ? angle *= -1 : 0;
        pos.x = (item->x - p->x) * 64 + 1920/2;
        pos.y = (item->y - p->y) * 64 + 1080/2;
        draw_arrow(pos, ori, angle, win);
    }
    sfSprite_setOrigin(win->game->it->sprite, orio);
    sfSprite_setRotation(win->game->it->sprite, 0);
}

void draw_other(win_t *win, player_t *p, sfVector2f pos, block_t ***to_draw)
{
    pos.x = -(flr(p->x)-p->x)*64;
    pos.y = -(flr(p->y)-p->y-1)*64;
    win->menu == 3 ? breaking(win, to_draw, pos) : 0;
    win->menu == 3 ? fight(win, p) : 0;
    free(to_draw-1);
    draw_game_proj(win, p);
    draw_game_items(win, p);
    win->game && win->menu != 4 ? draw_entity(win) : 0;
    win->menu == 3 ? animate_player(win) : 0;
}

void draw_game(win_t *win)
{
    player_t *p = win->game->players->next->data;
    sfIntRect rect = {flr(p->x-15), flr(p->y-10), 31, 18};
    block_t ***to_draw = generator_getmap(win->game->map, &rect);
    sfVector2f pos = {(flr(p->x)-p->x)*64, (flr(p->y)-p->y-1)*64};
    pos.x == 0 ? pos.x  += 0.01 : 0;
    rect.width = 64;
    rect.height = 64;
    rect.top = 0;
    for (int x = 0; x < 31; x++) {
        for (int y = 0; y < 19; y++) {
            if (to_draw[x][y]->type != -1) {
                rect.left = to_draw[x][y]->type * 64;
                sfSprite_setTextureRect(win->game->bl->sprite, rect);
                sfSprite_setPosition(win->game->bl->sprite, pos);
                sfRenderWindow_drawSprite(win->win, win->game->bl->sprite, 0);
            }
            pos.y += 64;
        }
        pos.x += 64;
        pos.y = (flr(p->y)-p->y-1)*64;
    }
    draw_other(win, p, pos, to_draw);
}

/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw game scene
*/

#include "rpg.h"

#define JUMP_HIGHT 2.5
#define JUMP_SPEED pow(JUMP_HIGHT*2*GRAVITY, 0.5)

void draw_game(win_t *win)
{

    player_t *player = win->game->players->next->data;
    sfIntRect rect = {flr(player->x-15), flr(player->y-10), 31, 18};
    block_t ***to_draw = generator_getmap(win->game->map, &rect);
    sfVector2f pos = {(flr(player->x)-player->x)*64, (flr(player->y)-player->y-1)*64};
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
        pos.y = (flr(player->y)-player->y-1)*64;
    }
    static animation = 0;
    if (!animator_animate(player->anim)){
        animation ^= 1;
        animation ? animator_goto(player->anim, 30.0, 45.0, -45.0, 10.0, 0.0, 45.0, -45.0) : animator_goto(player->anim, 15.0, -45.0, 45.0, -10.0, 0.0, -45.0, 45.0);
    }

    if (sfKeyboard_isKeyPressed(sfKeyRight))
        player->vx = 6.0;
    else if (sfKeyboard_isKeyPressed(sfKeyLeft))
        player->vx = -6.0;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && player->floor)
        player->vy = -JUMP_SPEED, printf("up\n");
    printf("FRAME\n");
    animator_setpos(player->anim, malloc_pos(1920/2, 1080/2, 0));
    animator_draw(win->win, player->anim);
    sfCircleShape *cir = sfCircleShape_create();
    pos.x = 1920/2, pos.y = 1080/2;
    sfCircleShape_setPosition(cir, pos);
    pos.x = 10, pos.y = 10;
    sfCircleShape_setOrigin(cir, pos);
    sfCircleShape_setFillColor(cir, sfRed);
    sfCircleShape_setRadius(cir, 10);
    sfRenderWindow_drawCircleShape(win->win, cir, 0);
}

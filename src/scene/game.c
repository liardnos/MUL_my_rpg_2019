/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw game scene
*/

#include "rpg.h"
#include <math.h>

float find_angle(float *p1, float *p2)
{
    float x = p2[0] - p1[0];
    float y = p2[1] - p1[1];
    float d = pow(pow(x, 2)+pow(y, 2), 0.5);

    if (d == 0)
        return (0);
    float a = acos(x/d);
    y < 0 ? a *= -1 : 0;
    return (a);
}

float player_head(win_t *win, player_t *player)
{
    sfVector2i vec = sfMouse_getPosition((sfWindow *)win->win);
    member_t *member = player->anim->member->next->next->next->data;

    vec.x -= player->anim->pos->x, vec.y -= player->anim->pos->y;
    float d = pow(pow(vec.x, 2)+pow(vec.y, 2), 0.5);
    float head_angle = 0;
    if (d != 0)
        head_angle = acos((float)vec.y / (float)d);
    vec.x > 0 ? head_angle *= -1 : 0;
    sfVector2f vec1 = {-0.5, 0.5};
    sfVector2f vec2 = {0.5, 0.5};
    if (head_angle < 0)
        head_angle -= PI, sfSprite_setScale(member->sprite, vec1);
    else
        sfSprite_setScale(member->sprite, vec2);
    return (head_angle/PI*180-90);
}

void animate_player(win_t *win)
{
    player_t *player = win->game->players->next->data;
    static int animation = 0;
    float h_head = player_head(win, player);

    if (!animator_animate(player->anim)){
        if (player->floor && fabsf(player->vx) > 1)
            animation ^= 1, animation ? animator_goto(player->anim, 15.0,
            ANIM_WALK1) : animator_goto(player->anim, 15.0, ANIM_WALK2);
        else if (player->floor)
            animator_goto(player->anim, 5.0, ANIM_STAND);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD))
        player->vx = 6.0;
    else if (sfKeyboard_isKeyPressed(sfKeyQ))
        player->vx = -6.0;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->floor)
        player->vy = -JUMP_SPEED, animator_goto(player->anim, 15.0, ANIM_JUMP);
    animator_draw(win->win, player->anim);
}

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

void draw_game_proj(win_t *win, player_t *p)
{
    sfIntRect rect = {64*ARROW, 0, 64, 64};
    sfVector2f pos = {0, 0};
    sfVector2f scale = {0.5, 0.5};
    lld_t *lld = win->game->proj;
    float angle = 0;

    angle += 0.05;
    for (lld_t *mv = lld->next; mv; mv = mv->next){
        item_t *item = mv->data;

        float d = pow(pow(item->vx, 2)+pow(item->vy, 2), 0.5);
        if (d != 0)
            angle = acos((float)item->vy / (float)d);
        item->vx > 0 ? angle *= -1 : 0;

        pos.x = (item->x - p->x) * 64 + 1920/2;
        pos.y = (item->y - p->y) * 64 + 1080/2;
        sfSprite_setPosition(win->game->it->sprite, pos);
        sfSprite_setScale(win->game->it->sprite, scale);
        sfSprite_setRotation(win->game->it->sprite, angle/PI*180 + 135);
        sfSprite_setTextureRect(win->game->bl->sprite, rect);
        sfRenderWindow_drawSprite(win->win, win->game->it->sprite, 0);
    }
    sfSprite_setRotation(win->game->it->sprite, 0);
}

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
    pos.x = -(flr(player->x)-player->x)*64;
    pos.y = -(flr(player->y)-player->y-1)*64;
    win->menu == 3 ? breaking(win, to_draw, pos) : 0;
    win->menu == 3 ? fight(win, player) : 0;
    free(to_draw-1);
    draw_game_proj(win, player);
    draw_game_items(win, player);
    win->game && win->menu != 4 ? draw_entity(win) : 0;
    win->menu == 3 ? animate_player(win) : 0;
}

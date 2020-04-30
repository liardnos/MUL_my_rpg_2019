/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw game scene
*/

#include "rpg.h"
#include <math.h>

#define JUMP_HIGHT 2.5
#define JUMP_SPEED pow(JUMP_HIGHT*2*GRAVITY, 0.5)

#define ANIM_JUMP 110.0, -45.0, h_head, 0.0, 45.0, -110.0
#define ANIM_WALK1 45.0, -45.0, h_head, 0.0, 45.0, -45.0
#define ANIM_WALK2 -45.0, 45.0, h_head, 0.0, -45.0, 45.0
#define ANIM_STAND 0.0, 0.0, h_head, 0.0, 0.0, 0.0

const block_t blockss[8][1];

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

    vec.x -= 1920/2, vec.y -= 1080/2;
    float d = pow(pow(vec.x, 2)+pow(vec.y, 2), 0.5);
    float head_angle = 0;
    printf("head %u %u\n", vec.x, vec.y);
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
    printf("head %f\n", h_head);

    if (!animator_animate(player->anim)){
        if (player->floor && fabsf(player->vx) > 1)
            animation ^= 1, animation ? animator_goto(player->anim, 15.0,
            ANIM_WALK1) : animator_goto(player->anim, 15.0, ANIM_WALK2);
        else if (player->floor)
            animator_goto(player->anim, 5.0, ANIM_STAND);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        player->vx = 6.0;
    else if (sfKeyboard_isKeyPressed(sfKeyLeft))
        player->vx = -6.0;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && player->floor)
        player->vy = -JUMP_SPEED, animator_goto(player->anim, 15.0, ANIM_JUMP);
    animator_setpos(player->anim, malloc_pos(1920/2, 1080/2, 0));
    animator_draw(win->win, player->anim);
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
    to_draw[10][8] = blockss[1];
    free(to_draw-1);
    animate_player(win);
}

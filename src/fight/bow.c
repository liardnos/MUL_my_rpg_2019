/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fighting mecanics
*/

#include <stdlib.h>
#include <math.h>
#include "rpg.h"

void fight_bow(win_t *win, player_t *p)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)win->win);
    static int s = 0;
    arrow_t *arrow;
    float h_head = 0;

    pos.x -= 1920/2, pos.y -= 1080/2;
    if (sfMouse_isButtonPressed(sfMouseRight) && s == 0){
        if (!take_inv(p->inventory, 2, ARROW, 1))
            return;
        arrow = malloc(sizeof(arrow_t));
        if (!arrow) return;
        arrow->x = p->x;
        arrow->y = p->y-0.10;
        arrow->vx = pos.x/30 + ((rand()%100)/100.0-0.5)*2;
        arrow->vy = pos.y/30 + ((rand()%100)/100.0-0.5)*2;
        arrow->type = 0;
        lld_insert(win->game->proj, 0, arrow);
        animator_goto(p->anim, 5.0, ANIM_WALK1);
        s = 1;
    } else if (sfMouse_isButtonPressed(sfMouseRight))
        s = s;
    else
        s = 0;
}

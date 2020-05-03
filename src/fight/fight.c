/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fighting mecanics
*/

#include <stdlib.h>
#include "rpg.h"

void fight_sword_wood(win_t *win, player_t *p)
{
}

void fight_sword_stone(win_t *win, player_t *p)
{
}

void fight_sword_iron(win_t *win, player_t *p)
{
}

void fight_sword_diamond(win_t *win, player_t *p)
{
}

void fight_bow(win_t *win, player_t *p)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)win->win);
    static int s = 0;
    arrow_t *arrow;

    pos.x -= 1920/2, pos.y -= 1080/2;
    if (sfMouse_isButtonPressed(sfMouseRight) && s == 0){
        if (!take_inv(p->inventory, 2, ARROW, 1))
            return;
        arrow = malloc(sizeof(arrow_t));
        if (!arrow) return (0);
        arrow->x = p->x;
        arrow->y = p->y-0.10;
        arrow->vx = pos.x/30;
        arrow->vy = pos.y/30;
        lld_insert(win->game->proj, 0, arrow);
        s = 1;
    } else if (sfMouse_isButtonPressed(sfMouseRight))
        s = s;
    else
        s = 0;
}

void fight(win_t *win, player_t *p)
{
    int select = p->inventory[3][p->select] / 100 % 100;
    int type = p->inventory[3][p->select] / 10000 % 10;

    if (type != 2)
        return;
    select == BOW ? fight_bow(win, p) :
    select == SWORD_WOOD ? fight_sword_wood(win, p) :
    select == SWORD_STONE ? fight_sword_stone(win, p) :
    select == SWORD_IRON ? fight_sword_iron(win, p) :
    select == SWORD_DIAMOND ? fight_sword_diamond(win, p) : 0;
}

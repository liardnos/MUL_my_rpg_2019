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
}

void fight(win_t *win, player_t *p)
{
    int select = p->inventory[3][p->select] / 100 % 100;
    select == BOW ? fight_bow(win, p) :
    select == SWORD_WOOD ? fight_sword_wood(win, p) :
    select == SWORD_STONE ? fight_sword_stone(win, p) :
    select == SWORD_IRON ? fight_sword_iron(win, p) :
    select == SWORD_DIAMOND ? fight_sword_diamond(win, p) : 0;
}

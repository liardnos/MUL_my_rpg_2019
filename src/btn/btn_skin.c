/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Btn funcs for change skin
*/

#include "rpg.h"

void btn_skinr(win_t *win, int *returned)
{
    if (!win->config->type)
        win->config->type++;
    else
        win->config->type = 0;
}

void btn_skinl(win_t *win, int *returned)
{
    if (win->config->type)
        win->config->type--;
    else
        win->config->type = 1;
}

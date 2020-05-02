/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Other funcs for utils
*/

#include "rpg.h"

void add_max(int *item, int *to_add)
{
    int tmp;

    if ((*to_add) % 100 <= 64 - ((*item) % 100)) {
        *item += (*to_add) % 100;
        *to_add = 0;
    } else {
        tmp = 64 - ((*item) % 100);
        *item += tmp;
        *to_add -= tmp;
    }
}

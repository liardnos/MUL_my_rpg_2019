/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** hello
*/

#include "../my.h"
#include <unistd.h>
#include <stdlib.h>

void lld_free_r(lld_t *lld)
{
    lld_t *mov = lld->next;

    while (lld->data)
        free(lld_pop(lld, 0));
    free(lld);
}

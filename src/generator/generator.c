/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** generator for my_rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"
#include "gen.h"

block_t **generate_getcolum(map_t *m, int x)
{
    static int here_p = 0;
    static lld_t *here = 0;

    m->new ? m->new = 0, here = m->map->next, here_p = -m->size_l : 0;
    while (x != here_p){
        if (x > here_p){
            here_p++;
            here->next == 0 ? lld_insert(m->map, (u64)m->map->data,
            generate_line(here_p, 6)), m->size_r++ : 0;
            here = here->next;
        } else {
            here_p--;
            here->prev == 0 ? lld_insert(m->map, 0, generate_line(here_p, 6)),
            m->size_l++ : 0;
            here = here->prev;
        }
    }
    return (here->data);
}

block_t ***generator_getmap(map_t *map, sfIntRect *rect)
{
    block_t ***block = malloc(sizeof(block_t **) * (rect->width+2));

    if (!block)
        return (0);
    block++;
    block[-1] = 0;
    block[rect->width] = 0;
    for (int i = 0; i < rect->width; i++){
        block[i] = generate_getcolum(map, rect->left+i)+rect->top;
    }
    return (block);
}

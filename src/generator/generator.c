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

//FIXME
//id color solide pos
const block_t blockss[15][1] = {
    {-1, {0x6A, 0x0D, 0xAD, 255}, 0, 0},
    {STONE, {136, 140, 141, 255}, 1, 1},   //stone
    {DIRT, {101, 53, 20, 255}, 1, 2},     //dirt
    {ICE, {135, 206, 235, 255}, 0, 3},    //air
    {ORE_COAL, {50, 50, 50, 255}, 1, 4}, //coal
    {ORE_IRON, {132, 125, 115, 255}, 1, 5}, //iron
    {ORE_DIAMOND, {185, 242, 255, 255}, 1, 6}, //diamond
    {GRASS, {185, 242, 255, 255}, 1, 7}, //diamond
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
};

block_t *calc_block(float height)
{
    height += 50;
    block_t *a = 0;
    height > 0 ? a = blockss[3] : 0;
    height <= 0 && height >= -20  ? a = blockss[2] : 0;
    height < -20 ? a = blockss[1] : 0;
    srand(height*100);
    (u64)a->type == 1 && !((u64)height % 50 / 4) ? a = blockss[4] : 0;
    ((u64)a->type == 1 && (rand() % 50) == 0) ? a = blockss[5] : 0;
    ((u64)a->type == 1 && (rand() % 100) == 0) ? a = blockss[6] : 0;
    return (a);
}

void generate_line_post(block_t **blocks)
{
    for (int i = 1; blocks[i+1]; i++)
        if (blocks[i]->type == DIRT && blocks[i-1]->type == ICE)
            blocks[i] = blockss[7];
}

block_t **generate_line(int x, int d)
{
    block_t **line = malloc(sizeof(block_t *) * (MAP_Y + 2));
    float line_f[MAP_Y];
    int y = 0;

    line++;
    x < 0 ? x = 1.1*pow(2, d)-x : 0;
    line[MAP_Y] = 0;
    line[-1] = 0;
    for (; y < MAP_Y; y++){
        line_f[y] = (80 - y*2);
        for (int d_nb = 0; d_nb < d; d_nb++)
            line_f[y] += perlin((float)x/(1.1*pow(2, d_nb)), (float)y/(1.1*pow(2, d_nb)))*pow(2, d_nb);
    }
    line[y] = 0;
    for (y = 0; y < MAP_Y; y++)
        line[y] = calc_block(line_f[y]);
    generate_line_post(line);
    return (line);
}

map_t *generate_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return (0);
    map->map = lld_init();
    map->size_l = 0;
    map->size_r = 0;
    lld_insert(map->map, 0, generate_line(0, 6));
    return (map);
}

block_t **generate_getcolum(map_t *m, int x)
{
    static int here_p = 0;
    static lld_t *here = 0; !here ? here = m->map->next, here_p = -m->size_l : 0;

    while (x != here_p){
        if (x > here_p){
            here_p++;
            here->next == 0 ? lld_insert(m->map, (u64)m->map->data, generate_line(here_p, 6)), m->size_r++ : 0;
            here = here->next;
        } else {
            here_p--;
            here->prev == 0 ? lld_insert(m->map, 0, generate_line(here_p, 6)), m->size_l++ : 0;
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

/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** map for my_rpg
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "rpg.h"
#include "my.h"

block_t *calc_block(float h)
{
    block_t *a = 0;

    h += 50;
    h > 0 ? a = blockss[ICE] : 0;
    h <= 0 && h >= -20  ? a = blockss[DIRT] : 0;
    h < -20 ? a = blockss[STONE] : 0;
    srand((u64)h * 100);
    (u64)a->type == STONE && !(((u64)h % 50) / 4) ? a = blockss[ORE_COAL] : 0;
    ((u64)a->type == STONE && !(rand() % 50)) ? a = blockss[ORE_IRON] : 0;
    ((u64)a->type == STONE && !(rand() % 100)) ? a = blockss[ORE_DIAMOND] : 0;
    return (a);
}

void generate_line_post(block_t **blocks)
{
    for (int i = 1; blocks[i+1]; i++)
        if (blocks[i]->type == DIRT && blocks[i-1]->type == ICE)
            blocks[i] = blockss[GRASS];
    blocks[8] = blockss[COBBLE];
    blocks[246] = blockss[COBBLE];
}

block_t **generate_line(int x, int d)
{
    block_t **line = malloc(sizeof(block_t *) * (MAP_Y + 2));
    float line_f[MAP_Y];
    int y = 0;

    line++;
    x < 0 ? x = 1.1 * pow(2, d) - x : 0;
    line[MAP_Y] = 0;
    line[-1] = 0;
    for (; y < MAP_Y; y++){
        line_f[y] = (80 - y * 2);
        for (int d_nb = 0; d_nb < d; d_nb++)
            line_f[y] += perlin((float)x / (1.1 * pow(2, d_nb)),
            (float)y / (1.1 * pow(2, d_nb))) * pow(2, d_nb);
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
    map->new = 1;
    lld_insert(map->map, 0, generate_line(0, 6));
    return (map);
}

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
//id color solide
const block_t blockss[8][1] = {
    {-1, {0x6A, 0x0D, 0xAD, 255}, 0},
    {STONE, {136, 140, 141, 255}, 1},   //stone
    {DIRT, {101, 53, 20, 255}, 1},     //dirt
    {-1, {135, 206, 235, 255}, 0},    //air
    {ORE_COAL, {50, 50, 50, 255}, 1}, //coal
    {ORE_IRON, {132, 125, 115, 255}, 1}, //iron
    {ORE_DIAMOND, {185, 242, 255, 255}, 1}, //diamond
    {0}
};

float lerp(float a, float b, float w) {
    return (1.0 - w)*a + w*b;
}

float ***grid_grad(int x, int y)
{
    float ***grad = malloc(sizeof(float *) * (x+1));

    srand(0);
    for (int i = 0; i < x; i++){
        grad[i] = malloc(sizeof(float *) * (y+1));
        int ii = 0;
        for (; ii < y; ii++){
            grad[i][ii] = malloc(sizeof(float) * 2);
            grad[i][ii][0] = ((rand()%5000)/2500.0-1);
            grad[i][ii][1] = ((rand()%5000)/2500.0-1);
        }
        grad[i][ii] = 0;
    }
    grad[y] = 0;
    return (grad);
}

float dotGridGradient(int ix, int iy, float x, float y)
{
    static float ***grad = 0;

    if (!grad)
        grad = grid_grad(128, 128);
    float dx = x - (float)ix;
    float dy = y - (float)iy;

    return (dx*grad[iy%128][ix%128][0] + dy*grad[iy%128][ix%128][1]);
}

float perlin(float x, float y)
{
    int x0 = (int)x;
    int x1 = x0 + 1;
    int y0 = (int)y;
    int y1 = y0 + 1;
    float sx = x - (float)x0;
    float sy = y - (float)y0;
    float n0, n1, ix0, ix1, value;
    n0 = dotGridGradient(x0, y0, x, y);
    n1 = dotGridGradient(x1, y0, x, y);
    ix0 = lerp(n0, n1, sx);
    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    ix1 = lerp(n0, n1, sx);
    value = lerp(ix0, ix1, sy);
    return value;
}

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

block_t **generate_line(int x, int d)
{
    block_t **line = malloc(sizeof(block_t *) * (MAP_Y + 2));
    line++;
    float line_f[MAP_Y];
    int y = 0;

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
    return (line);
}

map_t *generate_map()
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

block_t **generate_getcolum(map_t *map, int x)
{
    static int here_p = 0;
    static lld_t *here = 0; !here ? here = map->map->next : 0;

    while (x != here_p){
        if (x > here_p){
            here_p++;
            here->next == 0 ? lld_insert(map->map, (u64)map->map->data, generate_line(here_p, 6)) : 0;
            here = here->next;
        } else {
            here_p--;
            here->prev == 0 ? lld_insert(map->map, 0, generate_line(here_p, 6)) : 0;
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

//save and load

map_t *load_map()
{
    int fd = open("save/map", O_RDONLY);

}

player_t *load_player()
{
    int fd = open("save/player", O_RDONLY);

}

game_t *load_game()
{
    return (0);
}

int save_map(map_t *map)
{
    int fd = open("save/map", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);
    write(fd, &map->size_l, 4);
    write(fd, &map->size_r, 4);
    close(fd);
}

int save_player(map_t *map)
{
    int fd = open("save/player", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);

    close(fd);
}

int save_game(game_t *game)
{
    save_map(game->map);
    save_player(game->players->next->data);
    return (0);
}

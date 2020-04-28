/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** generator for my_rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../rpg.h"

const block_t blocks[8][1] = {
    {0, {0x6A, 0x0D, 0xAD, 255}, 0},
    {1, {136, 140, 141, 255}, 1},   //stone
    {2, {101, 53, 20, 255}, 1},     //dirt
    {3, {135, 206, 235, 255}, 0},    //air
    {4, {50, 50, 50, 255}, 1}, //coal
    {5, {132, 125, 115, 255}, 1}, //iron
    {6, {185, 242, 255, 255}, 1}, //diamond
    {0}
};

float lerp(float a, float b, float w) {
    return (1.0 - w)*a + w*b;
}

float ***grid_grad(int x, int y)
{
    float ***grad = malloc(sizeof(float *) * (x+1));
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

/*float **create_mesh(int x1, int y1, int x2, int y2, int d)
{
    float **mesh = malloc(sizeof(float *) * (x+1));
    int i = 0;
    for (; i < x; i++){
        mesh[i] = malloc(sizeof(float) * (y+1));
        int ii = 0;
        for (; ii < y; ii++){
            mesh[i][ii] = x / 2 - ii*2;
            for (int d_nb = 0; d_nb < d; d_nb++)
                mesh[i][ii] += perlin((float)i/(1.1*pow(2, d_nb)), (float)ii/(1.1*pow(2, d_nb)))*pow(2, d_nb);
            mesh[i][ii] -= 0;
        }
        mesh[i][ii] = 0;
    }
    mesh[i] = 0;
    return (mesh);
}*/

block_t *calc_block(float height)
{
    height += 50;
    block_t *a = 0;
    height > 0 ? a = blocks[3] : 0;
    height <= 0 && height >= -20  ? a = blocks[2] : 0;
    height < -20 ? a = blocks[1] : 0;
    srand(height*100);
    (u64)a->type == 1 && !((u64)height % 50 / 4) ? a = blocks[4] : 0;
    ((u64)a->type == 1 && (rand() % 100) == 0) ? a = blocks[5] : 0;
    ((u64)a->type == 1 && (rand() % 200) == 0) ? a = blocks[6] : 0;
    return (a);
}

block_t **generate_line(int x, int d)
{
    block_t **line = malloc(sizeof(block_t *) * (MAP_Y + 1));
    line[MAP_Y] = 0;
    float line_f[MAP_Y];
    int y = 0;
    for (; y < MAP_Y; y++){
        line_f[y] = (20 - y*2);
        for (int d_nb = 0; d_nb < d; d_nb++)
            line_f[y] += perlin((float)x/(1.1*pow(2, d_nb)), (float)y/(1.1*pow(2, d_nb)))*pow(2, d_nb);
    }
    line[y] = 0;
    for (y = 0; y < MAP_Y; y++)
        line[y] = calc_block(line_f[y]);
    return (line);
}
